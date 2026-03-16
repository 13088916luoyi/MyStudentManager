# MyStudentManager - 学生信息管理系统

## 一、项目概述

### 1.1 项目简介

MyStudentManager 是一个基于 **Qt 6 + SQLite** 开发的桌面端学生信息管理系统。系统采用**三角色权限分离**架构，支持学生、教师、管理员三种用户角色，每种角色拥有独立的功能模块和操作权限。

### 1.2 技术栈

| 技术项 | 版本/说明 |
|--------|-----------|
| 开发框架 | Qt 6.10.1 (C++17) |
| 数据库 | SQLite 3 (嵌入式数据库) |
| 构建工具 | qmake + MinGW 64-bit |
| UI设计 | Qt Designer (.ui 文件) |
| 数据访问 | QSqlTableModel + QSqlQuery |
| 数据初始化 | Python 3 (CreateTable.py) |

### 1.3 系统架构图

```
┌─────────────────────────────────────────────────────────────────┐
│                        main.cpp (程序入口)                        │
│   ┌─────────────┐    ┌─────────────┐    ┌─────────────┐        │
│   │ 数据库连接   │ -> │  登录验证   │ -> │ 角色路由分发 │        │
│   └─────────────┘    └─────────────┘    └─────────────┘        │
└─────────────────────────────────────────────────────────────────┘
                              │
         ┌────────────────────┼────────────────────┐
         ▼                    ▼                    ▼
┌─────────────────┐  ┌─────────────────┐  ┌─────────────────┐
│   学生模块       │  │   教师模块       │  │   管理员模块     │
│  (student.cpp)  │  │  (teacher.cpp)  │  │   (admin.cpp)   │
├─────────────────┤  ├─────────────────┤  ├─────────────────┤
│ - 查看个人成绩   │  │ - 查看授课课程   │  │ - 学生管理       │
│ - 选课/退课     │  │ - 成绩录入修改   │  │ - 教师管理       │
│ - 学分统计      │  │ - 成绩统计分析   │  │ - 课程管理       │
└─────────────────┘  └─────────────────┘  │ - 成绩管理       │
                                          │ - 账户管理       │
                                          └─────────────────┘
                              │
                              ▼
                    ┌─────────────────┐
                    │   SQLite 数据库  │
                    │   (table.db)    │
                    └─────────────────┘
```

---

## 二、总体设计思路

### 2.1 设计理念

本系统遵循**分层架构**和**职责分离**的设计原则：

1. **表现层 (UI)**：使用 Qt Designer 设计界面，通过 `.ui` 文件与代码分离
2. **业务逻辑层**：各模块类封装具体业务逻辑，通过信号槽机制响应用户操作
3. **数据访问层**：使用 `QSqlTableModel` 实现数据绑定，`QSqlQuery` 执行复杂查询
4. **数据存储层**：SQLite 嵌入式数据库，无需额外服务器配置

### 2.2 核心设计模式

#### 2.2.1 模态对话框模式
系统所有窗口均继承自 `QDialog`，采用模态方式运行（`exec()`），确保用户完成当前操作后才能进行下一步：

```cpp
// main.cpp:29-50 - 登录后根据角色跳转
login loginWindow;
loginWindow.exec();                    // 阻塞等待登录完成
QString jump = loginWindow.getRole();  // 获取登录角色
if(jump == "student") {
    student studentWindow(id);
    studentWindow.exec();              // 进入学生界面
}
```

#### 2.2.2 数据绑定模式
使用 `QSqlTableModel` 实现 **Model-View** 架构，数据自动同步：

```cpp
// admin.cpp:11-14 - 表格数据绑定
m_model = new QSqlTableModel(this, db);
ui->tableView->setModel(m_model);      // 视图绑定模型
ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
```

#### 2.2.3 状态机模式
管理员模块使用枚举状态机管理当前操作的表：

```cpp
// admin.h:49-57 - 表状态枚举
enum CurrentTable {
    Table_None,      // 未选择
    Table_Student,   // 学生表
    Table_Teacher,   // 教师表
    Table_Course,    // 课程表
    Table_Score,     // 成绩表
    Table_Account    // 账户表
};
CurrentTable m_currentTable = Table_None;
```

### 2.3 数据流设计

```
用户操作 → 信号槽触发 → 业务逻辑处理 → QSqlTableModel/QSqlQuery → SQLite数据库
                ↓
           UI自动更新 ← 数据变更通知
```

---

## 三、数据库设计

### 3.1 ER图概念模型

```
┌──────────────┐       ┌──────────────┐       ┌──────────────┐
│   students   │       │   courses    │       │    staff     │
├──────────────┤       ├──────────────┤       ├──────────────┤
│ PK student_id│──┐    │ PK course_id │    ┌─│ PK staff_id  │
│    name      │  │    │    course_name│◄───┤│    name      │
│    class     │  │    │    credit    │    ││ courses_taught│
│    major     │  │    │    hours     │    │└──────────────┘
└──────────────┘  │    │    course_type│   │
                  │    └──────────────┘    │
                  │            │           │
                  │            ▼           │
                  │    ┌──────────────┐    │
                  └───►│    scores    │◄───┘
                       ├──────────────┤
                       │ PK record_id │
                       │ FK student_id│
                       │    student_name│
                       │    course_name │
                       │    score      │
                       └──────────────┘

┌──────────────┐
│   accounts   │
├──────────────┤
│ PK account_id│
│    name      │
│    password  │
│    role      │
└──────────────┘
```

### 3.2 数据表详细结构

#### 3.2.1 学生信息表 (students)

| 字段名 | 类型 | 约束 | 说明 |
|--------|------|------|------|
| student_id | TEXT | PRIMARY KEY | 学号（主键） |
| name | TEXT | NOT NULL | 姓名 |
| class | TEXT | NOT NULL | 班级 |
| major | TEXT | NOT NULL | 专业 |

#### 3.2.2 教职工信息表 (staff)

| 字段名 | 类型 | 约束 | 说明 |
|--------|------|------|------|
| staff_id | TEXT | PRIMARY KEY | 工号（主键） |
| name | TEXT | NOT NULL | 姓名 |
| courses_taught | TEXT | NOT NULL | 授课列表（逗号分隔） |

**设计说明**：`courses_taught` 字段存储教师所教的所有课程名称，使用逗号分隔。例如：`"高等数学,线性代数"`。这种设计简化了多对多关系，适合小规模数据。

#### 3.2.3 课程信息表 (courses)

| 字段名 | 类型 | 约束 | 说明 |
|--------|------|------|------|
| course_id | TEXT | PRIMARY KEY | 课程号（主键） |
| course_name | TEXT | NOT NULL | 课程名称 |
| credit | REAL | NOT NULL | 学分 |
| hours | INTEGER | NOT NULL | 学时 |
| course_type | TEXT | NOT NULL | 课程类型（必修/选修） |

#### 3.2.4 成绩记录表 (scores)

| 字段名 | 类型 | 约束 | 说明 |
|--------|------|------|------|
| record_id | INTEGER | PRIMARY KEY AUTOINCREMENT | 记录ID（自增主键） |
| student_id | TEXT | NOT NULL | 学号 |
| student_name | TEXT | NOT NULL | 学生姓名 |
| course_name | TEXT | NOT NULL | 课程名称 |
| score | INTEGER | NOT NULL | 成绩 |

**设计说明**：成绩表采用冗余设计，同时存储 `student_id` 和 `student_name`，便于查询展示，牺牲部分存储空间换取查询效率。

#### 3.2.5 账户管理表 (accounts)

| 字段名 | 类型 | 约束 | 说明 |
|--------|------|------|------|
| account_id | TEXT | PRIMARY KEY | 账号（主键） |
| name | TEXT | NOT NULL | 用户姓名 |
| password | TEXT | NOT NULL DEFAULT '123456' | 密码 |
| role | TEXT | NOT NULL CHECK(role IN ('student', 'teacher', 'admin')) | 角色 |

**设计说明**：使用 `CHECK` 约束限制角色只能是三种之一，默认密码为 `123456`。

---

## 四、功能模块详解

### 4.1 程序入口模块 (main.cpp)

#### 4.1.1 功能概述
程序入口负责数据库连接初始化、登录流程控制、角色路由分发。

#### 4.1.2 核心实现

```cpp
// main.cpp:20-26 - 数据库连接
QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
db.setDatabaseName("table.db");  // 数据库文件需与exe同目录
if(!db.open()) {
    QMessageBox::critical(nullptr, "错误", "连不上数据库：" + db.lastError().text());
    return 0;
}
```

```cpp
// main.cpp:35-50 - 角色路由分发
if(jump == "student") {
    student studentWindow(id);    // 传入学生学号
    studentWindow.exec();
} else if(jump == "admin") {
    admin adminWindow();
    adminWindow.exec();
} else if(jump == "teacher") {
    teacher teacherWindow(id);    // 传入教师工号
    teacherWindow.exec();
}
```

#### 4.1.3 设计要点
- 使用 `QSqlDatabase::database()` 获取全局数据库连接，避免重复创建
- 登录窗口返回角色和账号，主函数根据角色实例化对应窗口
- 学生和教师窗口需要传入用户ID，用于后续数据过滤

---

### 4.2 登录模块 (login)

#### 4.2.1 文件结构
- `login.h` / `login.cpp` / `login.ui`

#### 4.2.2 功能流程

```
用户输入账号密码 → 点击登录 → 数据库验证 → 成功则记录角色/账号 → 关闭窗口
                                    ↓
                              失败则提示错误
```

#### 4.2.3 核心代码实现

```cpp
// login.cpp:17-46 - 登录验证逻辑
void login::on_login_2_clicked()
{
    QString account = ui->account->text();
    QString password = ui->password->text();
    Account = account;  // 保存账号
    
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query(db);
    // SQL查询：根据账号获取密码和角色
    QString sql = QString("SELECT password, role FROM accounts WHERE account_id = '%1'").arg(account);
    query.exec(sql);
    
    if (query.next()) {
        QString dbPassword = query.value(0).toString();
        QString dbRole = query.value(1).toString();
        if(dbPassword == password) {
            Role = dbRole;  // 保存角色
            this->accept(); // 关闭对话框，返回 QDialog::Accepted
        } else {
            QMessageBox::warning(this, "错误", "账号或密码错误");
        }
    } else {
        QMessageBox::warning(this, "错误", "账号或密码错误");
    }
}
```

#### 4.2.4 接口设计

```cpp
// login.h:25-26 - 对外接口
QString getRole();     // 返回登录用户角色
QString getAccount();  // 返回登录用户账号
```

---

### 4.3 注册模块 (reg)

#### 4.3.1 文件结构
- `loginwindowsH/reg.h` / `loginwindowsCPP/reg.cpp` / `loginwindowsUI/reg.ui`

#### 4.3.2 功能流程

```
选择角色 → 输入账号/密码/姓名 → 检测账号是否存在 → 写入数据库 → 注册成功
```

#### 4.3.3 核心代码实现

```cpp
// reg.cpp:20-67 - 注册逻辑
void reg::on_submit_clicked()
{
    QString account = ui->account->text();
    QString password = ui->password->text();
    QString name = ui->name->text();
    QString role = ui->id->currentData().toString();  // 从下拉框获取角色
    
    // 输入验证
    if(account.isEmpty()) {
        QMessageBox::warning(this, "提示", "账号不能为空！");
        return;
    }
    
    // 检测账号是否已存在
    QSqlQuery checkQuery(db);
    QString checkSql = QString("SELECT account_id FROM accounts WHERE account_id = '%1'").arg(account);
    checkQuery.exec(checkSql);
    
    if(!checkQuery.next()) {
        // 账号不存在，执行插入
        QString insertSql = QString("INSERT INTO accounts (account_id, password, name, role) "
                                    "VALUES ('%1', '%2', '%3', '%4')").arg(account).arg(password).arg(name).arg(role);
        if(insertQuery.exec(insertSql)) {
            QMessageBox::information(this, "成功", "注册成功！");
            this->accept();
        }
    } else {
        QMessageBox::warning(this, "提示", "该账号已被注册，请换一个账号！");
    }
}
```

#### 4.3.4 角色选择下拉框初始化

```cpp
// reg.cpp:10-12 - 下拉框配置
ui->id->addItem("学生", "student");
ui->id->addItem("教师", "teacher");
ui->id->addItem("管理员", "admin");
```

---

### 4.4 管理员模块 (admin)

#### 4.4.1 文件结构
- `admin.h` / `admin.cpp` / `admin.ui`
- 编辑对话框：`adminwindowsH/` 和 `adminwindowsCPP/` 目录下

#### 4.4.2 功能架构

```
┌─────────────────────────────────────────────────────────────┐
│                      管理员主界面                            │
├─────────────┬───────────────────────────────────────────────┤
│  功能按钮区  │              数据展示区 (QTableView)           │
│ ─────────── │ ───────────────────────────────────────────── │
│ [学生管理]   │    ┌─────────────────────────────────────┐   │
│ [教师管理]   │    │  QSqlTableModel 数据绑定            │   │
│ [课程管理]   │    │  自动显示当前表的所有记录            │   │
│ [成绩管理]   │    │  支持选中行操作                      │   │
│ [账户管理]   │    └─────────────────────────────────────┘   │
│ ─────────── │                                              │
│ [新建]       │                                              │
│ [修改]       │                                              │
│ [删除]       │                                              │
│ [刷新]       │                                              │
└─────────────┴───────────────────────────────────────────────┘
```

#### 4.4.3 表切换实现

```cpp
// admin.cpp:22-55 - 表切换逻辑
void admin::on_student_clicked()
{
    m_model->setTable("students");  // 切换到学生表
    m_model->select();              // 加载数据
    m_currentTable = Table_Student; // 更新状态
}

void admin::on_teacher_clicked()
{
    m_model->setTable("staff");
    m_model->select();
    m_currentTable = Table_Teacher;
}
// ... 其他表类似
```

#### 4.4.4 新建记录实现

```cpp
// admin.cpp:58-115 - 新建记录
void admin::on_create_clicked()
{
    if(m_currentTable == Table_None) {
        QMessageBox::warning(this, "提示", "请先在左侧选择要操作的表！");
        return;
    }
    
    QStringList newData;
    // 根据当前表类型弹出对应对话框
    if(m_currentTable == Table_Student) {
        studenteditdialog dlg(true, this);  // true表示新建模式
        if(dlg.exec() == QDialog::Accepted) {
            newData = dlg.getData();
        }
    }
    // ... 其他表类似
    
    if(newData.isEmpty()) return;
    
    // 插入新行
    int newRow = m_model->rowCount();
    m_model->insertRow(newRow);
    for(int i = 0; i < newData.size(); i++) {
        m_model->setData(m_model->index(newRow, i), newData[i]);
    }
    
    // 提交到数据库
    if(m_model->submitAll()) {
        QMessageBox::information(this, "成功", "新建数据成功！");
    } else {
        QMessageBox::critical(this, "失败", "新建失败：" + m_model->lastError().text());
        m_model->revertAll();  // 回滚
    }
}
```

#### 4.4.5 修改记录实现

```cpp
// admin.cpp:117-175 - 修改记录
void admin::on_modify_clicked()
{
    int curRow = ui->tableView->currentIndex().row();
    if(curRow < 0) {
        QMessageBox::warning(this, "提示", "请先选中一行！");
        return;
    }
    
    // 读取当前行数据
    QStringList oldData;
    for(int i = 0; i < m_model->columnCount(); i++) {
        oldData << m_model->data(m_model->index(curRow, i)).toString();
    }
    
    // 弹出编辑对话框
    QStringList newData;
    if(m_currentTable == Table_Student) {
        studenteditdialog dlg(false, this);  // false表示修改模式
        dlg.setData(oldData);  // 预填充旧数据
        if(dlg.exec() == QDialog::Accepted) {
            newData = dlg.getData();
        }
    }
    // ... 其他表类似
    
    // 更新数据
    for(int i = 0; i < newData.size(); i++) {
        m_model->setData(m_model->index(curRow, i), newData[i]);
    }
    
    if(m_model->submitAll()) {
        QMessageBox::information(this, "成功", "修改成功！");
    }
}
```

#### 4.4.6 编辑对话框设计

所有编辑对话框采用统一的设计模式：

```cpp
// 以 studenteditdialog 为例
class studenteditdialog : public QDialog
{
public:
    studenteditdialog(bool isNew, QWidget *parent = nullptr);
    QStringList getData();              // 获取表单数据
    void setData(const QStringList &data);  // 设置表单数据（修改时预填充）

private:
    bool m_isNew;  // 区分新建/修改模式
};

// 构造函数中根据模式设置UI
studenteditdialog::studenteditdialog(bool isNew, QWidget *parent) : m_isNew(isNew)
{
    if(!m_isNew) {
        ui->sno->setReadOnly(true);  // 修改模式下主键不可编辑
        ui->sno->setStyleSheet("background-color: #E0E0E0;");  // 灰色背景提示
    }
}
```

---

### 4.5 学生模块 (student)

#### 4.5.1 文件结构
- `student.h` / `student.cpp` / `student.ui`
- 选课对话框：`studentwindowsH/selectcourse.h` / `studentwindowsCPP/selectcourse.cpp`

#### 4.5.2 功能架构

```
┌─────────────────────────────────────────────────────────────┐
│                      学生主界面                              │
├─────────────┬───────────────────────────────────────────────┤
│  功能按钮区  │              数据展示区 (QTableView)           │
│ ─────────── │ ───────────────────────────────────────────── │
│ [查看成绩]   │    显示当前登录学生的个人成绩                   │
│ [选课]       │    （按学生姓名过滤 scores 表）                │
│ [统计学分]   │                                              │
│ [刷新]       │                                              │
└─────────────┴───────────────────────────────────────────────┘
```

#### 4.5.3 构造函数 - 接收学生ID

```cpp
// student.cpp:4-17 - 构造函数
student::student(QString id, QWidget *parent)
    : QDialog(parent), m_studentId(id)  // 保存登录时传入的学号
{
    ui->setupUi(this);
    this->setWindowTitle("学生界面");
    
    QSqlDatabase db = QSqlDatabase::database();
    m_model = new QSqlTableModel(this, db);
    ui->tableView->setModel(m_model);
    
    // 禁止编辑（学生只能查看，不能直接修改表格）
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}
```

#### 4.5.4 查看个人成绩

```cpp
// student.cpp:41-53 - 按姓名过滤成绩
void student::on_watch_clicked()
{
    // 先根据学号查询学生姓名
    QSqlQuery query(db);
    query.prepare("SELECT name FROM students WHERE student_id = ?");
    query.addBindValue(m_studentId);
    query.exec();
    query.next();
    QString studentName = query.value("name").toString();
    
    // 设置过滤器，只显示该学生的成绩
    m_model->setTable("scores");
    m_model->setFilter(QString("student_name = '%1'").arg(studentName));
    m_model->select();
}
```

#### 4.5.5 学分统计

```cpp
// student.cpp:56-94 - 统计已获得学分
void student::on_count_clicked()
{
    if (m_model->tableName() != "scores") {
        QMessageBox::information(this, "提示", "请先点击「查看成绩」后再统计总学分！");
        return;
    }
    
    double totalCredit = 0.0;
    int courseNameCol = m_model->fieldIndex("course_name");
    int scoreCol = m_model->fieldIndex("score");
    
    for (int i = 0; i < m_model->rowCount(); ++i) {
        QString courseName = m_model->index(i, courseNameCol).data().toString();
        double score = m_model->index(i, scoreCol).data().toDouble();
        
        // 只有成绩 >= 60 分才计入学分
        if (score < 60) continue;
        
        // 查询该课程的学分
        QSqlQuery query(db);
        query.prepare("SELECT credit FROM courses WHERE course_name = ?");
        query.addBindValue(courseName);
        if (query.exec() && query.next()) {
            totalCredit += query.value("credit").toDouble();
        }
    }
    
    QMessageBox::information(this, "总学分统计", 
        QString("您已获得的总学分：%1 分").arg(totalCredit, 0, 'f', 1));
}
```

#### 4.5.6 选课模块 (selectcourse)

**功能流程**：
```
打开选课窗口 → 加载所有课程 → 高亮已选课程 → 用户勾选/取消 → 计算差异 → 批量更新数据库
```

**核心实现**：

```cpp
// selectcourse.cpp:11-48 - 初始化：加载课程并高亮已选
selectcourse::selectcourse(QString studentId, QString studentName, QWidget *parent)
    : m_studentId(studentId), m_studentName(studentName)
{
    // 加载所有课程
    m_model->setQuery("SELECT course_id, course_name, credit, hours, course_type FROM courses", db);
    
    // 查询已选课程
    QSqlQuery query(db);
    query.prepare("SELECT course_name FROM scores WHERE student_id = ?");
    query.addBindValue(m_studentId);
    if (query.exec()) {
        while (query.next()) {
            m_alreadySelected.insert(query.value("course_name").toString());
        }
    }
    
    // 高亮已选课程
    QItemSelectionModel *selModel = ui->tableView->selectionModel();
    for (int i = 0; i < m_model->rowCount(); ++i) {
        QString courseName = m_model->index(i, courseNameCol).data().toString();
        if (m_alreadySelected.contains(courseName)) {
            selModel->select(m_model->index(i, 0), QItemSelectionModel::Select | QItemSelectionModel::Rows);
        }
    }
}
```

```cpp
// selectcourse.cpp:55-109 - 确认选课：计算差异并批量更新
void selectcourse::on_confirm_clicked()
{
    // 获取当前选中的课程
    QModelIndexList selectedRows = ui->tableView->selectionModel()->selectedRows();
    QSet<QString> currentSelected;
    for (const QModelIndex &index : selectedRows) {
        currentSelected.insert(m_model->index(index.row(), courseNameCol).data().toString());
    }
    
    db.transaction();  // 开启事务
    
    // 退课：原来选了但现在没选的
    for (const QString &courseName : m_alreadySelected) {
        if (!currentSelected.contains(courseName)) {
            query.prepare("DELETE FROM scores WHERE student_id = ? AND course_name = ?");
            query.addBindValue(m_studentId);
            query.addBindValue(courseName);
            if (query.exec()) deleteCount++;
        }
    }
    
    // 选课：现在选了但原来没选的
    for (const QString &courseName : currentSelected) {
        if (!m_alreadySelected.contains(courseName)) {
            query.prepare("INSERT INTO scores (student_id, student_name, course_name, score) VALUES (?, ?, ?, 0)");
            query.addBindValue(m_studentId);
            query.addBindValue(m_studentName);
            query.addBindValue(courseName);
            if (query.exec()) insertCount++;
        }
    }
    
    if (db.commit()) {
        QMessageBox::information(this, "成功", 
            QString("操作成功！新增 %1 门课，退选 %2 门课。").arg(insertCount).arg(deleteCount));
    } else {
        db.rollback();
    }
}
```

---

### 4.6 教师模块 (teacher)

#### 4.6.1 文件结构
- `teacher.h` / `teacher.cpp` / `teacher.ui`
- 成绩修改对话框：`teacherwindowsH/modifyscore.h` / `teacherwindowsCPP/modifyscore.cpp`

#### 4.6.2 功能架构

```
┌─────────────────────────────────────────────────────────────┐
│                      教师主界面                              │
├─────────────┬───────────────────────────────────────────────┤
│  功能按钮区  │              数据展示区 (QTableView)           │
│ ─────────── │ ───────────────────────────────────────────── │
│ [我的课程]   │    显示教师所教授的所有课程                    │
│ [查看详情]   │    点击课程后显示选课学生及成绩                │
│ [修改成绩]   │                                              │
│ [成绩分析]   │    [搜索框] 实时搜索学生                      │
│ [成绩排序]   │                                              │
│ [刷新]       │                                              │
└─────────────┴───────────────────────────────────────────────┘
```

#### 4.6.3 加载教师授课信息

```cpp
// teacher.cpp:150-160 - 从数据库加载教师所教课程
void teacher::loadTeacherInfo()
{
    QSqlQuery query(db);
    query.prepare("SELECT courses_taught FROM staff WHERE staff_id = ?");
    query.addBindValue(m_staffId);
    if(query.exec() && query.next()) {
        QString longStringFromDB = query.value("courses_taught").toString();
        // 将逗号分隔的字符串转为列表
        m_teachCourses = longStringFromDB.split(",", Qt::SkipEmptyParts);
    }
}
```

#### 4.6.4 查看所教课程

```cpp
// teacher.cpp:24-34 - 显示教师所教的所有课程
void teacher::on_student_clicked()
{
    if(m_teachCourses.isEmpty()) {
        QMessageBox::warning(this, "提示", "没找到您的授课信息！");
        return;
    }
    m_model->setTable("courses");
    // 使用 IN 子句过滤
    QString filter = QString("course_name IN ('%1')").arg(m_teachCourses.join("','"));
    m_model->setFilter(filter);
    m_model->select();
}
```

#### 4.6.5 查看课程详情（选课学生）

```cpp
// teacher.cpp:163-177 - 查看选中课程的学生成绩
void teacher::on_moreinf_clicked()
{
    QModelIndex index = ui->tableView->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "提示", "请先选中一门课程！");
        return;
    }
    
    // 获取选中的课程名
    QString courseName = m_model->index(index.row(), courseNameCol).data().toString();
    
    // 切换到成绩表，按课程名过滤
    m_model->setTable("scores");
    QString courseFilter = QString("course_name = '%1'").arg(courseName);
    m_model->setFilter(courseFilter);
    m_model->select();
    m_currentCourseFilter = courseFilter;  // 保存当前过滤条件
}
```

#### 4.6.6 成绩统计分析

```cpp
// teacher.cpp:74-129 - 计算平均分、标准差、及格率
void teacher::on_analysis_clicked()
{
    if (m_model->tableName() != "scores") {
        QMessageBox::information(this, "提示", "请先进入课程详情页再进行成绩分析！");
        return;
    }
    
    QList<double> scores;
    int passCount = 0;
    int totalCount = m_model->rowCount();
    
    // 收集所有成绩
    for (int i = 0; i < totalCount; ++i) {
        double score = m_model->index(i, scoreCol).data().toDouble();
        scores.append(score);
        if (score >= 60) passCount++;
    }
    
    // 计算平均分
    double sum = 0;
    for (double s : scores) sum += s;
    double average = sum / scores.size();
    
    // 计算标准差
    double varianceSum = 0;
    for (double s : scores) {
        varianceSum += (s - average) * (s - average);
    }
    double stdDev = qSqrt(varianceSum / scores.size());
    
    // 计算及格率
    double passRate = (static_cast<double>(passCount) / scores.size()) * 100;
    
    QMessageBox::information(this, "成绩分析", 
        QString("总人数：%1 人\n平均分：%2 分\n标准差：%3 分\n及格率：%4 %%")
        .arg(scores.size()).arg(average, 0, 'f', 2).arg(stdDev, 0, 'f', 2).arg(passRate, 0, 'f', 2));
}
```

#### 4.6.7 实时搜索功能

```cpp
// teacher.cpp:179-201 - 按学号或姓名模糊搜索
void teacher::dosearch()
{
    if (m_model->tableName() != "scores") return;
    
    QString key = ui->search->text();
    QString finalFilter;
    
    if (key.isEmpty()) {
        finalFilter = m_currentCourseFilter;  // 恢复原始过滤
    } else {
        // 组合条件：课程名匹配 AND (学号或姓名模糊匹配)
        QString searchCond = QString("(student_id LIKE '%%1%' OR student_name LIKE '%%1%')").arg(key);
        finalFilter = QString("%1 AND %2").arg(m_currentCourseFilter, searchCond);
    }
    
    m_model->setFilter(finalFilter);
    m_model->select();
}
```

**信号槽连接**（在构造函数中）：
```cpp
// teacher.cpp:16 - 文本变化时自动触发搜索
connect(ui->search, &QLineEdit::textChanged, this, &teacher::dosearch);
```

---

## 五、项目结构

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

---

## 六、数据库初始化脚本 (CreateTable.py)

### 6.1 脚本功能

Python 脚本 `CreateTable.py` 负责从文本文件导入初始数据到 SQLite 数据库。

### 6.2 配置项

```python
# CreateTable.py:5-19 - 配置项
DB_FILE = "build/Desktop_Qt_6_10_1_MinGW_64_bit-Debug/debug/table.db"
DATA_FOLDER = "module_project2"
FILE_ENCODING = "gbk"        # 文件编码
OVERWRITE_MODE = True        # True=覆盖重建，False=追加
```

### 6.3 数据导入流程

```
1. 创建数据库连接
2. 执行 CREATE TABLE 语句（5张表）
3. 按依赖顺序导入数据：
   - students（学生表）
   - courses（课程表）
   - staff（教职工表）
   - scores（成绩表）
   - accounts（账户表，从students和staff自动生成）
4. 提交事务
```

### 6.4 账户自动生成逻辑

```python
# CreateTable.py:187-206 - 自动生成账户
def import_accounts(cursor):
    # 1. 从学生表生成学生账户
    cursor.execute("SELECT student_id, name FROM students")
    students = cursor.fetchall()
    student_accounts = [(sid, name, "123456", "student") for sid, name in students]
    cursor.executemany("INSERT OR IGNORE INTO accounts VALUES (?,?,?,?)", student_accounts)
    
    # 2. 从教职工表生成教师账户
    cursor.execute("SELECT staff_id, name FROM staff")
    staffs = cursor.fetchall()
    staff_accounts = [(sid, name, "123456", "teacher") for sid, name in staffs]
    cursor.executemany("INSERT OR IGNORE INTO accounts VALUES (?,?,?,?)", staff_accounts)
    
    # 3. 添加默认管理员账户
    admin_account = ("admin", "System Admin", "123456", "admin")
    cursor.execute("INSERT OR IGNORE INTO accounts VALUES (?,?,?,?)", admin_account)
```

---

## 七、编译运行指南

### 7.1 环境要求

- Qt 6.10.1 或更高版本
- MinGW 64-bit 编译器
- C++17 支持
- Python 3.x（用于数据库初始化）

### 7.2 编译步骤

1. 打开 Qt Creator
2. 打开 `MyStudentManager.pro` 项目文件
3. 执行 qmake（右键项目 → 执行 qmake）
4. 构建项目（Ctrl+B）
5. 运行程序（Ctrl+R）

### 7.3 数据库初始化

```bash
# 在项目根目录执行
python CreateTable.py
```

脚本会自动创建 `table.db` 数据库文件并导入初始数据。

### 7.4 默认账户

| 账号 | 密码 | 角色 |
|------|------|------|
| admin | 123456 | 管理员 |
| (学生学号) | 123456 | 学生 |
| (教师工号) | 123456 | 教师 |

---

## 八、使用说明

### 8.1 管理员操作流程

1. 使用 `admin/123456` 登录
2. 点击左侧按钮选择要管理的表
3. 点击「新建」添加记录
4. 选中行后点击「修改」编辑记录
5. 选中行后点击「删除」删除记录
6. 点击「刷新」重新加载数据

### 8.2 学生操作流程

1. 使用学号和默认密码 `123456` 登录
2. 点击「查看成绩」查看个人成绩
3. 点击「选课」进入选课中心，勾选/取消课程
4. 点击「统计学分」查看已获得总学分（仅统计及格课程）

### 8.3 教师操作流程

1. 使用工号和默认密码 `123456` 登录
2. 点击「我的课程」查看所教课程列表
3. 选中课程后点击「查看详情」查看选课学生及成绩
4. 选中学生后点击「修改成绩」录入/修改成绩
5. 点击「成绩分析」查看统计报告
6. 点击「成绩排序」按成绩降序排列
7. 在搜索框输入学号或姓名实时搜索

---

## 九、注意事项

1. **数据库文件位置**：`table.db` 需要与可执行文件放在同一目录
2. **修改 .pro 文件后**：需要重新执行 qmake
3. **编码问题**：数据文件使用 GBK 编码，如有乱码请检查编码设置
4. **主键约束**：修改模式下主键字段不可编辑（灰色背景提示）
5. **成绩默认值**：新选课程成绩默认为 0 分

---

## 十、扩展建议

1. **密码加密**：当前密码明文存储，建议使用 MD5 或 SHA256 加密
2. **数据验证**：添加成绩范围验证（0-100）、学号格式验证等
3. **日志记录**：添加操作日志，记录谁在何时修改了什么数据
4. **数据备份**：添加数据库备份和恢复功能
5. **批量导入**：支持 Excel/CSV 批量导入学生和成绩数据
