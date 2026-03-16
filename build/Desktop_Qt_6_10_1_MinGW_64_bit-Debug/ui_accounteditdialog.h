/********************************************************************************
** Form generated from reading UI file 'accounteditdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCOUNTEDITDIALOG_H
#define UI_ACCOUNTEDITDIALOG_H

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

class Ui_accounteditdialog
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *account;
    QLineEdit *name;
    QLineEdit *password;
    QComboBox *role;
    QHBoxLayout *horizontalLayout;
    QPushButton *confirm;
    QPushButton *cancel;

    void setupUi(QDialog *accounteditdialog)
    {
        if (accounteditdialog->objectName().isEmpty())
            accounteditdialog->setObjectName("accounteditdialog");
        accounteditdialog->resize(378, 283);
        widget = new QWidget(accounteditdialog);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(93, 63, 191, 141));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
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


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        account = new QLineEdit(widget);
        account->setObjectName("account");

        verticalLayout_2->addWidget(account);

        name = new QLineEdit(widget);
        name->setObjectName("name");

        verticalLayout_2->addWidget(name);

        password = new QLineEdit(widget);
        password->setObjectName("password");

        verticalLayout_2->addWidget(password);

        role = new QComboBox(widget);
        role->setObjectName("role");

        verticalLayout_2->addWidget(role);


        horizontalLayout_2->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        confirm = new QPushButton(widget);
        confirm->setObjectName("confirm");

        horizontalLayout->addWidget(confirm);

        cancel = new QPushButton(widget);
        cancel->setObjectName("cancel");

        horizontalLayout->addWidget(cancel);


        verticalLayout_3->addLayout(horizontalLayout);


        retranslateUi(accounteditdialog);

        QMetaObject::connectSlotsByName(accounteditdialog);
    } // setupUi

    void retranslateUi(QDialog *accounteditdialog)
    {
        accounteditdialog->setWindowTitle(QCoreApplication::translate("accounteditdialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("accounteditdialog", "\350\264\246\345\217\267", nullptr));
        label_2->setText(QCoreApplication::translate("accounteditdialog", "\345\247\223\345\220\215", nullptr));
        label_3->setText(QCoreApplication::translate("accounteditdialog", "\345\257\206\347\240\201", nullptr));
        label_4->setText(QCoreApplication::translate("accounteditdialog", "\350\247\222\350\211\262", nullptr));
        confirm->setText(QCoreApplication::translate("accounteditdialog", "\347\241\256\350\256\244", nullptr));
        cancel->setText(QCoreApplication::translate("accounteditdialog", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class accounteditdialog: public Ui_accounteditdialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCOUNTEDITDIALOG_H
