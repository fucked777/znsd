﻿#include "FaultMsgPage.h"
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

void FaultMsgPage::slotUpdataTable()
{
    QList<FaultMsgData> data = m_pageNavigator->m_pDataModel->GetPageArrayData();
    xhcs = m_pageNavigator->m_pDataModel->GetCurPage() * m_pageNavigator->m_pDataModel->GetPageSize();
    for (int i = 0; i < data.size(); i++)
    {
        QPushButton* detailsBtn = new QPushButton("查看详情", this);
        detailsBtn->setFlat(true);
        detailsBtn->setStyleSheet("color:rgb(0,170,255);font-size:14px;border-style:none;text-align: left;");
        connect(detailsBtn, &QPushButton::clicked, this, &FaultMsgPage::viewDetailBtnClicked);
        //    detailsBtn->setProperty("row", i);
        ui->tableView->setIndexWidget(m_pageNavigator->m_pDataModel->index(xhcs + i, 9), detailsBtn);
    }
    for (int i = 0; i < data.size(); i++)
    {
        QPushButton* dealFaultBtn = new QPushButton("处理故障", this);
        dealFaultBtn->setFlat(true);
        dealFaultBtn->setStyleSheet("color:rgb(0,170,255);font-size:14px;border-style:none;text-align: left;");
        connect(dealFaultBtn, &QPushButton::clicked, this, &FaultMsgPage::dealFaultBtnClicked);
        //    dealFaultBtn->setProperty("row", i);
        ui->tableView->setIndexWidget(m_pageNavigator->m_pDataModel->index(xhcs + i, 10), dealFaultBtn);
    }
    //    ui->tableView->reset();
}

void FaultMsgPage::viewDetailBtnClicked() { m_viewDetailDialog->show(); }

void FaultMsgPage::dealFaultBtnClicked() { m_dealFaultDialog->show(); }

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

    for (auto status : status_lists)
    {
        stream << QString("故障等级:").toUtf8() << status.faultLevel << QString("     ").toUtf8() << QString("日期:").toUtf8()
               << status.dateTime.toUtf8() << QString("     ").toUtf8() << QString("任务编号:").toUtf8() << status.taskNum.toUtf8()
               << QString("     ").toUtf8() << QString("故障代码:").toUtf8() << status.faultCode.toUtf8() << QString("     ").toUtf8()
               << QString("分系统名称:").toUtf8() << status.systemName.toUtf8() << QString("     ").toUtf8() << QString("处理状态:").toUtf8()
               << status.dealStatus.toUtf8() << QString("     ").toUtf8() << QString("故障信息:").toUtf8() << status.faultInfor.toUtf8()
               << QString("     ").toUtf8() << QString("内部故障:").toUtf8() << status.internalFault.toUtf8() << QString("     ").toUtf8()
               << QString("备注:").toUtf8() << status.remarks.toUtf8() << QString("     ").toUtf8() << '\n';
    }
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
        data.faultLevel = QString::number(i);
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
QString FaultMsgPage::pasraDoubleToStr(double value, int prsc, char f) { return QString::number(value, f, prsc); }
