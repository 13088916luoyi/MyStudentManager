QT += core gui sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# 添加包含路径，让编译器能找到子文件夹中的头文件
INCLUDEPATH += \
    adminwindowsH \
    studentwindowsH \
    teacherwindowsH \
    loginwindowsH

SOURCES += \
    adminwindowsCPP/accounteditdialog.cpp \
    adminwindowsCPP/courseeditdialog.cpp \
    adminwindowsCPP/scoreeditdialog.cpp \
    adminwindowsCPP/studenteditdialog.cpp \
    adminwindowsCPP/teachereditdialog.cpp \
    admin.cpp \
    login.cpp \
    loginwindowsCPP/reg.cpp \
    main.cpp \
    mainwindow.cpp \
    student.cpp \
    studentwindowsCPP/selectcourse.cpp \
    teacher.cpp \
    teacherwindowsCPP/modifyscore.cpp

HEADERS += \
    adminwindowsH/accounteditdialog.h \
    adminwindowsH/courseeditdialog.h \
    adminwindowsH/scoreeditdialog.h \
    adminwindowsH/studenteditdialog.h \
    adminwindowsH/teachereditdialog.h \
    admin.h \
    login.h \
    loginwindowsH/reg.h \
    mainwindow.h \
    student.h \
    studentwindowsH/selectcourse.h \
    teacher.h \
    teacherwindowsH/modifyscore.h

FORMS += \
    adminwindowsUI/accounteditdialog.ui \
    adminwindowsUI/courseeditdialog.ui \
    adminwindowsUI/scoreeditdialog.ui \
    adminwindowsUI/studenteditdialog.ui \
    adminwindowsUI/teachereditdialog.ui \
    admin.ui \
    login.ui \
    loginwindowsUI/reg.ui \
    mainwindow.ui \
    student.ui \
    studentwindowsUI/selectcourse.ui \
    teacher.ui \
    teacherwindowsUI/modifyscore.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
