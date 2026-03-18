# MyStudentManager - 学生信息管理系统

## 一、项目概述

### 1.1 项目简介

MyStudentManager 是一个基于 **Qt 6 + SQLite** 开发的桌面端学生信息管理系统。系统采用**三角色权限分离**架构，支持学生、教师、管理员三种用户角色，每种角色拥有独立的功能模块和操作权限。

## 二、总体设计思路

### 2.1 设计理念

本系统遵循**分层架构**和**职责分离**的设计原则：

1. **表现层 (UI)**：使用 Qt Designer 设计界面，通过 `.ui` 文件与代码分离
2. **业务逻辑层**：各模块类封装具体业务逻辑，通过信号槽机制响应用户操作
3. **数据访问层**：使用 `QSqlTableModel` 实现数据绑定，`QSqlQuery` 执行复杂查询
4. **数据存储层**：SQLite 嵌入式数据库，无需额外服务器配置

## 三、项目结构

```
MyStudentManager/
├── main.cpp                              # 程序入口
├── MyStudentManager.pro                  # Qt项目配置文件
│
├── login.h / login.cpp / login.ui        # 登录模块
├── admin.h / admin.cpp / admin.ui        # 管理员主界面
├── student.h / student.cpp / student.ui  # 学生主界面
├── teacher.h / teacher.cpp / teacher.ui  # 教师主界面
│
├── loginwindowsH/                        # 登录模块子窗口
│   └── reg.h                             # 注册对话框头文件
├── loginwindowsCPP/
│   └── reg.cpp                           # 注册对话框实现
├── loginwindowsUI/
│   └── reg.ui                            # 注册对话框界面
│
├── adminwindowsH/                        # 管理员模块子窗口
│   ├── studenteditdialog.h               # 学生编辑对话框
│   ├── teachereditdialog.h               # 教师编辑对话框
│   ├── courseeditdialog.h                # 课程编辑对话框
│   ├── scoreeditdialog.h                 # 成绩编辑对话框
│   └── accounteditdialog.h               # 账户编辑对话框
├── adminwindowsCPP/
│   ├── studenteditdialog.cpp
│   ├── teachereditdialog.cpp
│   ├── courseeditdialog.cpp
│   ├── scoreeditdialog.cpp
│   └── accounteditdialog.cpp
├── adminwindowsUI/
│   ├── studenteditdialog.ui
│   ├── teachereditdialog.ui
│   ├── courseeditdialog.ui
│   ├── scoreeditdialog.ui
│   └── accounteditdialog.ui
│
├── studentwindowsH/                      # 学生模块子窗口
│   └── selectcourse.h                    # 选课对话框头文件
├── studentwindowsCPP/
│   └── selectcourse.cpp                  # 选课对话框实现
├── studentwindowsUI/
│   └── selectcourse.ui                   # 选课对话框界面
│
├── teacherwindowsH/                      # 教师模块子窗口
│   └── modifyscore.h                     # 成绩修改对话框头文件
├── teacherwindowsCPP/
│   └── modifyscore.cpp                   # 成绩修改对话框实现
├── teacherwindowsUI/
│   └── modifyscore.ui                    # 成绩修改对话框界面
│
├── CreateTable.py                        # 数据库初始化脚本
├── module_project2/                      # 初始数据文件夹
│   ├── module.txt                        # 课程数据
│   ├── student.txt                       # 学生数据
│   ├── staff.txt                         # 教职工数据
│   └── score.txt                         # 成绩数据
│
└── 文档资料/
    └── README.md                         # 项目说明文档
```

## 四、注意事项

1. **数据库文件位置**：`table.db` 需要与可执行文件放在同一目录
2. **修改 .pro 文件后**：需要重新执行 qmake
3. **编码问题**：数据文件使用 GBK 编码，如有乱码请检查编码设置
4. **主键约束**：修改模式下主键字段不可编辑（灰色背景提示）
5. **成绩默认值**：新选课程成绩默认为 0 分
