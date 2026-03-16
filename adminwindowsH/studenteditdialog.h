#ifndef STUDENTEDITDIALOG_H
#define STUDENTEDITDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QStringList>

namespace Ui {
class studenteditdialog;
}

class studenteditdialog : public QDialog
{
    Q_OBJECT

public:
    explicit studenteditdialog(bool isNew, QWidget *parent = nullptr);
    ~studenteditdialog();
    QStringList getData();//新数据打包
    void setData(const QStringList &data);//旧数据获取显示

private slots:
    void on_confirm_clicked();
    void on_cancel_clicked();

private:
    Ui::studenteditdialog *ui;
    bool m_isNew;
};

#endif // STUDENTEDITDIALOG_H
