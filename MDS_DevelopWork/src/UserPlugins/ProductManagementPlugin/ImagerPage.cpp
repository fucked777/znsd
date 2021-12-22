#include "ImagerPage.h"
#include "DeviceStatusLogTableModel.h"
#include "PageNavigator.h"
#include "ui_ImagerPage.h"
#include <QDebug>
const int MAX_INSERT_NUM = 1000;

ImagerPage::ImagerPage(QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::ImagerPage)
{
    ui->setupUi(this);
    initMember();
    initView();
}

ImagerPage::~ImagerPage() { delete ui; }

void ImagerPage::queryBtnClicked() {}

void ImagerPage::reportBtnClicked() {}

void ImagerPage::allBtnClicked() {}

void ImagerPage::firstPageBtnClicked() {}

void ImagerPage::upperPageBtnClicked() {}

void ImagerPage::nextPageBtnClicked() {}

void ImagerPage::lastPageBtnClicked() {}

void ImagerPage::okBtnClicked() {}

void ImagerPage::initMember()
{
    connect(ui->allBtn, &QPushButton::clicked, this, &ImagerPage::allBtnClicked);
    connect(ui->queryBtn, &QPushButton::clicked, this, &ImagerPage::queryBtnClicked);
    connect(ui->reportBtn, &QPushButton::clicked, this, &ImagerPage::reportBtnClicked);
    connect(ui->okBtn, &QPushButton::clicked, this, &ImagerPage::okBtnClicked);

    m_pageNavigator = new PageNavigator();
    ui->widget->layout()->addWidget(m_pageNavigator);
    m_deviceStatusLogTableModel = new DeviceStatusLogTableModel();
    ui->tableView->viewport()->installEventFilter(this);
    ui->tableView->viewport()->setMouseTracking(true);

    ui->tableView->setModel(m_deviceStatusLogTableModel);
    ui->tableView->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->comboBox->addItem("25");
    ui->comboBox->addItem("50");
    ui->comboBox->addItem("80");
    ui->comboBox->addItem("100");
    //    connect(ui->comboBox, &QComboBox::currentTextChanged, this, &ImagerPage::curTestChangedCombox);
    //    datas.clear();
    if (headNames.size() == 0)  // default
        headNames << "序号"
                  << "任务编号"
                  << "输出时间"
                  << "文件名称"
                  << "本地文件路径"
                  << "输出文件路径"
                  << "传输方向"
                  << "传输方式"
                  << "精度"
                  << "输出类型"
                  << "文件大小";

    //    tableModel->setHorizontalHeaderLabels(headNames);
    //    tableModel->setRowCount(1);

    ui->tableView->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
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
void ImagerPage::slotSearchAck(const QByteArray& data)
{
    QByteArray bak = data;

    for (int i = 0; i < 10; i++)
    {
        DeviceStatusLogData data;
        DeviceStatusLogDataList DATA;
        data.taskNum = "111";
        data.outputTime = "二级";
        data.fileName = "2021-10-12 00:13:14";
        data.LocalFilePath = "xxx";
        data.outputFilePath = "NRSS15621";
        data.sendDirection = "成像仪图像定位与配准";
        data.sendType = "暂未处理";
        data.accuracy = "XXXXX";
        data.outputType = "NRST100001";
        data.fileSize = "XXX";
        DATA.append(data);

        //    bak >> dataList;
        m_deviceStatusLogTableModel->setDeviceStatusLogData(DATA);
    }
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
