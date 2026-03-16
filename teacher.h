#ifndef TEACHER_H
#define TEACHER_H

#include "modifyscore.h"

#include <QDialog>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QMessageBox>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlTableModel>
#include <QStringList>
#include <QModelIndex>

namespace Ui {
class teacher;
}

class teacher : public QDialog
{
    Q_OBJECT

public:
    explicit teacher(QString staffId, QWidget *parent = nullptr);
    ~teacher();
    void loadTeacherInfo();
    void dosearch();
private slots:
    void on_student_clicked();

    void on_modify_clicked();

    void on_analysis_clicked();

    void on_refresh_clicked();

    void on_sort_clicked();

    void on_moreinf_clicked();

    void showCellTooltip(const QModelIndex &index);

private:
    Ui::teacher *ui;
    QSqlTableModel *m_model;
    QString m_staffId;
    QStringList m_teachCourses;
    QString m_currentCourseFilter;
};

#endif // TEACHER_H
