#include "modifyscore.h"
#include "ui_modifyscore.h"

modifyscore::modifyscore(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::modifyscore)
{
    ui->setupUi(this);
}

modifyscore::~modifyscore()
{
    delete ui;
}

void modifyscore::on_confirm_clicked()
{
    QString scoreStr = ui->score->text();
    m_newscore = scoreStr.toDouble();
    accept();
}


void modifyscore::on_cancel_clicked()
{
    this->reject();
}

double modifyscore::getnewscore()
{
    return m_newscore;
}

void modifyscore::setInitScore(double score)
{
    ui->score->setText(QString::number(score));
}
