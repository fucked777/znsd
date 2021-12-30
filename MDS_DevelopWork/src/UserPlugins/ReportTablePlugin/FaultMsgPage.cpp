#include "FaultMsgPage.h"
#include "DealFaultDialog.h"
#include "QueryDialog.h"
#include "SqlFaultMsgManager.h"
#include "ViewDetailDialog.h"
#include "pageWidget.h"
#include "ui_FaultMsgPage.h"
#include <QDateTime>
#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
const int MAX_INSERT_NUM = 1000;

FaultMsgPage::FaultMsgPage(QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::FaultMsgPage)
{
    ui->setupUi(this);
    m_queryDialog = new QueryDialog();
    m_dealFaultDialog = new DealFaultDialog();
    m_viewDetailDialog = new ViewDetailDialog();
    m_sqlFaultMsgManager = new SqlFaultMsgManager();
    connect(m_queryDialog, &QueryDialog::search, this, &FaultMsgPage::searchSlot);
    m_queryDialog->setWindowModality(Qt::ApplicationModal);
    m_dealFaultDialog->setWindowModality(Qt::ApplicationModal);
    m_viewDetailDialog->setWindowModality(Qt::ApplicationModal);  // motai
    initMember();
    initView();
}

FaultMsgPage::~FaultMsgPage() { delete ui; }

void FaultMsgPage::queryBtnClicked() { m_queryDialog->show(); }

void FaultMsgPage::exportStatus()
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

void FaultMsgPage::searchSlot(const QStringList& taskName, const QStringList& taskNum, const QStringList& fileName, const QStringList& outputType,
                              const QDateTime& start_time, const QDateTime& end_time)
{
}

void FaultMsgPage::slotUpdataTable() { ui->tableView->reset(); }
void FaultMsgPage::processExport(const QString& fileName)
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

    //    for (auto status : status_lists)
    //    {
    //        stream << QString("任务编号：").toUtf8() << status.taskNum << QString("     ").toUtf8() << QString("输出时间：").toUtf8()
    //               << status.outputTime.toUtf8() << QString("     ").toUtf8() << QString("文件名称：").toUtf8() << status.fileName.toUtf8()
    //               << QString("     ").toUtf8() << QString("本地文件路径：").toUtf8() << status.LocalFilePath.toUtf8() << QString("     ").toUtf8()
    //               << QString("输出文件路径").toUtf8() << status.outputFilePath.toUtf8() << QString("     ").toUtf8() <<
    //               QString("传输方向：").toUtf8()
    //               << status.sendDirection.toUtf8() << QString("     ").toUtf8() << QString("传输方式：").toUtf8() << status.sendType.toUtf8()
    //               << QString("     ").toUtf8() << QString("精度：").toUtf8() << status.accuracy.toUtf8() << QString("     ").toUtf8()
    //               << QString("输出类型：").toUtf8() << status.outputType.toUtf8() << QString("     ").toUtf8() << QString("文件大小：").toUtf8()
    //               << status.fileSize.toUtf8() << QString("     ").toUtf8() << '\n';
    //    }
    file.close();
}

void FaultMsgPage::allBtnClicked()
{
    QFile file("data/style/MainManager.qss");
    if (file.open(QFile::ReadOnly))
    {
        QString styleSheet = QLatin1String(file.readAll());

        ui->allBtn->setStyleSheet(styleSheet);
        file.close();
    }
}

void FaultMsgPage::initMember()
{
    m_pageNavigator = new pageWidget();
    ui->widget->layout()->addWidget(m_pageNavigator);
    ui->tableView->setModel(m_pageNavigator->m_pDataModel);
    //更新表格
    connect(m_pageNavigator, &pageWidget::updataTableView, this, &FaultMsgPage::slotUpdataTable);
    FaultMsgData data;
    FaultMsgDataList DATA;
    for (int i = 1; i < 101; i++)
    {
        data.faultLevel = "二级";
        data.dateTime = "2021-10-12 00:13:14";
        data.taskNum = "xxx";
        data.faultCode = "NRSS15621";
        data.systemName = "成像仪图像定位与配准";
        data.dealStatus = "暂未处理";
        data.faultInfor = "XXXXX";
        data.internalFault = "NRST100001";
        data.remarks = "XXX";
        DATA.append(data);
    }
    m_sqlFaultMsgManager->insert(DATA);
    m_pageNavigator->m_pDataModel->SetArrayData(DATA);
    m_pageNavigator->m_pDataModel->SetPageSize(20);
    m_pageNavigator->UpdateStatus();

    //    int index = m_pageNavigator->m_pDataModel->GetPageSize();
    //    for (int i = 0; i < index; i++)
    //    {
    //        QPushButton* detailsBtn = new QPushButton("查看详情", this);
    //        detailsBtn->setFlat(true);
    //        detailsBtn->setStyleSheet("color:rgb(0,170,255);font-size:12px;border-style:none;text-align: left;");
    //        //    connect(detailsBtn, &QPushButton::clicked, this, &FaultMsgPage::viewDetailItemClicked);
    //        //    detailsBtn->setProperty("row", i);
    //        ui->tableView->setIndexWidget(m_pageNavigator->m_pDataModel->index(i, 9), detailsBtn);
    //    }

    connect(ui->allBtn, &QPushButton::clicked, this, &FaultMsgPage::allBtnClicked);
    connect(ui->queryBtn, &QPushButton::clicked, this, &FaultMsgPage::queryBtnClicked);
    connect(ui->reportBtn, &QPushButton::clicked, this, &FaultMsgPage::exportStatus);
}
void FaultMsgPage::initView()
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

// void FaultMsgPage::appendRowData(RowDataFaultMsg value)
//{
//    QList<QStandardItem*> itemList;
//    itemList << new QStandardItem(QString::number(tableModel->rowCount() + 1)) << new QStandardItem(value.faultLevel)
//             << new QStandardItem(value.dateTime) << new QStandardItem(value.taskNum) << new QStandardItem(value.faultCode)
//             << new QStandardItem(value.systemName) << new QStandardItem(value.dealStatus) << new QStandardItem(value.faultInfor)
//             << new QStandardItem(value.internalFault) << new QStandardItem(value.remarks) << new QStandardItem << new QStandardItem;

//    QPushButton* detailsBtn = new QPushButton("查看详情", this);
//    detailsBtn->setFlat(true);
//    detailsBtn->setStyleSheet("color:rgb(0,170,255);font-size:18px;background-color:transparent;border-style:none;text-align: left;");
//    //    connect(handleBtn, &QPushButton::clicked, this, &FaultMsgPage::delItemClicked);
//    detailsBtn->setProperty("row", tableModel->rowCount() - 1);
//    ui->tableView->setIndexWidget(tableModel->index(tableModel->rowCount() - 2, tableModel->columnCount() - 2), detailsBtn);

//    QPushButton* dealBtn = new QPushButton("处理故障", this);
//    dealBtn->setFlat(true);
//    dealBtn->setStyleSheet("color:rgb(0,170,255);font-size:18px;background-color:transparent;border-style:none;text-align: left;");
//    //    connect(handleBtn, &QPushButton::clicked, this, &FaultMsgPage::delItemClicked);
//    dealBtn->setProperty("row", tableModel->rowCount() - 1);
//    ui->tableView->setIndexWidget(tableModel->index(tableModel->rowCount() - 1, tableModel->columnCount() - 1), dealBtn);

//    tableModel->appendRow(itemList);
//    ui->tableView->clearSelection();
//}
QString FaultMsgPage::pasraDoubleToStr(double value, int prsc, char f) { return QString::number(value, f, prsc); }
