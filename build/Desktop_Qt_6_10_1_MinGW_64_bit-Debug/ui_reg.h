/********************************************************************************
** Form generated from reading UI file 'reg.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REG_H
#define UI_REG_H

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

class Ui_reg
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
    QVBoxLayout *verticalLayout_2;
    QLineEdit *account;
    QLineEdit *password;
    QLineEdit *name;
    QComboBox *id;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *submit;
    QPushButton *cancel;

    void setupUi(QDialog *reg)
    {
        if (reg->objectName().isEmpty())
            reg->setObjectName("reg");
        reg->resize(400, 250);
        widget = new QWidget(reg);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(80, 50, 231, 141));
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


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        account = new QLineEdit(widget);
        account->setObjectName("account");

        verticalLayout_2->addWidget(account);

        password = new QLineEdit(widget);
        password->setObjectName("password");

        verticalLayout_2->addWidget(password);

        name = new QLineEdit(widget);
        name->setObjectName("name");

        verticalLayout_2->addWidget(name);

        id = new QComboBox(widget);
        id->setObjectName("id");

        verticalLayout_2->addWidget(id);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        submit = new QPushButton(widget);
        submit->setObjectName("submit");

        horizontalLayout_2->addWidget(submit);

        cancel = new QPushButton(widget);
        cancel->setObjectName("cancel");

        horizontalLayout_2->addWidget(cancel);


        verticalLayout_3->addLayout(horizontalLayout_2);


        retranslateUi(reg);

        QMetaObject::connectSlotsByName(reg);
    } // setupUi

    void retranslateUi(QDialog *reg)
    {
        reg->setWindowTitle(QCoreApplication::translate("reg", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("reg", "\350\264\246\345\217\267", nullptr));
        label_2->setText(QCoreApplication::translate("reg", "\345\257\206\347\240\201", nullptr));
        label_3->setText(QCoreApplication::translate("reg", "\345\247\223\345\220\215", nullptr));
        label_4->setText(QCoreApplication::translate("reg", "\350\272\253\344\273\275", nullptr));
        submit->setText(QCoreApplication::translate("reg", "\346\217\220\344\272\244", nullptr));
        cancel->setText(QCoreApplication::translate("reg", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class reg: public Ui_reg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REG_H
