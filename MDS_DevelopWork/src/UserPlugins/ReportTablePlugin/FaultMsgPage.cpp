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
#include <QJsonArray>
#include <QJsonDocument>
#include <QMessageBox>
#include <QToolTip>
#define DISPLAY_TIME_FORMAT "yyyy-MM-dd HH:mm:ss"
#define SERVER              "reportTableServer"
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
    connect(m_viewDetailDialog, &ViewDetailDialog::saveRemarksSignal, this, &FaultMsgPage::saveRemarksSlot);

    connect(m_dealFaultDialog, &DealFaultDialog::dealRemarksSignal, this, &FaultMsgPage::dealRemarksSlot);
    m_queryDialog->setWindowModality(Qt::ApplicationModal);
    m_dealFaultDialog->setWindowModality(Qt::ApplicationModal);
    m_viewDetailDialog->setWindowModality(Qt::ApplicationModal);  // motai
    initMember();
    initView();
    setArrayDataInterface();
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

void FaultMsgPage::saveRemarksSlot(const QString& text, int row)
{
    qDebug() << "text:" << text;
    QModelIndex indexValue = m_pageNavigator->m_pDataModel->index(row, 8);
    m_pageNavigator->m_pDataModel->setData(indexValue, text, Qt::EditRole);
}

void FaultMsgPage::dealRemarksSlot(const QStringList& text, int row)
{
    QModelIndex indexValue = m_pageNavigator->m_pDataModel->index(row, 5);
    m_pageNavigator->m_pDataModel->setData(indexValue, text, Qt::EditRole);
}

void FaultMsgPage::ShowTooltip(QModelIndex index)
{
    if (!index.isValid())
        return;
    QModelIndex _index = m_pageNavigator->m_pDataModel->index(index.row(), index.column());
    QVariant dataValue = m_pageNavigator->m_pDataModel->data(_index, Qt::DisplayRole);
    QString text = dataValue.toString();
    if (text.isEmpty())
        return;
    QToolTip::showText(QCursor::pos(), text);
    return;
}

void FaultMsgPage::reciveServerAndData(iDataTransformPluginService* server, QByteArray array)
{
    _server = server;
    m_array = array;
}

void FaultMsgPage::slotUpdataTable()
{
    ui->tableView->reset();
    QList<FaultMsgData> data = m_pageNavigator->m_pDataModel->GetPageArrayData();
    for (int i = 0; i < data.size(); i++)
    {
        QPushButton* detailsBtn = new QPushButton("查看详情", this);
        detailsBtn->setFlat(true);
        detailsBtn->setStyleSheet("color:rgb(0,170,255);font-size:14px;border-style:none;text-align: left;");
        connect(detailsBtn, &QPushButton::clicked, this, &FaultMsgPage::viewDetailBtnClicked);
        detailsBtn->setProperty("row", i);
        ui->tableView->setIndexWidget(m_pageNavigator->m_pDataModel->index(i, 9), detailsBtn);
    }
    for (int i = 0; i < data.size(); i++)
    {
        QPushButton* dealFaultBtn = new QPushButton("处理故障", this);
        dealFaultBtn->setFlat(true);
        dealFaultBtn->setStyleSheet("color:rgb(0,170,255);font-size:14px;border-style:none;text-align: left;");
        connect(dealFaultBtn, &QPushButton::clicked, this, &FaultMsgPage::dealFaultBtnClicked);
        dealFaultBtn->setProperty("row", i);
        ui->tableView->setIndexWidget(m_pageNavigator->m_pDataModel->index(i, 10), dealFaultBtn);
    }
}

void FaultMsgPage::viewDetailBtnClicked()
{
    QStringList Parameter;
    QPushButton* button = dynamic_cast<QPushButton*>(sender());
    QVariant val = button->property("row");
    int row = 0;
    if (val.isValid())
    {
        row = val.toInt();
    }
    for (int i = 0; i < m_pageNavigator->m_pDataModel->ColumnCount() - 2; i++)
    {
        QModelIndex indexValue = m_pageNavigator->m_pDataModel->index(row, i);
        QVariant dataValue = m_pageNavigator->m_pDataModel->data(indexValue, Qt::DisplayRole);
        Parameter << dataValue.toString();
    }
    m_viewDetailDialog->parameterSet(Parameter, row);
    m_viewDetailDialog->show();
}

void FaultMsgPage::dealFaultBtnClicked()
{
    QStringList Parameter;
    QPushButton* button = dynamic_cast<QPushButton*>(sender());
    QVariant val = button->property("row");
    int row = 0;
    if (val.isValid())
    {
        row = val.toInt();
    }
    //    for (int i = 0; i < m_pageNavigator->m_pDataModel->ColumnCount() - 2; i++)
    //    {
    //        QModelIndex indexValue = m_pageNavigator->m_pDataModel->index(row, i);
    //        QVariant dataValue = m_pageNavigator->m_pDataModel->data(indexValue, Qt::DisplayRole);
    //        Parameter << dataValue.toString();
    //    }
    m_dealFaultDialog->parameterSet(Parameter, row);
    m_dealFaultDialog->show();
}

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

    //    connect(ui->allBtn, &QPushButton::clicked, this, &FaultMsgPage::allBtnClicked);

    connect(ui->allBtn, &QAbstractButton::clicked, [=]() {
        QByteArray result /*= _server->cmdControl()->getMessage(SERVER, "get_table")*/;
        ui->tableView->reset();
        QJsonDocument doc = QJsonDocument::fromJson(result);
        if (doc.isEmpty())
        {
            return;
        }
        FaultMsgDataList DATA;
        QJsonArray obj = doc.array();
        for (int i = 0; i < obj.size(); ++i)
        {
            FaultMsgData data;
            QJsonArray colum = obj.at(i).toArray();
            for (int j = 0; j < colum.size(); ++j)
            {
                QString text = (QString("%1").arg(colum.at(j).toString()));
                switch (j)
                {
                case 0: data.faultLevel = text; continue;
                case 1: data.dateTime = text; continue;
                case 2: data.taskNum = text; continue;
                case 3: data.faultCode = text; continue;
                case 4: data.systemName = text; continue;
                case 5: data.dealStatus = text; continue;
                case 6: data.faultInfor = text; continue;
                case 7: data.internalFault = text; continue;
                case 8: data.remarks = text; continue;
                }
                //                QModelIndex indexValue = m_pageNavigator->m_pDataModel->index(i, j);
                //                m_pageNavigator->m_pDataModel->setData(indexValue, text, Qt::EditRole);
            }
            DATA.append(data);
        }
        m_pageNavigator->m_pDataModel->SetArrayData(DATA);
        m_pageNavigator->m_pDataModel->SetPageSize(20);
        m_pageNavigator->UpdateStatus();
    });

    connect(ui->queryBtn, &QPushButton::clicked, this, &FaultMsgPage::queryBtnClicked);
    connect(ui->reportBtn, &QPushButton::clicked, this, &FaultMsgPage::exportStatus);
}

void FaultMsgPage::setArrayDataInterface()
{
    FaultMsgData data;
    FaultMsgDataList DATA;
    QDateTime time = QDateTime::currentDateTime();
    for (int i = 1; i < 101; i++)
    {
        data.faultLevel = QString::number(i);
        data.dateTime = time.toString(DISPLAY_TIME_FORMAT);
        data.taskNum = "xxx";
        data.faultCode = "NRSS15621";
        data.systemName = "成像仪图像定位与配准";
        data.dealStatus = "暂未处理";
        data.faultInfor = "XXXXX";
        data.internalFault = "NRST100001";
        data.remarks = "XXX";
        DATA.append(data);
    }
    //    m_sqlFaultMsgManager->insert(DATA);  //插入数据库，方便查询
    //初始化
    m_pageNavigator->m_pDataModel->SetArrayData(DATA);
    m_pageNavigator->m_pDataModel->SetPageSize(20);
    m_pageNavigator->UpdateStatus();
}
void FaultMsgPage::initView()
{
    connect(ui->tableView, SIGNAL(entered(QModelIndex)), this, SLOT(ShowTooltip(QModelIndex)));
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
