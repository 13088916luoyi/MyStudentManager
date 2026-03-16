#ifndef MODIFYSCORE_H
#define MODIFYSCORE_H

#include <QDialog>

namespace Ui {
class modifyscore;
}

class modifyscore : public QDialog
{
    Q_OBJECT

public:
    explicit modifyscore(QWidget *parent = nullptr);
    ~modifyscore();
    double getnewscore();
    void setInitScore(double score);
private slots:
    void on_confirm_clicked();

    void on_cancel_clicked();

private:
    Ui::modifyscore *ui;
    double m_newscore = 0;
};

#endif // MODIFYSCORE_H
