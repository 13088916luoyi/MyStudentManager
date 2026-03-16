#include "courseeditdialog.h"
#include "ui_courseeditdialog.h"

courseeditdialog::courseeditdialog(bool isNew, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::courseeditdialog),
    m_isNew(isNew)
{
    ui->setupUi(this);
    this->setWindowTitle(m_isNew ? "新建课程" : "修改课程");
    ui->type->addItems({"必修", "选修"});
    if(!m_isNew){
        ui->id->setReadOnly(true);
        ui->id->setStyleSheet("background-color: #E0E0E0;");
    }
}

courseeditdialog::~courseeditdialog()
{
    delete ui;
}

void courseeditdialog::on_confirm_clicked()
{
    if(ui->id->text().isEmpty() || ui->name->text().isEmpty()){
        QMessageBox::warning(this, "提示", "课程号和课程名不能为空！");
        return;
    }
    this->accept();
}

void courseeditdialog::on_cancel_clicked()
{
    this->reject();
}


QStringList courseeditdialog::getData()
{
    QStringList data;
    data << ui->id->text();
    data << ui->name->text();
    data << ui->credit->text();
    data << ui->hour->text();
    data << ui->type->currentText();
    return data;
}


void courseeditdialog::setData(const QStringList &data)
{
    if(data.size() < 5) return;
    ui->id->setText(data[0]);
    ui->name->setText(data[1]);
    ui->credit->setText(data[2]);
    ui->hour->setText(data[3]);

    int typeIndex = ui->type->findText(data[4]);
    if(typeIndex >= 0){
        ui->type->setCurrentIndex(typeIndex);
    }
}
