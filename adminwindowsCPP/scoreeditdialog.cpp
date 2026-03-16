#include "scoreeditdialog.h"
#include "ui_scoreeditdialog.h"

scoreeditdialog::scoreeditdialog(bool isNew, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::scoreeditdialog),
    m_isNew(isNew)
{
    ui->setupUi(this);
    this->setWindowTitle(m_isNew ? "新建成绩" : "修改成绩");

    if(!m_isNew){
        ui->id->setReadOnly(true);
        ui->id->setStyleSheet("background-color: #E0E0E0;");
        ui->sno->setReadOnly(true);
        ui->sno->setStyleSheet("background-color: #E0E0E0;");
    }
}


scoreeditdialog::~scoreeditdialog()
{
    delete ui;
}

void scoreeditdialog::on_confirm_clicked()
{
    if(ui->id->text().isEmpty() || ui->sno->text().isEmpty()){
        QMessageBox::warning(this, "提示", "记录ID和学号不能为空！");
        return;
    }
    this->accept();
}


void scoreeditdialog::on_cancel_clicked()
{
    this->reject();
}

QStringList scoreeditdialog::getData()
{
    QStringList data;
    data << ui->id->text();
    data << ui->sno->text();
    data << ui->name->text();
    data << ui->classname->text();
    data << ui->score->text();
    return data;
}

void scoreeditdialog::setData(const QStringList &data)
{
    if(data.size() < 5) return;
    ui->id->setText(data[0]);
    ui->sno->setText(data[1]);
    ui->name->setText(data[2]);
    ui->classname->setText(data[3]);
    ui->score->setText(data[4]);
}
