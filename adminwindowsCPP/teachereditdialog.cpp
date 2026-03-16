#include "teachereditdialog.h"
#include "ui_teachereditdialog.h"
#include <QMessageBox>

teachereditdialog::teachereditdialog(bool isNew, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::teachereditdialog),
    m_isNew(isNew)
{
    ui->setupUi(this);
    this->setWindowTitle(m_isNew ? "新建教师" : "修改教师");

    if(!m_isNew){
        ui->id->setReadOnly(true);
        ui->id->setStyleSheet("background-color: #E0E0E0;");
    }
}

teachereditdialog::~teachereditdialog()
{
    delete ui;
}

void teachereditdialog::on_confirm_clicked()
{
    if(ui->id->text().isEmpty() || ui->name->text().isEmpty()){
        QMessageBox::warning(this, "提示", "工号和姓名不能为空！");
        return;
    }
    this->accept();
}

void teachereditdialog::on_cancel_clicked()
{
    this->reject();
}

QStringList teachereditdialog::getData()
{
    QStringList data;
    data << ui->id->text();
    data << ui->name->text();
    data << ui->classes->text();
    return data;
}

void teachereditdialog::setData(const QStringList &data)
{
    if(data.size() < 3) return; // 教师表一共3列
    ui->id->setText(data[0]);
    ui->name->setText(data[1]);
    ui->classes->setText(data[2]);
}
