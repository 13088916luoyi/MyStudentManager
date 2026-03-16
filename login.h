#ifndef LOGIN_H
#define LOGIN_H

#include "reg.h"

#include <QDialog>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QMessageBox>
#include <QSqlQuery>
#include <QDebug>

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();
    QString getRole();
    QString getAccount();

private slots:
    void on_login_2_clicked();
    void on_register_2_clicked();

private:
    Ui::login *ui;
    QString Role;
    QString Account;
};

#endif // LOGIN_H
