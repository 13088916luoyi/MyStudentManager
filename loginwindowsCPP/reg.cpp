#include "reg.h"
#include "ui_reg.h"

reg::reg(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::reg)
{
    ui->setupUi(this);
    this->setWindowTitle("注册");
    ui->id->addItem("学生", "student");
    ui->id->addItem("教师", "teacher");
    ui->id->addItem("管理员", "admin");
}

reg::~reg()
{
    delete ui;
}

void reg::on_submit_clicked()
{
    QString account = ui->account->text();
    QString password = ui->password->text();
    QString name = ui->name->text();
    QString role = ui->id->currentData().toString();

    if(account.isEmpty()){
        QMessageBox::warning(this, "提示", "账号不能为空！");
        ui->account->setFocus();
        return;
    }
    if(password.isEmpty()){
        QMessageBox::warning(this, "提示", "密码不能为空！");
        ui->password->setFocus();
        return;
    }
    if(name.isEmpty()){
        QMessageBox::warning(this, "提示", "姓名不能为空！");
        ui->name->setFocus();
        return;
    }

    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery checkQuery(db);
    QString checkSql = QString("SELECT account_id FROM accounts WHERE account_id = '%1'").arg(account);
    checkQuery.exec(checkSql);
    if(!checkQuery.next())
    {
        QSqlQuery insertQuery(db);
        QString insertSql = QString("INSERT INTO accounts (account_id, password, name, role)" "VALUES ('%1', '%2', '%3', '%4')").arg(account).arg(password).arg(name).arg(role);
        if(insertQuery.exec(insertSql))
        {
            QMessageBox::information(this, "成功", "注册成功！");
            this->accept();
        }
        else
        {
            QMessageBox::critical(this, "错误", "注册失败");
        }
    }
    else
    {
        QMessageBox::warning(this, "提示", "该账号已被注册，请换一个账号！");
        ui->account->clear();
        ui->account->setFocus();
    }
}


void reg::on_cancel_clicked()
{
    this->reject();
}

