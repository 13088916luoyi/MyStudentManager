#include "admin.h"
#include "ui_admin.h"
#include <QStyledItemDelegate>
#include <QPainter>
#include <QFile>

class CenteredDelegate : public QStyledItemDelegate {
public:
    using QStyledItemDelegate::QStyledItemDelegate;
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override {
        QStyleOptionViewItem opt = option;
        opt.displayAlignment = Qt::AlignCenter;
        QStyledItemDelegate::paint(painter, opt, index);
    }
};

admin::admin(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::admin)
{
    ui->setupUi(this);
    this->setWindowTitle("管理员界面");

    QFile file(":/styles/admin.qss");
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
    ui->tableView->verticalHeader()->setDefaultSectionSize(40);
    ui->tableView->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->tableView->verticalHeader()->setDefaultSectionSize(40);
    ui->tableView->setWordWrap(false);
    ui->tableView->setTextElideMode(Qt::ElideRight);
    ui->tableView->setItemDelegate(new CenteredDelegate(this));
    ui->tableView->setMouseTracking(true);
    connect(ui->tableView, &QTableView::entered, this, &admin::showCellTooltip);
}

admin::~admin()
{
    delete ui;
}

void admin::on_student_clicked()
{
    m_model->setTable("students");
    m_model->select();
    m_currentTable = Table_Student;
}

void admin::on_teacher_clicked()
{
    m_model->setTable("staff");
    m_model->select();
    m_currentTable = Table_Teacher;
}

void admin::on_course_clicked()
{
    m_model->setTable("courses");
    m_model->select();
    m_currentTable = Table_Course;
}

void admin::on_score_clicked()
{
    m_model->setTable("scores");
    m_model->select();
    m_currentTable = Table_Score;
}

void admin::on_account_clicked()
{
    m_model->setTable("accounts");
    m_model->select();
    m_currentTable = Table_Account;
}


void admin::on_create_clicked()
{
    if(m_currentTable == Table_None){
        QMessageBox::warning(this, "提示", "请先在左侧选择要操作的表！");
        return;
    }

    QStringList newData;
    if(m_currentTable == Table_Student){
        studenteditdialog dlg(true, this);
        if(dlg.exec() == QDialog::Accepted){
            newData = dlg.getData();
        }
    }

    else if(m_currentTable == Table_Teacher){
        teachereditdialog dlg(true, this);
        if(dlg.exec() == QDialog::Accepted){
            newData = dlg.getData();
        }
    }

    else if(m_currentTable == Table_Course){
        courseeditdialog dlg(true, this);
        if(dlg.exec() == QDialog::Accepted){
            newData = dlg.getData();
        }
    }

    else if(m_currentTable == Table_Score){
        scoreeditdialog dlg(true, this);
        if(dlg.exec() == QDialog::Accepted){
            newData = dlg.getData();
        }
    }

    else if(m_currentTable == Table_Account){
        accounteditdialog dlg(true, this);
        if(dlg.exec() == QDialog::Accepted){
            newData = dlg.getData();
        }
    }

    if(newData.isEmpty()) return;

    int newRow = m_model->rowCount();
    m_model->insertRow(newRow);
    for(int i = 0; i < newData.size(); i++){
        m_model->setData(m_model->index(newRow, i), newData[i]); // 按索引顺序填列
    }

    if(m_model->submitAll()){
        QMessageBox::information(this, "成功", "新建数据成功！");
    }else{
        QMessageBox::critical(this, "失败", "新建失败：" + m_model->lastError().text());
        m_model->revertAll();
    }
}

void admin::on_modify_clicked()
{
    int curRow = ui->tableView->currentIndex().row();
    if(curRow < 0){
        QMessageBox::warning(this, "提示", "请先选中一行！");
        return;
    }
    if(m_currentTable == Table_None) return;

    QStringList oldData;
    for(int i=0; i<m_model->columnCount(); i++){
        oldData << m_model->data(m_model->index(curRow, i)).toString();
    }

    QStringList newData;

    if(m_currentTable == Table_Student){
        studenteditdialog dlg(false, this);
        dlg.setData(oldData);
        if(dlg.exec() == QDialog::Accepted) newData = dlg.getData();
    }

    else if(m_currentTable == Table_Teacher){
        teachereditdialog dlg(false, this);
        dlg.setData(oldData);
        if(dlg.exec() == QDialog::Accepted) newData = dlg.getData();
    }

    else if(m_currentTable == Table_Course){
        courseeditdialog dlg(false, this);
        dlg.setData(oldData);
        if(dlg.exec() == QDialog::Accepted) newData = dlg.getData();
    }

    else if(m_currentTable == Table_Score){
        scoreeditdialog dlg(false, this);
        dlg.setData(oldData);
        if(dlg.exec() == QDialog::Accepted) newData = dlg.getData();
    }

    else if(m_currentTable == Table_Account){
        accounteditdialog dlg(false, this);
        dlg.setData(oldData);
        if(dlg.exec() == QDialog::Accepted) newData = dlg.getData();
    }

    if(newData.isEmpty()) return;

    for(int i=0; i<newData.size(); i++){
        m_model->setData(m_model->index(curRow, i), newData[i]);
    }

    if(m_model->submitAll()){
        QMessageBox::information(this, "成功", "修改成功！");
    }else{
        QMessageBox::critical(this, "失败", "错误：" + m_model->lastError().text());
        m_model->revertAll();
    }
}


void admin::on_refresh_clicked()
{
    m_model->select();
    QMessageBox::information(this, "提示", "数据刷新成功！");
}


void admin::on_delete_2_clicked()
{
    int curRow = ui->tableView->currentIndex().row();
    if(curRow < 0){
        QMessageBox::warning(this, "提示", "请先选中一行！");
        return;
    }
    m_model->removeRow(curRow);
    m_model->select();
    QMessageBox::information(this, "提示", "数据删除成功！");
}

void admin::showCellTooltip(const QModelIndex &index)
{
    if (!index.isValid()) return;
    QString text = m_model->data(index).toString();
    ui->tableView->setToolTip(text);
}
