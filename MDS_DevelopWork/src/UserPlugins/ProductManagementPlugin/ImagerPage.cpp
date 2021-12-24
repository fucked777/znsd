#include "ImagerPage.h"
#include "DeviceStatusLogTableModel.h"
#include "PageNavigator.h"
#include "QueryDialog_CXY.h"
#include "ui_ImagerPage.h"
#include <QDebug>
const int MAX_INSERT_NUM = 1000;

ImagerPage::ImagerPage(QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::ImagerPage)
{
    ui->setupUi(this);
    m_queryDialog_CXY = new QueryDialog_CXY();
    m_queryDialog_CXY->setWindowModality(Qt::ApplicationModal);
    connect(m_queryDialog_CXY, &QueryDialog_CXY::search, this, &ImagerPage::searchSlot);
    initMember();
    initView();
    slotSearchAck();
}

ImagerPage::~ImagerPage() { delete ui; }

void ImagerPage::queryBtnClicked() { m_queryDialog_CXY->show(); }

void ImagerPage::reportBtnClicked() {}

void ImagerPage::allBtnClicked() {}

void ImagerPage::okBtnClicked() {}

void ImagerPage::initMember()
{
    connect(ui->allBtn, &QPushButton::clicked, this, &ImagerPage::allBtnClicked);
    connect(ui->queryBtn, &QPushButton::clicked, this, &ImagerPage::queryBtnClicked);
    connect(ui->reportBtn, &QPushButton::clicked, this, &ImagerPage::reportBtnClicked);
    connect(ui->okBtn, &QPushButton::clicked, this, &ImagerPage::okBtnClicked);
    connect(ui->comboBox, &QComboBox::currentTextChanged, this, &ImagerPage::pageSizeChange);
    m_pageNavigator = new PageNavigator();
    ui->widget->layout()->addWidget(m_pageNavigator);
    connect(m_pageNavigator, &PageNavigator::currentPageChanged, this, &ImagerPage::currentPageChanged);
    m_deviceStatusLogTableModel = new DeviceStatusLogTableModel();
    ui->tableView->setModel(m_deviceStatusLogTableModel);
    connect(m_deviceStatusLogTableModel, &DeviceStatusLogTableModel::signalTotalCount, this, &ImagerPage::slotGetTotalCount);

    ui->tableView->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    //    ui->tableView->viewport()->installEventFilter(this);
    //    ui->tableView->viewport()->setMouseTracking(true);
    ui->comboBox->addItem("10");
    ui->comboBox->addItem("25");
    ui->comboBox->addItem("50");
    ui->comboBox->addItem("100");
}
void ImagerPage::slotGetTotalCount(const int totalCount, const int currentPage)
{
    int pageSize = ui->comboBox->currentData().toInt();
    int pageNum = totalCount / pageSize + ((totalCount % pageSize) ? 1 : 0);
    m_pageNavigator->setMaxPage(pageNum);
    m_pageNavigator->setCurrentPage(currentPage);
}

void ImagerPage::searchSlot(const QStringList& taskName, const QStringList& taskNum, const QStringList& fileName, const QStringList& outputType,
                            const QDateTime& start_time, const QDateTime& end_time)
{
    int pageSize = ui->comboBox->currentData().toInt();
    m_deviceStatusLogTableModel->reset(taskName, taskNum, fileName, outputType, start_time, end_time, 1, pageSize);
}
void ImagerPage::pageSizeChange(const QString& /*strPage*/) { query(); }
void ImagerPage::query()
{
    //    QVector<QStringList> data;
    //    data = m_queryDialog_CXY->getSerachData();
    //    QVector<QDateTime> time;
    //    time = m_queryDialog_CXY->getTime();
    //    int pageSize = ui->comboBox->currentData().toInt();
    //    m_deviceStatusLogTableModel->reset(data.at(0), data.at(1), data.at(2), data.at(3), time.at(0), time.at(1), 1, pageSize);
}
void ImagerPage::currentPageChanged(int page)
{
    int pageSize = ui->comboBox->currentData().toInt();
    //    m_deviceStatusLogTableModel->reset(device_list, unit_list, status_list, ui->startDateTimeEdit->dateTime(), ui->endDateTimeEdit->dateTime(),
    //                                       mode_list, page, pageSize);
}
void ImagerPage::initView()
{
    ui->tableView->setShowGrid(false);
    // 设置表头不可见，需要添加QHeadView头文件
    //    ui->tableView->horizontalHeader()->setVisible(false);  // 水平不可见
    ui->tableView->verticalHeader()->setVisible(false);  // 垂直不可见
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->horizontalHeader()->setDefaultAlignment(Qt::AlignVCenter);
    ui->tableView->setEditTriggers(QAbstractItemView::DoubleClicked);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);  //设置选中模式为选中行
}
void ImagerPage::slotSearchAck(/*const QByteArray& data*/)
{
    //    QByteArray bak = data;
    DeviceStatusLogData data;
    DeviceStatusLogDataList DATA;
    for (int i = 1; i < 101; i++)
    {
        data.taskNum = QString::number(i);
        data.outputTime = "2021-10-12";
        data.fileName = "00:13:14";
        data.LocalFilePath = "c:xiaoxiao";
        data.outputFilePath = "c:xiaoxiao";
        data.sendDirection = "成像仪";
        data.sendType = "暂未处理";
        data.accuracy = "XXXXX";
        data.outputType = "NRST100001";
        data.fileSize = "XXX";
        DATA.append(data);
    }
    m_deviceStatusLogTableModel->setDeviceStatusLogData(DATA);
}
// void ImagerPage::updateRowData(QVector<RowDataImagerMsg>& values)
//{
//    tableModel->clear();
//    tableModel->setHorizontalHeaderLabels(headNames);
//    for (int i = 0; i < values.size(); i++)
//    {
//        QList<QStandardItem*> itemList;
//        itemList << new QStandardItem << new QStandardItem(QString::number(tableModel->rowCount() + 1)) << new QStandardItem(values[i].faultLevel)
//                 << new QStandardItem(values[i].dateTime) << new QStandardItem(values[i].taskNum) << new QStandardItem(values[i].faultCode)
//                 << new QStandardItem(values[i].systemName) << new QStandardItem(values[i].dealStatus) << new QStandardItem(values[i].faultInfor)
//                 << new QStandardItem(values[i].internalFault) << new QStandardItem(values[i].remarks) << new QStandardItem << new QStandardItem;
//        tableModel->appendRow(itemList);

//        QPushButton* detailsBtn = new QPushButton("查看详情", this);
//        detailsBtn->setFlat(true);
//        detailsBtn->setStyleSheet("color:rgb(0,170,255);font-size:12px;border-style:none;text-align: left;");
//        //        connect(handleBtn, &QPushButton::clicked, this, &ImagerPage::delItemClicked);
//        detailsBtn->setProperty("row", i);
//        ui->tableView->setIndexWidget(tableModel->index(i, tableModel->columnCount() - 2), detailsBtn);

//        QPushButton* dealBtn = new QPushButton("处理故障", this);
//        dealBtn->setFlat(true);
//        dealBtn->setStyleSheet("color:rgb(0,170,255);font-size:12px;border-style:none;text-align: left;");
//        //        connect(handleBtn, &QPushButton::clicked, this, &ImagerPage::delItemClicked);
//        dealBtn->setProperty("row", i);
//        ui->tableView->setIndexWidget(tableModel->index(i, tableModel->columnCount() - 1), dealBtn);
//    }
//}
QString ImagerPage::pasraDoubleToStr(double value, int prsc, char f) { return QString::number(value, f, prsc); }
