#ifndef ACCOUNTEDITDIALOG_H
#define ACCOUNTEDITDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QStringList>

namespace Ui {
class accounteditdialog;
}

class accounteditdialog : public QDialog
{
    Q_OBJECT

public:
    explicit accounteditdialog(bool isNew, QWidget *parent = nullptr);
    ~accounteditdialog();
    QStringList getData();
    void setData(const QStringList &data);
private slots:
    void on_confirm_clicked();
    void on_cancel_clicked();

private:
    Ui::accounteditdialog *ui;
    bool m_isNew;
};

#endif // ACCOUNTEDITDIALOG_H
