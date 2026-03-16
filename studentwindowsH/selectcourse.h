#ifndef SELECTCOURSE_H
#define SELECTCOURSE_H

#include <QDialog>
#include <QSqlQueryModel>
#include <QSet>
#include <QSqlTableModel>
#include <QMessageBox>
#include <QSqlQuery>
#include <QHeaderView>
#include <QAbstractItemView>
#include <QItemSelectionModel>
#include <QSqlRecord>
#include <QDebug>




namespace Ui {
class selectcourse;
}

class selectcourse : public QDialog
{
    Q_OBJECT

public:
    explicit selectcourse(QString studentId, QString studentName, QWidget *parent = nullptr);
    ~selectcourse();

private slots:
    void on_confirm_clicked();

    void on_cancel_clicked();

private:
    Ui::selectcourse *ui;
    QString m_studentId;       // 学生学号
    QString m_studentName;     // 学生姓名
    QSqlQueryModel *m_model;   // 课程列表模型
    QSet<QString> m_alreadySelected; // 存已经选过的课程名
};

#endif // SELECTCOURSE_H
