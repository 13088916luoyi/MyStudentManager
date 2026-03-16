#ifndef REG_H
#define REG_H

#include <QDialog>

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>

namespace Ui {
class reg;
}

class reg : public QDialog
{
    Q_OBJECT

public:
    explicit reg(QWidget *parent = nullptr);
    ~reg();

private slots:
    void on_submit_clicked();

    void on_cancel_clicked();

private:
    Ui::reg *ui;
};

#endif // REG_H
