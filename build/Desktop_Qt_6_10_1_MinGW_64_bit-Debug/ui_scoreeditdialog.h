/********************************************************************************
** Form generated from reading UI file 'scoreeditdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCOREEDITDIALOG_H
#define UI_SCOREEDITDIALOG_H

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

class Ui_scoreeditdialog
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_5;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *id;
    QLineEdit *sno;
    QLineEdit *name;
    QLineEdit *classname;
    QLineEdit *score;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *confirm;
    QPushButton *cancel;

    void setupUi(QDialog *scoreeditdialog)
    {
        if (scoreeditdialog->objectName().isEmpty())
            scoreeditdialog->setObjectName("scoreeditdialog");
        scoreeditdialog->resize(400, 300);
        widget = new QWidget(scoreeditdialog);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(90, 60, 221, 171));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label_5 = new QLabel(widget);
        label_5->setObjectName("label_5");

        verticalLayout->addWidget(label_5);

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
        id = new QLineEdit(widget);
        id->setObjectName("id");

        verticalLayout_2->addWidget(id);

        sno = new QLineEdit(widget);
        sno->setObjectName("sno");

        verticalLayout_2->addWidget(sno);

        name = new QLineEdit(widget);
        name->setObjectName("name");

        verticalLayout_2->addWidget(name);

        classname = new QLineEdit(widget);
        classname->setObjectName("classname");

        verticalLayout_2->addWidget(classname);

        score = new QLineEdit(widget);
        score->setObjectName("score");

        verticalLayout_2->addWidget(score);


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


        retranslateUi(scoreeditdialog);

        QMetaObject::connectSlotsByName(scoreeditdialog);
    } // setupUi

    void retranslateUi(QDialog *scoreeditdialog)
    {
        scoreeditdialog->setWindowTitle(QCoreApplication::translate("scoreeditdialog", "Dialog", nullptr));
        label_5->setText(QCoreApplication::translate("scoreeditdialog", "\346\240\207\345\217\267", nullptr));
        label->setText(QCoreApplication::translate("scoreeditdialog", "\345\255\246\345\217\267", nullptr));
        label_2->setText(QCoreApplication::translate("scoreeditdialog", "\345\247\223\345\220\215", nullptr));
        label_3->setText(QCoreApplication::translate("scoreeditdialog", "\350\257\276\345\220\215", nullptr));
        label_4->setText(QCoreApplication::translate("scoreeditdialog", "\345\210\206\346\225\260", nullptr));
        confirm->setText(QCoreApplication::translate("scoreeditdialog", "\347\241\256\350\256\244", nullptr));
        cancel->setText(QCoreApplication::translate("scoreeditdialog", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class scoreeditdialog: public Ui_scoreeditdialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCOREEDITDIALOG_H
