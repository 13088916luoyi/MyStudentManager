#include "studenteditdialog.h"
#include "ui_studenteditdialog.h"

studenteditdialog::studenteditdialog(bool isNew, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::studenteditdialog),
    m_isNew(isNew)
{
    ui->setupUi(this);
    this->setWindowTitle(m_isNew ? "新建学生" : "修改学生");

    // 如果是修改模式，把第一个输入框（假设是学号）设为只读
    if(!m_isNew){
        ui->sno->setReadOnly(true);
        ui->sno->setStyleSheet("background-color: #E0E0E0;");
    }
}

studenteditdialog::~studenteditdialog()
{
    delete ui;
}

void studenteditdialog::on_confirm_clicked()
{
    if(ui->sno->text().isEmpty() || ui->name->text().isEmpty()){
        QMessageBox::warning(this, "提示", "学号和姓名不能为空！");
        return;
    }
    this->accept();
}


void studenteditdialog::on_cancel_clicked()
{
    this->reject();
}

QStringList studenteditdialog::getData()
{
    QStringList data;
    data << ui->sno->text();
    data << ui->name->text();
    data << ui->class_2->text();
    data << ui->major->text();
    return data;
}

void studenteditdialog::setData(const QStringList &data)
{
    if(data.size() < 4) return;
    ui->sno->setText(data[0]);
    ui->name->setText(data[1]);
    ui->class_2->setText(data[2]);
    ui->major->setText(data[3]);
}
