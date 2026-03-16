#include "selectcourse.h"
#include "ui_selectcourse.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QHeaderView>
#include <QAbstractItemView>
#include <QItemSelectionModel>
#include <QSet>

selectcourse::selectcourse(QString studentId, QString studentName, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::selectcourse)
    , m_studentId(studentId)
    , m_studentName(studentName)
{
    ui->setupUi(this);
    this->setWindowTitle("选课中心");

    QSqlDatabase db = QSqlDatabase::database();
    m_model = new QSqlQueryModel(this);
    ui->tableView->setModel(m_model);


    m_model->setQuery("SELECT course_id, course_name, credit, hours, course_type FROM courses", db);

    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    QSqlQuery query(db);
    query.prepare("SELECT course_name FROM scores WHERE student_id = ?");
    query.addBindValue(m_studentId);
    if (query.exec()) {
        while (query.next()) {
            m_alreadySelected.insert(query.value("course_name").toString());
        }
    }

    QItemSelectionModel *selModel = ui->tableView->selectionModel();
    int courseNameCol = m_model->record().indexOf("course_name");

    for (int i = 0; i < m_model->rowCount(); ++i) {
        QString courseName = m_model->index(i, courseNameCol).data().toString();
        if (m_alreadySelected.contains(courseName)) {
            selModel->select(m_model->index(i, 0), QItemSelectionModel::Select | QItemSelectionModel::Rows);
        }
    }
}

selectcourse::~selectcourse()
{
    delete ui;
}

void selectcourse::on_confirm_clicked()
{
    QModelIndexList selectedRows = ui->tableView->selectionModel()->selectedRows();
    QSqlDatabase db = QSqlDatabase::database();
    int courseNameCol = m_model->record().indexOf("course_name");

    QSet<QString> currentSelected;
    for (const QModelIndex &index : selectedRows) {
        QString courseName = m_model->index(index.row(), courseNameCol).data().toString();
        currentSelected.insert(courseName);
    }

    db.transaction();
    int deleteCount = 0; // 退课数量
    int insertCount = 0; // 新增选课数量

    QSqlQuery query(db);

    for (const QString &courseName : m_alreadySelected) {
        if (!currentSelected.contains(courseName)) {
            query.prepare("DELETE FROM scores WHERE student_id = ? AND course_name = ?");
            query.addBindValue(m_studentId);
            query.addBindValue(courseName);
            if (query.exec()) deleteCount++;
        }
    }

    for (const QString &courseName : currentSelected) {
        if (!m_alreadySelected.contains(courseName)) {
            query.prepare("INSERT INTO scores (student_id, student_name, course_name, score) VALUES (?, ?, ?, 0)");
            query.addBindValue(m_studentId);
            query.addBindValue(m_studentName);
            query.addBindValue(courseName);
            if (query.exec()) insertCount++;
        }
    }

    if (db.commit()) {
        QString msg;
        if (insertCount > 0 && deleteCount > 0) {
            msg = QString("操作成功！新增 %1 门课，退选 %2 门课。").arg(insertCount).arg(deleteCount);
        } else if (insertCount > 0) {
            msg = QString("选课成功！新增 %1 门课。").arg(insertCount);
        } else if (deleteCount > 0) {
            msg = QString("退课成功！退选 %2 门课。").arg(deleteCount);
        } else {
            msg = "没有进行任何修改。";
        }
        QMessageBox::information(this, "成功", msg);
        accept();
    } else {
        db.rollback();
        QMessageBox::critical(this, "错误", "保存失败");
    }
}

void selectcourse::on_cancel_clicked()
{
    this->reject();
}
