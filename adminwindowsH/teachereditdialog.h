#ifndef TEACHEREDITDIALOG_H
#define TEACHEREDITDIALOG_H

#include <QDialog>
#include <QStringList>

namespace Ui {
class teachereditdialog;
}

class teachereditdialog : public QDialog
{
    Q_OBJECT

public:
    explicit teachereditdialog(bool isNew, QWidget *parent = nullptr);
    ~teachereditdialog();

    QStringList getData();
    void setData(const QStringList &data);

private slots:
    void on_confirm_clicked();
    void on_cancel_clicked();

private:
    Ui::teachereditdialog *ui;
    bool m_isNew;
};

#endif // TEACHEREDITDIALOG_H
