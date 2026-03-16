#ifndef SCOREEDITDIALOG_H
#define SCOREEDITDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QStringList>

namespace Ui {
class scoreeditdialog;
}

class scoreeditdialog : public QDialog
{
    Q_OBJECT

public:
    explicit scoreeditdialog(bool isNew, QWidget *parent = nullptr);
    ~scoreeditdialog();

    QStringList getData();
    void setData(const QStringList &data);

private slots:
    void on_confirm_clicked();
    void on_cancel_clicked();

private:
    Ui::scoreeditdialog *ui;
    bool m_isNew;
};

#endif // SCOREEDITDIALOG_H
