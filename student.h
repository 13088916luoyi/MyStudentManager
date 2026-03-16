#ifndef STUDENT_H
#define STUDENT_H

#include "selectcourse.h"

#include <QDialog>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlTableModel>
#include <QStringList>
#include <QModelIndex>

namespace Ui {
class student;
}

class student : public QDialog
{
    Q_OBJECT

public:
    explicit student(QString id, QWidget *parent = nullptr);
    ~student();

private slots:
    void on_select_clicked();

    void on_watch_clicked();

    void on_count_clicked();

    void on_refresh_clicked();

    void showCellTooltip(const QModelIndex &index);

private:
    Ui::student *ui;
    QString m_studentId; // 保存登录时传入的学生学号
    QSqlTableModel *m_model;
};

#endif // STUDENT_H
