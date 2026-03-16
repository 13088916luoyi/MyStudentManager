/********************************************************************************
** Form generated from reading UI file 'courseeditdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COURSEEDITDIALOG_H
#define UI_COURSEEDITDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_courseeditdialog
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *id;
    QLineEdit *name;
    QLineEdit *credit;
    QLineEdit *hour;
    QComboBox *type;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *confirm;
    QPushButton *cancel;

    void setupUi(QDialog *courseeditdialog)
    {
        if (courseeditdialog->objectName().isEmpty())
            courseeditdialog->setObjectName("courseeditdialog");
        courseeditdialog->resize(400, 300);
        widget = new QWidget(courseeditdialog);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(90, 60, 211, 182));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(widget);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(widget);
        label_4->setObjectName("label_4");

        verticalLayout->addWidget(label_4);

        label_5 = new QLabel(widget);
        label_5->setObjectName("label_5");

        verticalLayout->addWidget(label_5);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        id = new QLineEdit(widget);
        id->setObjectName("id");

        verticalLayout_2->addWidget(id);

        name = new QLineEdit(widget);
        name->setObjectName("name");

        verticalLayout_2->addWidget(name);

        credit = new QLineEdit(widget);
        credit->setObjectName("credit");

        verticalLayout_2->addWidget(credit);

        hour = new QLineEdit(widget);
        hour->setObjectName("hour");

        verticalLayout_2->addWidget(hour);

        type = new QComboBox(widget);
        type->setObjectName("type");

        verticalLayout_2->addWidget(type);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        confirm = new QPushButton(widget);
        confirm->setObjectName("confirm");

        horizontalLayout_2->addWidget(confirm);

        cancel = new QPushButton(widget);
        cancel->setObjectName("cancel");

        horizontalLayout_2->addWidget(cancel);


        verticalLayout_3->addLayout(horizontalLayout_2);


        retranslateUi(courseeditdialog);

        QMetaObject::connectSlotsByName(courseeditdialog);
    } // setupUi

    void retranslateUi(QDialog *courseeditdialog)
    {
        courseeditdialog->setWindowTitle(QCoreApplication::translate("courseeditdialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("courseeditdialog", "\350\257\276\347\250\213\345\217\267", nullptr));
        label_2->setText(QCoreApplication::translate("courseeditdialog", "\350\257\276\345\220\215\345\255\227", nullptr));
        label_3->setText(QCoreApplication::translate("courseeditdialog", "\345\255\246\345\210\206", nullptr));
        label_4->setText(QCoreApplication::translate("courseeditdialog", "\350\257\276\346\227\266", nullptr));
        label_5->setText(QCoreApplication::translate("courseeditdialog", "\346\200\247\350\264\250", nullptr));
        confirm->setText(QCoreApplication::translate("courseeditdialog", "\347\241\256\350\256\244", nullptr));
        cancel->setText(QCoreApplication::translate("courseeditdialog", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class courseeditdialog: public Ui_courseeditdialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COURSEEDITDIALOG_H
