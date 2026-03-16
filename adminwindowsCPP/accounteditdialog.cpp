#include "accounteditdialog.h"
#include "ui_accounteditdialog.h"

accounteditdialog::accounteditdialog(bool isNew, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::accounteditdialog),
    m_isNew(isNew)
{
    ui->setupUi(this);
    this->setWindowTitle(m_isNew ? "新建账户" : "修改账户");
    ui->role->addItems({"student", "teacher", "admin"});
    if(!m_isNew){
        ui->account->setReadOnly(true);
        ui->account->setStyleSheet("background-color: #E0E0E0;");
    }
}

accounteditdialog::~accounteditdialog()
{
    delete ui;
}

void accounteditdialog::on_confirm_clicked()
{
    if(ui->account->text().isEmpty() || ui->name->text().isEmpty()){
        QMessageBox::warning(this, "提示", "账号和姓名不能为空！");
        return;
    }
    this->accept();
}


void accounteditdialog::on_cancel_clicked()
{
    this->reject();
}

QStringList accounteditdialog::getData()
{
    QStringList data;
    data << ui->account->text();
    data << ui->name->text();
    data << ui->password->text();
    data << ui->role->currentText();
    return data;
}

void accounteditdialog::setData(const QStringList &data)
{
    if(data.size() < 4) return;
    ui->account->setText(data[0]);
    ui->name->setText(data[1]);
    ui->password->setText(data[2]);
    int index = ui->role->findText(data[3]);
    if(index >= 0){
        ui->role->setCurrentIndex(index);
    }
}
