#include "student.h"
#include "ui_student.h"
#include <QFile>
#include <QStyledItemDelegate>
#include <QPainter>

class CenteredDelegate : public QStyledItemDelegate {
public:
    using QStyledItemDelegate::QStyledItemDelegate;
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override {
        QStyleOptionViewItem opt = option;
        opt.displayAlignment = Qt::AlignCenter;
        QStyledItemDelegate::paint(painter, opt, index);
    }
};

student::student(QString id, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::student)
    , m_studentId(id)
{
    ui->setupUi(this);
    this->setWindowTitle("学生界面");

    QFile file(":/styles/student.qss");
    if (file.open(QFile::ReadOnly | QFile::Text)) {
        this->setStyleSheet(QString::fromUtf8(file.readAll()));
        file.close();
    }

    QSqlDatabase db = QSqlDatabase::database();
    m_model = new QSqlTableModel(this, db);
    ui->tableView->setModel(m_model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->horizontalHeader()->setDefaultSectionSize(120);
    ui->tableView->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->tableView->verticalHeader()->setDefaultSectionSize(40);
    ui->tableView->setWordWrap(false);
    ui->tableView->setTextElideMode(Qt::ElideRight);
    ui->tableView->setItemDelegate(new CenteredDelegate(this));
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setMouseTracking(true);
    connect(ui->tableView, &QTableView::entered, this, &student::showCellTooltip);
}

student::~student()
{
    delete ui;
}

void student::on_select_clicked()
{
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query(db);
    query.prepare("SELECT name FROM students WHERE student_id = ?");
    query.addBindValue(m_studentId);
    query.exec();
    query.next();

    QString studentName = query.value("name").toString();
    selectcourse dlg(m_studentId, studentName, this);
    dlg.exec();

    m_model->select();
}


void student::on_watch_clicked()
{
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query(db);
    query.prepare("SELECT name FROM students WHERE student_id = ?");
    query.addBindValue(m_studentId); // 用登录时传的学号过滤
    query.exec();
    query.next();
    QString studentName = query.value("name").toString();
    m_model->setTable("scores");
    m_model->setFilter(QString("student_name = '%1'").arg(studentName)); // 按姓名过滤
    m_model->select();
}


void student::on_count_clicked()
{
    if (m_model->tableName() != "scores") {
        QMessageBox::information(this, "提示", "请先点击「查看成绩」后再统计总学分！");
        return;
    }

    int rowCount = m_model->rowCount();
    double totalCredit = 0.0;
    QSqlDatabase db = QSqlDatabase::database();
    int courseNameCol = m_model->fieldIndex("course_name");
    int scoreCol = m_model->fieldIndex("score");
    for (int i = 0; i < rowCount; ++i) {
        QString courseName = m_model->index(i, courseNameCol).data().toString();
        double score = m_model->index(i, scoreCol).data().toDouble();
        //只有成绩 >= 60 分才给学分
        if (score < 60) {
            continue;
        }

        QSqlQuery query(db);
        query.prepare("SELECT credit FROM courses WHERE course_name = ?");
        query.addBindValue(courseName);

        if (query.exec() && query.next()) {
            double credit = query.value("credit").toDouble();
            totalCredit += credit;
        }
    }

    QString result = QString(
                         "总学分统计\n"
                         "——————————————\n"
                         "您已获得的总学分：%1 分\n"
                         "——————————————"
                         ).arg(totalCredit, 0, 'f', 1); // 保留1位小数

    QMessageBox::information(this, "总学分统计", result);
}


void student::on_refresh_clicked()
{
    m_model->select();
    QMessageBox::information(this, "提示", "数据刷新成功！");
}

void student::showCellTooltip(const QModelIndex &index)
{
    if (!index.isValid()) return;
    QString text = m_model->data(index).toString();
    ui->tableView->setToolTip(text);
}
