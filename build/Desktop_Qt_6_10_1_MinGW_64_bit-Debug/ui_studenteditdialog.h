/********************************************************************************
** Form generated from reading UI file 'studenteditdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENTEDITDIALOG_H
#define UI_STUDENTEDITDIALOG_H

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

class Ui_studenteditdialog
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
    QLineEdit *sno;
    QLineEdit *name;
    QLineEdit *class_2;
    QLineEdit *major;
    QHBoxLayout *horizontalLayout;
    QPushButton *confirm;
    QPushButton *cancel;

    void setupUi(QDialog *studenteditdialog)
    {
        if (studenteditdialog->objectName().isEmpty())
            studenteditdialog->setObjectName("studenteditdialog");
        studenteditdialog->resize(363, 233);
        widget = new QWidget(studenteditdialog);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(60, 40, 241, 131));
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
        sno = new QLineEdit(widget);
        sno->setObjectName("sno");

        verticalLayout_2->addWidget(sno);

        name = new QLineEdit(widget);
        name->setObjectName("name");

        verticalLayout_2->addWidget(name);

        class_2 = new QLineEdit(widget);
        class_2->setObjectName("class_2");

        verticalLayout_2->addWidget(class_2);

        major = new QLineEdit(widget);
        major->setObjectName("major");

        verticalLayout_2->addWidget(major);


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


        retranslateUi(studenteditdialog);

        QMetaObject::connectSlotsByName(studenteditdialog);
    } // setupUi

    void retranslateUi(QDialog *studenteditdialog)
    {
        studenteditdialog->setWindowTitle(QCoreApplication::translate("studenteditdialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("studenteditdialog", "\345\255\246\345\217\267", nullptr));
        label_2->setText(QCoreApplication::translate("studenteditdialog", "\345\247\223\345\220\215", nullptr));
        label_3->setText(QCoreApplication::translate("studenteditdialog", "\347\217\255\347\272\247", nullptr));
        label_4->setText(QCoreApplication::translate("studenteditdialog", "\344\270\223\344\270\232", nullptr));
        confirm->setText(QCoreApplication::translate("studenteditdialog", "\347\241\256\350\256\244", nullptr));
        cancel->setText(QCoreApplication::translate("studenteditdialog", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class studenteditdialog: public Ui_studenteditdialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENTEDITDIALOG_H
