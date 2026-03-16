#ifndef COURSEEDITDIALOG_H
#define COURSEEDITDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QStringList>

namespace Ui {
class courseeditdialog;
}

class courseeditdialog : public QDialog
{
    Q_OBJECT

public:
    explicit courseeditdialog(bool isNew, QWidget *parent = nullptr);
    ~courseeditdialog();

    QStringList getData();
    void setData(const QStringList &data);

private slots:
    void on_confirm_clicked();
    void on_cancel_clicked();

private:
    Ui::courseeditdialog *ui;
    bool m_isNew;
};

#endif // COURSEEDITDIALOG_H
