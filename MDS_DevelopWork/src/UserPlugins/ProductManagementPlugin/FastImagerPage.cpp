#include "FastImagerPage.h"
#include "HeaderView.h"
#include "NotEditableDelegate.h"
//#include "TableAnalyse.h"
#include "ui_FastImagerPage.h"
#include <QDebug>
const int MAX_INSERT_NUM = 1000;

FastImagerPage::FastImagerPage(QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::FastImagerPage)
{
    ui->setupUi(this);
    initMember();
    initView();
}

FastImagerPage::~FastImagerPage() { delete ui; }

QVector<RowDataFastImagerMsg> FastImagerPage::getDatas() const { return m_datas; }

void FastImagerPage::delBtnClicked()
{
    //    QVector<RowDataFastImagerMsg> datas = getCheckedRowData();
    //    faultMstAnalyse->dels(datas);
    //    datas.clear();
    //    datas = faultMstAnalyse->query();
    //    updateRowData(datas);
}

void FastImagerPage::queryBtnClicked() {}

void FastImagerPage::reportBtnClicked() {}

void FastImagerPage::allBtnClicked() {}

void FastImagerPage::firstPageBtnClicked() {}

void FastImagerPage::upperPageBtnClicked() {}

void FastImagerPage::nextPageBtnClicked() {}

void FastImagerPage::lastPageBtnClicked() {}

void FastImagerPage::okBtnClicked()
{
    //    m_datas = freqTableView->getCheckedRowDataLSSMs();
    //    emit settingDlgCloseSignal(1, m_datas.size());
    //    accept();
    //    QVariant index = freqTableView->getRowCount();
    //    NSGlobal::RowDataFastImagerMsg dataSaveInfoMap;
    //    QVector<NSGlobal::LSSMFreqTableRowData> dataSave;
    //    dataSave = freqTableView->getDataInfo(dataSaveInfoMap);
    //    m_datas = dataSave;
    //    emit dataSaveSignal(dataSave);
}

void FastImagerPage::clearBtnClicked() {}

void FastImagerPage::delItemClicked(const int rowIndex)
{
    //    QVector<RowDataFastImagerMsg> datas;
    //    datas << getRowData(rowIndex);
    //    faultMstAnalyse->dels(datas);
    //    datas.clear();
    //    datas = faultMstAnalyse->query();
    //    updateRowData(datas);
}

void FastImagerPage::initMember()
{
    connect(ui->allBtn, &QPushButton::clicked, this, &FastImagerPage::allBtnClicked);
    connect(ui->queryBtn, &QPushButton::clicked, this, &FastImagerPage::queryBtnClicked);
    connect(ui->delBtn, &QPushButton::clicked, this, &FastImagerPage::delBtnClicked);
    connect(ui->reportBtn, &QPushButton::clicked, this, &FastImagerPage::reportBtnClicked);
    connect(ui->clearBtn, &QPushButton::clicked, this, &FastImagerPage::clearBtnClicked);
    connect(ui->firstPageBtn, &QPushButton::clicked, this, &FastImagerPage::firstPageBtnClicked);
    connect(ui->upperPageBtn, &QPushButton::clicked, this, &FastImagerPage::upperPageBtnClicked);
    connect(ui->nextPageBtn, &QPushButton::clicked, this, &FastImagerPage::nextPageBtnClicked);
    connect(ui->lastPageBtn, &QPushButton::clicked, this, &FastImagerPage::lastPageBtnClicked);
    connect(ui->okBtn, &QPushButton::clicked, this, &FastImagerPage::okBtnClicked);

    ui->tableView->viewport()->installEventFilter(this);
    ui->tableView->viewport()->setMouseTracking(true);

    tableModel = new QStandardItemModel(this);
    ui->tableView->setModel(tableModel);

    //    checkBoxDelegate = new CheckBoxDelegate(this);
    notEditableDelegate = new NotEditableDelegate(ui->tableView);
    ui->tableView->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    //    ui->tableView->setItemDelegateForColumn(0, checkBoxDelegate);
    ui->tableView->setItemDelegate(notEditableDelegate);
    connect(notEditableDelegate, &NotEditableDelegate::checkCurrRowSignal, this, &FastImagerPage::checkCurrRowSlot);
    ui->comboBox->addItem("25");
    ui->comboBox->addItem("50");
    ui->comboBox->addItem("80");
    ui->comboBox->addItem("100");
    connect(ui->comboBox, &QComboBox::currentTextChanged, this, &FastImagerPage::curTestChangedCombox);
    //    datas.clear();
    columnWidths.clear();
    columnWidths.push_back(120);
    columnWidths.push_back(120);
    columnWidths.push_back(120);
    columnWidths.push_back(200);
    columnWidths.push_back(120);
    columnWidths.push_back(120);
    columnWidths.push_back(200);
    columnWidths.push_back(120);
    columnWidths.push_back(120);
    columnWidths.push_back(120);
    columnWidths.push_back(120);
    columnWidths.push_back(120);
    columnWidths.push_back(120);
    for (int i = 0; i < 12; i++)
    {
        totleColumnWidth += columnWidths.at(i);
    }
    if (headNames.size() == 0)  // default
        headNames << ""
                  << "序号"
                  << "故障等级"
                  << "日期"
                  << "任务编号"
                  << "故障代码"
                  << "分系统名"
                  << "处理与否"
                  << "故障信息"
                  << "内部故障"
                  << "备注"
                  << "故障详情"
                  << "操作";

    tableModel->setHorizontalHeaderLabels(headNames);
    //    tableModel->setRowCount(1);
    headerView = new HeaderView(Qt::Horizontal, this);
    connect(headerView, &HeaderView::selectOrDeselectAll, this, &FastImagerPage::selectAllItems);
    ui->tableView->setHorizontalHeader(headerView);

    ui->tableView->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    //    connect(freqTableView, &FastImagerPage::sigDelItemClicked, this, &FastImagerPage::delItemClicked);

    //    faultMstAnalyse = new TableAnalyse("Datas/ReportTable/rawdata/freq.dat");
    //    if (faultMstAnalyse)
    //    {
    //        QVector<RowDataFastImagerMsg> datas = faultMstAnalyse->query();
    //        updateRowData(datas);
    //    }
}
void FastImagerPage::initView()
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

void FastImagerPage::curTestChangedCombox(const QString test)
{
    //    QVector<RowDataFastImagerMsg> datas = faultMstAnalyse->query();
    //    if (datas.size() >= MAX_INSERT_NUM)
    //        return;
    //    for (int i = 0; i < 10; i++)
    //    {
    //        RowDataFastImagerMsg data;
    //        data.faultLevel = "二级";
    //        data.dateTime = "2021-10-12 00:13:14";
    //        data.taskNum = "xxx";
    //        data.faultCode = "NRSS15621";
    //        data.systemName = "成像仪图像定位与配准";
    //        data.dealStatus = "暂未处理";
    //        data.faultInfor = "XXXXX";
    //        data.internalFault = "NRST100001";
    //        data.remarks = "XXX";
    //        faultMstAnalyse->add(data);
    //    }
    //    datas = faultMstAnalyse->query();
    //    updateRowData(datas);
}
void FastImagerPage::selectAllItems(Qt::CheckState state)
{
    //    for (int i = 0; i < tableModel->rowCount(); i++)
    //    {
    //        bool checkState = (state == Qt::Checked) ? true : false;
    //        tableModel->item(i, 0)->setData(checkState, Qt::UserRole);
    //    }
    removeRowIndexs.clear();
    if (state)
        for (int i = 0; i < tableModel->rowCount(); i++)
        {
            tableModel->setData(tableModel->index(i, 0), state, Qt::UserRole);
            removeRowIndexs.push_back(i);
        }
    else
        for (int i = 0; i < tableModel->rowCount(); i++)
        {
            tableModel->setData(tableModel->index(i, 0), state, Qt::UserRole);
        }
    //    QMessageBox::information(this, "xxx", "xxx");
}
void FastImagerPage::checkCurrRowSlot(int rowIndex, bool checked)
{
    if (checked)

        removeRowIndexs.push_back(rowIndex);
    else
    {
        int pos = -1;
        if (removeRowIndexs.contains(rowIndex))
        {
            pos = removeRowIndexs.indexOf(rowIndex);
            removeRowIndexs.removeAt(pos);
        }
    }
}

RowDataFastImagerMsg FastImagerPage::getRowData(const int rowNum)
{
    RowDataFastImagerMsg data;
    if (rowNum >= 0 && rowNum < tableModel->rowCount())
    {
        data.faultLevel = tableModel->item(rowNum, 2)->data(Qt::DisplayRole).toString();
        data.dateTime = tableModel->item(rowNum, 3)->data(Qt::DisplayRole).toString();
        data.taskNum = tableModel->item(rowNum, 4)->data(Qt::DisplayRole).toString();
        data.faultCode = tableModel->item(rowNum, 5)->data(Qt::DisplayRole).toString();
        data.systemName = tableModel->item(rowNum, 6)->data(Qt::DisplayRole).toString();
        data.dealStatus = tableModel->item(rowNum, 7)->data(Qt::DisplayRole).toString();
        data.faultInfor = tableModel->item(rowNum, 8)->data(Qt::DisplayRole).toString();
        data.internalFault = tableModel->item(rowNum, 9)->data(Qt::DisplayRole).toString();
        data.remarks = tableModel->item(rowNum, 10)->data(Qt::DisplayRole).toString();
    }
    return data;
}
void FastImagerPage::updateRowData(QVector<RowDataFastImagerMsg>& values)
{
    tableModel->clear();
    tableModel->setHorizontalHeaderLabels(headNames);
    for (int i = 0; i < values.size(); i++)
    {
        QList<QStandardItem*> itemList;
        itemList << new QStandardItem << new QStandardItem(QString::number(tableModel->rowCount() + 1)) << new QStandardItem(values[i].faultLevel)
                 << new QStandardItem(values[i].dateTime) << new QStandardItem(values[i].taskNum) << new QStandardItem(values[i].faultCode)
                 << new QStandardItem(values[i].systemName) << new QStandardItem(values[i].dealStatus) << new QStandardItem(values[i].faultInfor)
                 << new QStandardItem(values[i].internalFault) << new QStandardItem(values[i].remarks) << new QStandardItem << new QStandardItem;
        tableModel->appendRow(itemList);

        QPushButton* detailsBtn = new QPushButton("查看详情", this);
        detailsBtn->setFlat(true);
        detailsBtn->setStyleSheet("color:rgb(0,170,255);font-size:12px;border-style:none;text-align: left;");
        //        connect(handleBtn, &QPushButton::clicked, this, &FastImagerPage::delItemClicked);
        detailsBtn->setProperty("row", i);
        ui->tableView->setIndexWidget(tableModel->index(i, tableModel->columnCount() - 2), detailsBtn);

        QPushButton* dealBtn = new QPushButton("处理故障", this);
        dealBtn->setFlat(true);
        dealBtn->setStyleSheet("color:rgb(0,170,255);font-size:12px;border-style:none;text-align: left;");
        //        connect(handleBtn, &QPushButton::clicked, this, &FastImagerPage::delItemClicked);
        dealBtn->setProperty("row", i);
        ui->tableView->setIndexWidget(tableModel->index(i, tableModel->columnCount() - 1), dealBtn);
    }
}
QVector<RowDataFastImagerMsg> FastImagerPage::getCheckedRowData()
{
    QVector<RowDataFastImagerMsg> datas;
    for (int i = 0; i < tableModel->rowCount(); i++)
    {
        bool isSelected = tableModel->item(i, 0)->data(Qt::UserRole).toBool();
        if (isSelected)
        {
            datas << getRowData(i);
        }
    }
    return datas;
}

void FastImagerPage::delItemClicked()
{
    int rowIndex = ui->tableView->currentIndex().row();
    int pos = -1;
    for (int i = 0; i < removeRowIndexs.size(); i++)
    {
        if (removeRowIndexs.at(i) == rowIndex)
            pos = i;
        else if (removeRowIndexs.at(i) > rowIndex)
            removeRowIndexs[i]--;
    }
    if (pos != -1)
        removeRowIndexs.removeAt(pos);
    QPushButton* button = dynamic_cast<QPushButton*>(sender());
    QVariant val = button->property("row");
    if (val.isValid())
    {
        int row = val.toInt();
        //        emit sigDelItemClicked(row);
    }
}

void FastImagerPage::appendRowData(RowDataFastImagerMsg value)
{
    QList<QStandardItem*> itemList;
    itemList << new QStandardItem(QString::number(tableModel->rowCount() + 1)) << new QStandardItem(value.faultLevel)
             << new QStandardItem(value.dateTime) << new QStandardItem(value.taskNum) << new QStandardItem(value.faultCode)
             << new QStandardItem(value.systemName) << new QStandardItem(value.dealStatus) << new QStandardItem(value.faultInfor)
             << new QStandardItem(value.internalFault) << new QStandardItem(value.remarks) << new QStandardItem << new QStandardItem;

    QPushButton* detailsBtn = new QPushButton("查看详情", this);
    detailsBtn->setFlat(true);
    detailsBtn->setStyleSheet("color:rgb(0,170,255);font-size:18px;background-color:transparent;border-style:none;text-align: left;");
    //    connect(handleBtn, &QPushButton::clicked, this, &FastImagerPage::delItemClicked);
    detailsBtn->setProperty("row", tableModel->rowCount() - 1);
    ui->tableView->setIndexWidget(tableModel->index(tableModel->rowCount() - 2, tableModel->columnCount() - 2), detailsBtn);

    QPushButton* dealBtn = new QPushButton("处理故障", this);
    dealBtn->setFlat(true);
    dealBtn->setStyleSheet("color:rgb(0,170,255);font-size:18px;background-color:transparent;border-style:none;text-align: left;");
    //    connect(handleBtn, &QPushButton::clicked, this, &FastImagerPage::delItemClicked);
    dealBtn->setProperty("row", tableModel->rowCount() - 1);
    ui->tableView->setIndexWidget(tableModel->index(tableModel->rowCount() - 1, tableModel->columnCount() - 1), dealBtn);

    tableModel->appendRow(itemList);
    ui->tableView->clearSelection();
}
QString FastImagerPage::pasraDoubleToStr(double value, int prsc, char f) { return QString::number(value, f, prsc); }
