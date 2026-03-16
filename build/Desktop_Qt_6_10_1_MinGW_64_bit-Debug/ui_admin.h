/********************************************************************************
** Form generated from reading UI file 'admin.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMIN_H
#define UI_ADMIN_H

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

class Ui_admin
{
public:
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QPushButton *student;
    QPushButton *teacher;
    QPushButton *course;
    QPushButton *score;
    QPushButton *account;
    QHBoxLayout *horizontalLayout;
    QPushButton *create;
    QSpacerItem *horizontalSpacer;
    QPushButton *modify;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *delete_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *refresh;
    QTableView *tableView;

    void setupUi(QDialog *admin)
    {
        if (admin->objectName().isEmpty())
            admin->setObjectName("admin");
        admin->resize(673, 441);
        gridLayout = new QGridLayout(admin);
        gridLayout->setObjectName("gridLayout");
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        student = new QPushButton(admin);
        student->setObjectName("student");

        verticalLayout->addWidget(student);

        teacher = new QPushButton(admin);
        teacher->setObjectName("teacher");

        verticalLayout->addWidget(teacher);

        course = new QPushButton(admin);
        course->setObjectName("course");

        verticalLayout->addWidget(course);

        score = new QPushButton(admin);
        score->setObjectName("score");

        verticalLayout->addWidget(score);

        account = new QPushButton(admin);
        account->setObjectName("account");

        verticalLayout->addWidget(account);


        gridLayout_2->addLayout(verticalLayout, 0, 0, 2, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        create = new QPushButton(admin);
        create->setObjectName("create");

        horizontalLayout->addWidget(create);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        modify = new QPushButton(admin);
        modify->setObjectName("modify");

        horizontalLayout->addWidget(modify);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        delete_2 = new QPushButton(admin);
        delete_2->setObjectName("delete_2");

        horizontalLayout->addWidget(delete_2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        refresh = new QPushButton(admin);
        refresh->setObjectName("refresh");

        horizontalLayout->addWidget(refresh);


        gridLayout_2->addLayout(horizontalLayout, 0, 1, 1, 1);

        tableView = new QTableView(admin);
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

        gridLayout_2->addWidget(tableView, 1, 1, 1, 1);


        gridLayout->addLayout(gridLayout_2, 0, 0, 1, 1);


        retranslateUi(admin);

        QMetaObject::connectSlotsByName(admin);
    } // setupUi

    void retranslateUi(QDialog *admin)
    {
        admin->setWindowTitle(QCoreApplication::translate("admin", "Dialog", nullptr));
        student->setText(QCoreApplication::translate("admin", "\345\255\246\347\224\237\347\256\241\347\220\206", nullptr));
        teacher->setText(QCoreApplication::translate("admin", "\350\200\201\345\270\210\347\256\241\347\220\206", nullptr));
        course->setText(QCoreApplication::translate("admin", "\350\257\276\347\250\213\347\256\241\347\220\206", nullptr));
        score->setText(QCoreApplication::translate("admin", "\346\210\220\347\273\251\347\256\241\347\220\206", nullptr));
        account->setText(QCoreApplication::translate("admin", "\350\264\246\346\210\267\347\256\241\347\220\206", nullptr));
        create->setText(QCoreApplication::translate("admin", "\346\226\260\345\273\272", nullptr));
        modify->setText(QCoreApplication::translate("admin", "\344\277\256\346\224\271", nullptr));
        delete_2->setText(QCoreApplication::translate("admin", "\345\210\240\351\231\244", nullptr));
        refresh->setText(QCoreApplication::translate("admin", "\345\210\267\346\226\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class admin: public Ui_admin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMIN_H
