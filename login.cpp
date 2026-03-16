#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::login)
{
    ui->setupUi(this);
    this->setWindowTitle("登录");
}

login::~login()
{
    delete ui;
}

void login::on_login_2_clicked()
{
    QString account = ui->account->text();
    QString password = ui->password->text();
    qDebug() << "account:" << account;
    Account=account;
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query(db);
    QString sql = QString("SELECT password, role FROM accounts WHERE account_id = '%1'").arg(account);
    query.exec(sql);
    if (query.next())
    {
        QString dbPassword = query.value(0).toString();
        QString dbRole = query.value(1).toString();
        if(dbPassword == password)
        {
            Role=dbRole;
            qDebug() << "login success - Account:" << Account << "Role:" << Role;
            this->accept();
        }
        else
        {
            QMessageBox::warning(this, "错误", "账号或密码错误");
        }
    }
    else
    {
        QMessageBox::warning(this, "错误", "账号或密码错误");
    }
}


void login::on_register_2_clicked()
{
    reg regWindow(this);
    regWindow.exec();
}

QString login::getRole()
{
    return Role;
}


QString login::getAccount()
{
    return Account;
}
