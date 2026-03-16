#include "teacher.h"
#include "ui_teacher.h"
#include <QFile>
#include <QStyledItemDelegate>
#include <QPainter>

class CenteredDelegate : public QStyledItemDelegate {
public:
    using QStyledItemDelegate::QStyledItemDelegate;
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override {
        QStyleOptionViewItem opt = option;
        opt.displayAlignment = Qt::AlignCenter;
        QStyledItemDelegate::paint(painter, opt, index);
    }
};

teacher::teacher(QString staffId, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::teacher)
    , m_staffId(staffId)
{
    ui->setupUi(this);
    this->setWindowTitle("教师界面");

    QFile file(":/styles/teacher.qss");
    if (file.open(QFile::ReadOnly | QFile::Text)) {
        this->setStyleSheet(QString::fromUtf8(file.readAll()));
        file.close();
    }

    QSqlDatabase db = QSqlDatabase::database();
    m_model = new QSqlTableModel(this, db);
    ui->tableView->setModel(m_model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->horizontalHeader()->setDefaultSectionSize(120);
    ui->tableView->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->tableView->verticalHeader()->setDefaultSectionSize(40);
    ui->tableView->setWordWrap(false);
    ui->tableView->setTextElideMode(Qt::ElideRight);
    ui->tableView->setItemDelegate(new CenteredDelegate(this));
    loadTeacherInfo();
    connect(ui->search, &QLineEdit::textChanged, this, &teacher::dosearch);
    ui->tableView->setMouseTracking(true);
    connect(ui->tableView, &QTableView::entered, this, &teacher::showCellTooltip);
}

teacher::~teacher()
{
    delete ui;
}

void teacher::on_student_clicked()
{
    if(m_teachCourses.isEmpty()){
        QMessageBox::warning(this, "提示", "没找到您的授课信息！");
        return;
    }
    m_model->setTable("courses");
    QString filter = QString("course_name IN ('%1')").arg(m_teachCourses.join("','"));
    m_model->setFilter(filter);
    m_model->select();
}


void teacher::on_modify_clicked()
{
    if (m_model->tableName() != "scores") {
        QMessageBox::information(this, "提示", "请先进入课程详情页再修改成绩！");
        return;
    }

    QModelIndex index = ui->tableView->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "提示", "请先选中要修改成绩的学生行！");
        return;
    }

    int scoreCol = m_model->fieldIndex("score");
    QModelIndex scoreIndex = m_model->index(index.row(), scoreCol);
    double currentScore = scoreIndex.data().toDouble();
    modifyscore dlg(this);
    dlg.setInitScore(currentScore);

    if (dlg.exec() == QDialog::Accepted) {
        double newScore = dlg.getnewscore(); // 获取新成绩

        if (m_model->setData(scoreIndex, newScore))
        {
            if (m_model->submitAll())
            {
                QMessageBox::information(this, "成功", "成绩修改成功！");
            }
            else
            {
                QMessageBox::critical(this, "错误", "保存失败");
                m_model->revertAll();
            }
        }
    }
}

void teacher::on_analysis_clicked()
{
    if (m_model->tableName() != "scores") {
        QMessageBox::information(this, "提示", "请先进入课程详情页再进行成绩分析！");
        return;
    }

    int scoreCol = m_model->fieldIndex("score");
    QList<double> scores;
    int passCount = 0; // 及格人数
    int totalCount = m_model->rowCount();
    for (int i = 0; i < totalCount; ++i) {
        QModelIndex index = m_model->index(i, scoreCol);
        bool ok;
        double score = index.data().toDouble(&ok);
        if (ok) {
            scores.append(score);
            if (score >= 60) {
                passCount++;
            }
        }
    }

    if (scores.isEmpty()) {
        QMessageBox::information(this, "提示", "没有有效的成绩数据！");
        return;
    }

    double sum = 0;
    for (double s : scores) {
        sum += s;
    }
    double average = sum / scores.size();

    double varianceSum = 0;
    for (double s : scores) {
        varianceSum += (s - average) * (s - average);
    }
    double variance = varianceSum / scores.size();
    double stdDev = qSqrt(variance);

    double passRate = (static_cast<double>(passCount) / scores.size()) * 100;
    QString result = QString(
                         "成绩分析报告\n"
                         "——————————————\n"
                         "总人数：%1 人\n"
                         "平均分：%2 分\n"
                         "标准差：%3 分\n"
                         "及格率：%4 %%\n"
                         "——————————————"
                         ).arg(scores.size())
                         .arg(average, 0, 'f', 2) // 保留2位小数
                         .arg(stdDev, 0, 'f', 2)
                         .arg(passRate, 0, 'f', 2);
    QMessageBox::information(this, "成绩分析", result);
}

void teacher::on_refresh_clicked()
{
    m_model->select();
    QMessageBox::information(this, "提示", "数据刷新成功！");
}


void teacher::on_sort_clicked()
{
    if (m_model->tableName() != "scores") {
        QMessageBox::information(this, "提示", "请先进入课程详情页再排序！");
        return;
    }

    int scoreCol = m_model->fieldIndex("score");
    m_model->setSort(scoreCol, Qt::DescendingOrder);
    m_model->select();
}

void teacher::loadTeacherInfo()
{
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query(db);
    query.prepare("SELECT courses_taught FROM staff WHERE staff_id = ?");
    query.addBindValue(m_staffId); // 用你登录时传进来的工号过滤
    if(query.exec() && query.next()){
        QString longStringFromDB = query.value("courses_taught").toString();
        m_teachCourses = longStringFromDB.split(",", Qt::SkipEmptyParts);
    }
}


void teacher::on_moreinf_clicked()
{
    QModelIndex index = ui->tableView->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "提示", "请先选中一门课程！");
        return;
    }
    int courseNameCol = m_model->fieldIndex("course_name");
    QString courseName = m_model->index(index.row(), courseNameCol).data().toString();
    m_model->setTable("scores");
    QString courseFilter = QString("course_name = '%1'").arg(courseName);
    m_model->setFilter(courseFilter); // 按课程名过滤
    m_model->select();
    m_currentCourseFilter = courseFilter;
}

void teacher::dosearch()
{
    if (m_model->tableName() != "scores") {
        QMessageBox::information(this, "提示", "请先进入课程详情页再排序！");
        return;
    }

    QString key = ui->search->text();
    QString courseFilter = m_model->filter();
    QString finalFilter;
    if (key.isEmpty())
    {
        finalFilter = m_currentCourseFilter;
    }
    else
    {
        QString searchCond = QString("(student_id LIKE '%%1%' OR student_name LIKE '%%1%')").arg(key);
        finalFilter = QString("%1 AND %2").arg(m_currentCourseFilter, searchCond);
    }

    m_model->setFilter(finalFilter);
    m_model->select();
}

void teacher::showCellTooltip(const QModelIndex &index)
{
    if (!index.isValid()) return;
    QString text = m_model->data(index).toString();
    ui->tableView->setToolTip(text);
}
