/********************************************************************************
** Form generated from reading UI file 'teachereditdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEACHEREDITDIALOG_H
#define UI_TEACHEREDITDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_teachereditdialog
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *id;
    QLineEdit *name;
    QLineEdit *classes;
    QHBoxLayout *horizontalLayout;
    QPushButton *confirm;
    QPushButton *cancel;

    void setupUi(QDialog *teachereditdialog)
    {
        if (teachereditdialog->objectName().isEmpty())
            teachereditdialog->setObjectName("teachereditdialog");
        teachereditdialog->resize(393, 274);
        layoutWidget = new QWidget(teachereditdialog);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(100, 80, 191, 111));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(layoutWidget);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");

        verticalLayout->addWidget(label_3);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        id = new QLineEdit(layoutWidget);
        id->setObjectName("id");

        verticalLayout_2->addWidget(id);

        name = new QLineEdit(layoutWidget);
        name->setObjectName("name");

        verticalLayout_2->addWidget(name);

        classes = new QLineEdit(layoutWidget);
        classes->setObjectName("classes");

        verticalLayout_2->addWidget(classes);


        horizontalLayout_2->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        confirm = new QPushButton(layoutWidget);
        confirm->setObjectName("confirm");

        horizontalLayout->addWidget(confirm);

        cancel = new QPushButton(layoutWidget);
        cancel->setObjectName("cancel");

        horizontalLayout->addWidget(cancel);


        verticalLayout_3->addLayout(horizontalLayout);


        retranslateUi(teachereditdialog);

        QMetaObject::connectSlotsByName(teachereditdialog);
    } // setupUi

    void retranslateUi(QDialog *teachereditdialog)
    {
        teachereditdialog->setWindowTitle(QCoreApplication::translate("teachereditdialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("teachereditdialog", "\345\267\245\345\217\267", nullptr));
        label_2->setText(QCoreApplication::translate("teachereditdialog", "\345\247\223\345\220\215", nullptr));
        label_3->setText(QCoreApplication::translate("teachereditdialog", "\346\211\200\346\225\231\350\257\276\347\250\213", nullptr));
        confirm->setText(QCoreApplication::translate("teachereditdialog", "\347\241\256\350\256\244", nullptr));
        cancel->setText(QCoreApplication::translate("teachereditdialog", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class teachereditdialog: public Ui_teachereditdialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEACHEREDITDIALOG_H
