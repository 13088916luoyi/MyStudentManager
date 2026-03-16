#include "mainwindow.h"
#include <QApplication>

#include "admin.h"
#include "student.h"
#include "teacher.h"

#include <QSqlDatabase>
#include <QSqlError>
#include <QMessageBox>
#include <QSqlQuery>
#include <QDebug>

#include "login.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE"); // 1. 声明用SQLite
    db.setDatabaseName("table.db");         // 2. 填你的db文件名（要放在exe同级目录）
    if(!db.open())                                           // 3. 打开连接
    {
        QMessageBox::critical(nullptr, "错误", "连不上数据库：" + db.lastError().text());
        return 0;
    }
    qDebug() << "sql connect success!"; // 这里会在输出栏打印提示

    login loginWindow;
    loginWindow.exec();
    QString jump=loginWindow.getRole();
    QString id=loginWindow.getAccount();
    //qDebug() << jump;
    //qDebug()<<id;
    if(jump=="student")
    {
        student studentWindow(id);
        studentWindow.exec();
    }
    else if(jump=="admin")
    {
        admin adminWindow;
        adminWindow.exec();
    }
    else if(jump=="teacher")
    {
        teacher teacherWindow(id);
        //qDebug()<<id;
        teacherWindow.exec();
    }

    return a.exec();
}
