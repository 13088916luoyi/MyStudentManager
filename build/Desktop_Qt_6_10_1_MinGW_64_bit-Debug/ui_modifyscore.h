/********************************************************************************
** Form generated from reading UI file 'modifyscore.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFYSCORE_H
#define UI_MODIFYSCORE_H

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

class Ui_modifyscore
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *score;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *confirm;
    QPushButton *cancel;

    void setupUi(QDialog *modifyscore)
    {
        if (modifyscore->objectName().isEmpty())
            modifyscore->setObjectName("modifyscore");
        modifyscore->resize(400, 300);
        widget = new QWidget(modifyscore);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(120, 120, 168, 50));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(widget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        score = new QLineEdit(widget);
        score->setObjectName("score");

        horizontalLayout->addWidget(score);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        confirm = new QPushButton(widget);
        confirm->setObjectName("confirm");

        horizontalLayout_2->addWidget(confirm);

        cancel = new QPushButton(widget);
        cancel->setObjectName("cancel");

        horizontalLayout_2->addWidget(cancel);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(modifyscore);

        QMetaObject::connectSlotsByName(modifyscore);
    } // setupUi

    void retranslateUi(QDialog *modifyscore)
    {
        modifyscore->setWindowTitle(QCoreApplication::translate("modifyscore", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("modifyscore", "\346\210\220\347\273\251", nullptr));
        confirm->setText(QCoreApplication::translate("modifyscore", "\347\241\256\350\256\244", nullptr));
        cancel->setText(QCoreApplication::translate("modifyscore", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class modifyscore: public Ui_modifyscore {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFYSCORE_H
