/********************************************************************************
** Form generated from reading UI file 'student.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENT_H
#define UI_STUDENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_student
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_4;
    QPushButton *select;
    QSpacerItem *verticalSpacer;
    QPushButton *watch;
    QSpacerItem *verticalSpacer_2;
    QPushButton *count;
    QSpacerItem *verticalSpacer_3;
    QPushButton *refresh;
    QSpacerItem *verticalSpacer_5;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QTableView *tableView;

    void setupUi(QDialog *student)
    {
        if (student->objectName().isEmpty())
            student->setObjectName("student");
        student->resize(673, 441);
        gridLayout = new QGridLayout(student);
        gridLayout->setObjectName("gridLayout");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        select = new QPushButton(student);
        select->setObjectName("select");

        verticalLayout->addWidget(select);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        watch = new QPushButton(student);
        watch->setObjectName("watch");

        verticalLayout->addWidget(watch);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        count = new QPushButton(student);
        count->setObjectName("count");

        verticalLayout->addWidget(count);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        refresh = new QPushButton(student);
        refresh->setObjectName("refresh");

        verticalLayout->addWidget(refresh);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");

        verticalLayout_2->addLayout(horizontalLayout);

        tableView = new QTableView(student);
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
        tableView->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);
        tableView->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);

        verticalLayout_2->addWidget(tableView);


        horizontalLayout_2->addLayout(verticalLayout_2);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);


        retranslateUi(student);

        QMetaObject::connectSlotsByName(student);
    } // setupUi

    void retranslateUi(QDialog *student)
    {
        student->setWindowTitle(QCoreApplication::translate("student", "Dialog", nullptr));
        select->setText(QCoreApplication::translate("student", "\347\202\271\345\207\273\351\200\211\350\257\276", nullptr));
        watch->setText(QCoreApplication::translate("student", "\346\237\245\347\234\213\346\211\200\351\200\211\350\257\276\347\250\213", nullptr));
        count->setText(QCoreApplication::translate("student", "\346\243\200\346\237\245\346\200\273\345\255\246\345\210\206", nullptr));
        refresh->setText(QCoreApplication::translate("student", "\345\210\267\346\226\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class student: public Ui_student {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENT_H
