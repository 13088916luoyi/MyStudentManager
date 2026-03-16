#ifndef ADMIN_H
#define ADMIN_H

#include <QDialog>
#include <QSqlTableModel>
#include <QMessageBox>
#include <QSqlError>

#include "studenteditdialog.h"
#include "teachereditdialog.h"
#include "courseeditdialog.h"
#include "scoreeditdialog.h"
#include "accounteditdialog.h"

namespace Ui {
class admin;
}

class admin : public QDialog
{
    Q_OBJECT

public:
    explicit admin(QWidget *parent = nullptr);
    ~admin();

private slots:
    void on_student_clicked();

    void on_teacher_clicked();

    void on_course_clicked();

    void on_score_clicked();

    void on_account_clicked();

    void on_create_clicked();

    void on_modify_clicked();

    void on_refresh_clicked();

    void on_delete_2_clicked();

    void showCellTooltip(const QModelIndex &index);

private:
    Ui::admin *ui;
    QSqlTableModel *m_model;
    enum CurrentTable {
        Table_None,
        Table_Student,
        Table_Teacher,
        Table_Course,
        Table_Score,
        Table_Account
    };
    CurrentTable m_currentTable = Table_None;
};

#endif // ADMIN_H
