/********************************************************************************
** Form generated from reading UI file 'selectcourse.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTCOURSE_H
#define UI_SELECTCOURSE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_selectcourse
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *confirm;
    QPushButton *cancel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *selectcourse)
    {
        if (selectcourse->objectName().isEmpty())
            selectcourse->setObjectName("selectcourse");
        selectcourse->resize(673, 411);
        widget = new QWidget(selectcourse);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(10, 10, 651, 391));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tableView = new QTableView(widget);
        tableView->setObjectName("tableView");
        tableView->setStyleSheet(QString::fromUtf8("/* \350\241\250\346\240\274\346\225\264\344\275\223\357\274\232\350\256\276\347\275\256\347\275\221\346\240\274\347\272\277\351\242\234\350\211\262\357\274\214\350\256\251\350\241\250\346\240\274\346\233\264\346\270\205\346\231\260 */\n"
"QTableView {\n"
"    gridline-color: #E5E5E5;\n"
"    outline: none; /* \345\216\273\346\216\211\347\202\271\345\207\273\346\227\266\347\232\204\350\231\232\347\272\277\346\241\206 */\n"
"}\n"
"\n"
"/* \350\241\250\345\244\264\357\274\232\350\256\276\347\275\256\350\203\214\346\231\257\350\211\262\345\222\214\346\226\207\345\255\227\350\211\262\357\274\214\346\233\264\347\276\216\350\247\202 */\n"
"QHeaderView::section {\n"
"    background-color: #F5F5F5;\n"
"    color: #333333;\n"
"    padding: 6px;\n"
"    border: 1px solid #E0E0E0;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"/* \343\200\220\346\240\270\345\277\203\343\200\221\351\200\211\344\270\255\350\241\214\357\274\232\350\256\276\347\275\256\350\203\214\346\231\257\350\211\262\345\222\214\346\226\207\345\255\227\350\211"
                        "\262\357\274\214\346\225\264\350\241\214\351\253\230\344\272\256 */\n"
"QTableView::item:selected {\n"
"    background-color: #0078D4; /* \344\272\256\350\223\235\350\211\262\350\203\214\346\231\257\357\274\214\344\275\240\345\217\257\344\273\245\346\224\271\346\210\220 #2196F3 \346\210\226 #107C10 */\n"
"    color: #FFFFFF;             /* \347\231\275\350\211\262\346\226\207\345\255\227\357\274\214\345\222\214\350\203\214\346\231\257\345\275\242\346\210\220\345\274\272\347\203\210\345\257\271\346\257\224 */\n"
"}\n"
"\n"
"/* \343\200\220\350\241\245\345\205\205\343\200\221\345\215\263\344\275\277\347\252\227\345\217\243\345\244\261\345\216\273\347\204\246\347\202\271\357\274\214\351\200\211\344\270\255\350\241\214\344\271\237\344\277\235\346\214\201\351\253\230\344\272\256\357\274\214\344\270\215\344\274\232\345\217\230\347\201\260 */\n"
"QTableView::item:selected:!active {\n"
"    background-color: #0078D4;\n"
"    color: #FFFFFF;\n"
"}"));
        tableView->setSelectionMode(QAbstractItemView::SelectionMode::MultiSelection);
        tableView->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);

        verticalLayout->addWidget(tableView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        confirm = new QPushButton(widget);
        confirm->setObjectName("confirm");

        horizontalLayout->addWidget(confirm);

        cancel = new QPushButton(widget);
        cancel->setObjectName("cancel");

        horizontalLayout->addWidget(cancel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(selectcourse);

        QMetaObject::connectSlotsByName(selectcourse);
    } // setupUi

    void retranslateUi(QDialog *selectcourse)
    {
        selectcourse->setWindowTitle(QCoreApplication::translate("selectcourse", "Dialog", nullptr));
        confirm->setText(QCoreApplication::translate("selectcourse", "\347\241\256\345\256\232", nullptr));
        cancel->setText(QCoreApplication::translate("selectcourse", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class selectcourse: public Ui_selectcourse {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTCOURSE_H
