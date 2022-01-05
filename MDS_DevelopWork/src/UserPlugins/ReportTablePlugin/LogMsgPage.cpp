#include "LogMsgPage.h"
#include "LogPageWidget.h"
#include "LogQueryDialog.h"
#include "SqlLogMsgManager.h"
#include "ui_LogMsgPage.h"
#include <QDateTime>
#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#define DISPLAY_TIME_FORMAT "yyyy-MM-dd HH:mm:ss"
const int MAX_INSERT_NUM = 1000;

LogMsgPage::LogMsgPage(QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::LogMsgPage)
{
    ui->setupUi(this);
    m_queryDialog = new LogQueryDialog();

    m_sqlLogMsgManager = new SqlLogMsgManager();
    //    connect(m_queryDialog, &QueryDialog::search, this, &LogMsgPage::searchSlot);
    m_queryDialog->setWindowModality(Qt::ApplicationModal);  // motai

    initMember();
    initView();
    setArrayDataInterface();
}

LogMsgPage::~LogMsgPage() { delete ui; }

void LogMsgPage::queryBtnClicked() { m_queryDialog->show(); }

void LogMsgPage::exportStatus()
{
    QString filename = QFileDialog::getSaveFileName(this, tr("导出状态历史数据"));
    if (filename.isEmpty())
    {
        QMessageBox::critical(this, "提示", "文件打开失败", "确定");
        return;
    }

    QMessageBox mb(QMessageBox::Information, tr("保存状态历史数据"), filename, QMessageBox::Ok | QMessageBox::Close);
    if (mb.exec() == QMessageBox::Ok)
    {
        processExport(filename);
    }
}

void LogMsgPage::searchSlot(const QStringList& taskName, const QStringList& taskNum, const QStringList& fileName, const QStringList& outputType,
                            const QDateTime& start_time, const QDateTime& end_time)
{
}

void LogMsgPage::slotUpdataTable() { ui->tableView->reset(); }
void LogMsgPage::processExport(const QString& fileName)
{
    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::critical(this, "提示", "文件创建失败", "确定");
        return;
    }
    uchar bom[] = { 0xef, 0xbb, 0xbf };
    file.write(reinterpret_cast<char*>(bom), sizeof(bom));

    QTextStream stream(&file);
    stream.setCodec("UTF-8");
    auto status_lists = m_pageNavigator->m_pDataModel->GetArrayData();

    for (auto status : status_lists)
    {
        stream << QString("日期:").toUtf8() << status.dateTime << QString("     ").toUtf8() << QString("分系统名称:").toUtf8()
               << status.systemName.toUtf8() << QString("     ").toUtf8() << QString("任务编号").toUtf8() << status.taskNum.toUtf8()
               << QString("     ").toUtf8() << QString("故障信息").toUtf8() << status.logMsg.toUtf8() << QString("     ").toUtf8()
               << QString("日志属性").toUtf8() << status.logProperty.toUtf8() << QString("     ").toUtf8() << '\n';
    }
    file.close();
}

void LogMsgPage::allBtnClicked()
{
    QFile file("data/style/MainManager.qss");
    if (file.open(QFile::ReadOnly))
    {
        QString styleSheet = QLatin1String(file.readAll());

        ui->allBtn->setStyleSheet(styleSheet);
        file.close();
    }
}

void LogMsgPage::initMember()
{
    m_pageNavigator = new LogPageWidget();
    ui->widget->layout()->addWidget(m_pageNavigator);
    ui->tableView->setModel(m_pageNavigator->m_pDataModel);
    //更新表格
    connect(m_pageNavigator, &LogPageWidget::updataTableView, this, &LogMsgPage::slotUpdataTable);

    connect(ui->allBtn, &QPushButton::clicked, this, &LogMsgPage::allBtnClicked);
    connect(ui->queryBtn, &QPushButton::clicked, this, &LogMsgPage::queryBtnClicked);
    connect(ui->reportBtn, &QPushButton::clicked, this, &LogMsgPage::exportStatus);
}

void LogMsgPage::setArrayDataInterface()
{
    LogMsgData data;
    LogMsgDataList DATA;

    QDateTime time = QDateTime::currentDateTime();

    for (int i = 1; i < 101; i++)
    {
        data.dateTime = time.toString(DISPLAY_TIME_FORMAT);
        data.systemName = "探测仪图像定位";
        data.taskNum = "GTNXXXXXX" + QString::number(i);
        data.logMsg = "GTNXXmsg";
        data.logProperty = "信息";
        DATA.append(data);
    }
    m_sqlLogMsgManager->insert(DATA);
    m_pageNavigator->m_pDataModel->SetArrayData(DATA);
    m_pageNavigator->m_pDataModel->SetPageSize(20);
    m_pageNavigator->UpdateStatus();
}
void LogMsgPage::initView()
{
    ui->tableView->setShowGrid(false);
    //    ui->tableView->horizontalHeader()->setVisible(false);  // 水平不可见
    ui->tableView->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->tableView->viewport()->installEventFilter(this);
    ui->tableView->viewport()->setMouseTracking(true);
    ui->tableView->verticalHeader()->setVisible(false);  // 垂直不可见
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->horizontalHeader()->setDefaultAlignment(Qt::AlignVCenter);
    ui->tableView->setEditTriggers(QAbstractItemView::DoubleClicked);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);  //设置选中模式为选中行
}
QString LogMsgPage::pasraDoubleToStr(double value, int prsc, char f) { return QString::number(value, f, prsc); }
