#include "LogMsgPage.h"
#include "HeaderView.h"
#include "NotEditableDelegate.h"
#include "TableAnalyse.h"
#include "ui_LogMsgPage.h"
#include <QDebug>
const int MAX_INSERT_NUM = 1000;

LogMsgPage::LogMsgPage(QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::LogMsgPage)
{
    ui->setupUi(this);
    initMember();
    initView();
}

LogMsgPage::~LogMsgPage() { delete ui; }

QVector<RowDataLogMsg> LogMsgPage::getDatas() const { return m_datas; }

void LogMsgPage::delBtnClicked()
{
    //    QVector<RowDataLogMsg> datas = getCheckedRowData();
    //    faultMstAnalyse->dels(datas);
    //    datas.clear();
    //    datas = faultMstAnalyse->query();
    //    updateRowData(datas);
}

void LogMsgPage::queryBtnClicked() {}

void LogMsgPage::reportBtnClicked() {}

void LogMsgPage::allBtnClicked() {}

void LogMsgPage::firstPageBtnClicked() {}

void LogMsgPage::upperPageBtnClicked() {}

void LogMsgPage::nextPageBtnClicked() {}

void LogMsgPage::lastPageBtnClicked() {}

void LogMsgPage::okBtnClicked()
{
    //    m_datas = freqTableView->getCheckedRowDataLSSMs();
    //    emit settingDlgCloseSignal(1, m_datas.size());
    //    accept();
    //    QVariant index = freqTableView->getRowCount();
    //    NSGlobal::RowDataLogMsg dataSaveInfoMap;
    //    QVector<NSGlobal::LSSMFreqTableRowData> dataSave;
    //    dataSave = freqTableView->getDataInfo(dataSaveInfoMap);
    //    m_datas = dataSave;
    //    emit dataSaveSignal(dataSave);
}

void LogMsgPage::clearBtnClicked() {}

void LogMsgPage::delItemClicked(const int rowIndex)
{
    //    QVector<RowDataLogMsg> datas;
    //    datas << getRowData(rowIndex);
    //    faultMstAnalyse->dels(datas);
    //    datas.clear();
    //    datas = faultMstAnalyse->query();
    //    updateRowData(datas);
}

void LogMsgPage::initMember()
{
    connect(ui->allBtn, &QPushButton::clicked, this, &LogMsgPage::allBtnClicked);
    connect(ui->queryBtn, &QPushButton::clicked, this, &LogMsgPage::queryBtnClicked);
    connect(ui->delBtn, &QPushButton::clicked, this, &LogMsgPage::delBtnClicked);
    connect(ui->reportBtn, &QPushButton::clicked, this, &LogMsgPage::reportBtnClicked);
    connect(ui->clearBtn, &QPushButton::clicked, this, &LogMsgPage::clearBtnClicked);
    connect(ui->firstPageBtn, &QPushButton::clicked, this, &LogMsgPage::firstPageBtnClicked);
    connect(ui->upperPageBtn, &QPushButton::clicked, this, &LogMsgPage::upperPageBtnClicked);
    connect(ui->nextPageBtn, &QPushButton::clicked, this, &LogMsgPage::nextPageBtnClicked);
    connect(ui->lastPageBtn, &QPushButton::clicked, this, &LogMsgPage::lastPageBtnClicked);
    connect(ui->okBtn, &QPushButton::clicked, this, &LogMsgPage::okBtnClicked);

    ui->tableView->viewport()->installEventFilter(this);
    ui->tableView->viewport()->setMouseTracking(true);

    tableModel = new QStandardItemModel(this);
    ui->tableView->setModel(tableModel);

    //    checkBoxDelegate = new CheckBoxDelegate(this);
    notEditableDelegate = new NotEditableDelegate(ui->tableView);
    ui->tableView->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    //    ui->tableView->setItemDelegateForColumn(0, checkBoxDelegate);
    ui->tableView->setItemDelegate(notEditableDelegate);
    connect(notEditableDelegate, &NotEditableDelegate::checkCurrRowSignal, this, &LogMsgPage::checkCurrRowSlot);
    ui->comboBox->addItem("25");
    ui->comboBox->addItem("50");
    ui->comboBox->addItem("80");
    ui->comboBox->addItem("100");
    connect(ui->comboBox, &QComboBox::currentTextChanged, this, &LogMsgPage::curTestChangedCombox);
    //    datas.clear();
    columnWidths.clear();
    columnWidths.push_back(120);
    columnWidths.push_back(120);
    columnWidths.push_back(120);
    columnWidths.push_back(200);
    columnWidths.push_back(120);
    columnWidths.push_back(120);
    columnWidths.push_back(200);

    for (int i = 0; i < 7; i++)
    {
        totleColumnWidth += columnWidths.at(i);
    }
    if (headNames.size() == 0)  // default
        headNames << ""
                  << "序号"
                  << "日期"
                  << "分系统名"
                  << "任务编号"
                  << "日志信息"
                  << "日志性质";

    tableModel->setHorizontalHeaderLabels(headNames);
    //    tableModel->setRowCount(1);
    headerView = new HeaderView(Qt::Horizontal, this);
    connect(headerView, &HeaderView::selectOrDeselectAll, this, &LogMsgPage::selectAllItems);
    ui->tableView->setHorizontalHeader(headerView);

    ui->tableView->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    //    connect(freqTableView, &LogMsgPage::sigDelItemClicked, this, &LogMsgPage::delItemClicked);

    //    faultMstAnalyse = new TableAnalyse("Datas/ReportTable/rawdata/freq.dat");
    //    if (faultMstAnalyse)
    //    {
    //        QVector<RowDataLogMsg> datas = faultMstAnalyse->query();
    //        updateRowData(datas);
    //    }
}
void LogMsgPage::initView()
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

void LogMsgPage::curTestChangedCombox(const QString test)
{
    //    QVector<RowDataLogMsg> datas = faultMstAnalyse->query();
    //    if (datas.size() >= MAX_INSERT_NUM)
    //        return;
    //    for (int i = 0; i < 10; i++)
    //    {
    //        RowDataLogMsg data;
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
void LogMsgPage::selectAllItems(Qt::CheckState state)
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
void LogMsgPage::checkCurrRowSlot(int rowIndex, bool checked)
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

RowDataLogMsg LogMsgPage::getRowData(const int rowNum)
{
    RowDataLogMsg data;
    if (rowNum >= 0 && rowNum < tableModel->rowCount())
    {
        data.dateTime = tableModel->item(rowNum, 2)->data(Qt::DisplayRole).toString();
        data.systemName = tableModel->item(rowNum, 3)->data(Qt::DisplayRole).toString();
        data.taskNum = tableModel->item(rowNum, 4)->data(Qt::DisplayRole).toString();
        data.logMsg = tableModel->item(rowNum, 5)->data(Qt::DisplayRole).toString();
        data.logAttribute = tableModel->item(rowNum, 6)->data(Qt::DisplayRole).toString();
    }
    return data;
}
void LogMsgPage::updateRowData(QVector<RowDataLogMsg>& values)
{
    tableModel->clear();
    tableModel->setHorizontalHeaderLabels(headNames);
    for (int i = 0; i < values.size(); i++)
    {
        QList<QStandardItem*> itemList;
        itemList << new QStandardItem << new QStandardItem(QString::number(tableModel->rowCount() + 1)) << new QStandardItem(values[i].dateTime)
                 << new QStandardItem(values[i].systemName) << new QStandardItem(values[i].taskNum) << new QStandardItem(values[i].logMsg)
                 << new QStandardItem(values[i].logAttribute);
        tableModel->appendRow(itemList);

        //        QPushButton* detailsBtn = new QPushButton("查看详情", this);
        //        detailsBtn->setFlat(true);
        //        detailsBtn->setStyleSheet("color:rgb(0,170,255);font-size:12px;border-style:none;text-align: left;");
        //        //        connect(handleBtn, &QPushButton::clicked, this, &LogMsgPage::delItemClicked);
        //        detailsBtn->setProperty("row", i);
        //        ui->tableView->setIndexWidget(tableModel->index(i, tableModel->columnCount() - 2), detailsBtn);

        //        QPushButton* dealBtn = new QPushButton("处理故障", this);
        //        dealBtn->setFlat(true);
        //        dealBtn->setStyleSheet("color:rgb(0,170,255);font-size:12px;border-style:none;text-align: left;");
        //        //        connect(handleBtn, &QPushButton::clicked, this, &LogMsgPage::delItemClicked);
        //        dealBtn->setProperty("row", i);
        //        ui->tableView->setIndexWidget(tableModel->index(i, tableModel->columnCount() - 1), dealBtn);
    }
}
QVector<RowDataLogMsg> LogMsgPage::getCheckedRowData()
{
    QVector<RowDataLogMsg> datas;
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

void LogMsgPage::delItemClicked()
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

void LogMsgPage::appendRowData(RowDataLogMsg value)
{
    QList<QStandardItem*> itemList;
    itemList << new QStandardItem << new QStandardItem(QString::number(tableModel->rowCount() + 1)) << new QStandardItem(value.dateTime)
             << new QStandardItem(value.systemName) << new QStandardItem(value.taskNum) << new QStandardItem(value.logMsg)
             << new QStandardItem(value.logAttribute);
    tableModel->appendRow(itemList);

    //    QPushButton* detailsBtn = new QPushButton("查看详情", this);
    //    detailsBtn->setFlat(true);
    //    detailsBtn->setStyleSheet("color:rgb(0,170,255);font-size:18px;background-color:transparent;border-style:none;text-align: left;");
    //    //    connect(handleBtn, &QPushButton::clicked, this, &LogMsgPage::delItemClicked);
    //    detailsBtn->setProperty("row", tableModel->rowCount() - 1);
    //    ui->tableView->setIndexWidget(tableModel->index(tableModel->rowCount() - 2, tableModel->columnCount() - 2), detailsBtn);

    //    QPushButton* dealBtn = new QPushButton("处理故障", this);
    //    dealBtn->setFlat(true);
    //    dealBtn->setStyleSheet("color:rgb(0,170,255);font-size:18px;background-color:transparent;border-style:none;text-align: left;");
    //    //    connect(handleBtn, &QPushButton::clicked, this, &LogMsgPage::delItemClicked);
    //    dealBtn->setProperty("row", tableModel->rowCount() - 1);
    //    ui->tableView->setIndexWidget(tableModel->index(tableModel->rowCount() - 1, tableModel->columnCount() - 1), dealBtn);

    ui->tableView->clearSelection();
}
QString LogMsgPage::pasraDoubleToStr(double value, int prsc, char f) { return QString::number(value, f, prsc); }
