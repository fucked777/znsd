#include "LoadFilePage.h"
#include "LoadFilePageWidget.h"
#include "SqlLoadFileManager.h"
#include "ui_LoadFilePage.h"
#include <QDateTime>
#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
LoadFilePage::LoadFilePage(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::LoadFilePage)
{
    ui->setupUi(this);
    m_sqlLoadFileManager = new SqlLoadFileManager();
    initMember();
    initView();
    setArrayDataInterface();
}

LoadFilePage::~LoadFilePage() { delete ui; }

void LoadFilePage::exportStatus()
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

void LoadFilePage::processExport(const QString& fileName)
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
        stream << QString("载荷名称:").toUtf8() << status.loadName << QString("     ").toUtf8() << QString("任务编号:").toUtf8()
               << status.taskNum.toUtf8() << QString("     ").toUtf8() << QString("任务状态").toUtf8() << status.taskStatus.toUtf8()
               << QString("     ").toUtf8() << QString("任务实际执行时间").toUtf8() << status.taskActualExetime.toUtf8() << QString("     ").toUtf8()
               << QString("l0第一行到达时间").toUtf8() << status.l0FirstArrivaltime.toUtf8() << QString("     ").toUtf8()
               << QString("l0最后一行到达时间:").toUtf8() << status.l0LastArrivaltime << QString("     ").toUtf8()
               << QString("实际收到l0总数:").toUtf8() << status.L0ActualReceiveNum << QString("     ").toUtf8() << QString("获取l0总时间:").toUtf8()
               << status.getL0Alltime << QString("     ").toUtf8() << QString("生成l1A第一行时间:").toUtf8() << status.l1AFirsttime
               << QString("     ").toUtf8() << QString("l1A最后一个文件时间:").toUtf8() << status.l1ALasttime << QString("     ").toUtf8()
               << QString("生成l1A总数:").toUtf8() << status.l1ANum << QString("     ").toUtf8() << QString("l1A生成总时间:").toUtf8()
               << status.l1A_Alltime << QString("     ").toUtf8()

               << '\n';
    }
    file.close();
}

void LoadFilePage::queryBtnClicked() {}

void LoadFilePage::searchSlot(const QStringList& taskName, const QStringList& taskNum, const QStringList& fileName, const QStringList& outputType,
                              const QDateTime& start_time, const QDateTime& end_time)
{
}
void LoadFilePage::slotUpdataTable() { ui->tableView->reset(); }
void LoadFilePage::initMember()
{
    ui->comboBox->addItem("成像仪", -1);
    ui->comboBox->addItem("快速成像仪", -1);
    ui->comboBox->addItem("探测仪", -1);

    m_pageNavigator = new LoadFilePageWidget();
    ui->pageWidget->layout()->addWidget(m_pageNavigator);
    ui->tableView->setModel(m_pageNavigator->m_pDataModel);
    //更新表格
    connect(m_pageNavigator, &LoadFilePageWidget::updataTableView, this, &LoadFilePage::slotUpdataTable);
    connect(ui->queryBtn, &QPushButton::clicked, this, &LoadFilePage::queryBtnClicked);
    connect(ui->reportBtn, &QPushButton::clicked, this, &LoadFilePage::exportStatus);
}
void LoadFilePage::setArrayDataInterface()
{
    LoadFileData data;
    LoadFileDataList DATA;

    QDateTime time = QDateTime::currentDateTime();

    for (int i = 1; i < 101; i++)
    {
        data.loadName = "探测仪图像定位";
        data.taskNum = "GTNXXXXXX" + QString::number(i);
        data.taskStatus = "GTNXXmsg";
        data.taskActualExetime = "信息";
        data.l0FirstArrivaltime = "探测仪图像定位";
        data.l0LastArrivaltime = "GTNXXXXXX" + QString::number(i);
        data.L0ActualReceiveNum = "GTNXXmsg";
        data.getL0Alltime = "信息";
        data.l1AFirsttime = "探测仪图像定位";
        data.l1ALasttime = "GTNXXXXXX" + QString::number(i);
        data.l1ANum = "GTNXXmsg";
        data.l1A_Alltime = "信息";
        DATA.append(data);
    }
    m_sqlLoadFileManager->insert(DATA);
    m_pageNavigator->m_pDataModel->SetArrayData(DATA);
    m_pageNavigator->m_pDataModel->SetPageSize(20);
    m_pageNavigator->UpdateStatus();
}
void LoadFilePage::initView()
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
