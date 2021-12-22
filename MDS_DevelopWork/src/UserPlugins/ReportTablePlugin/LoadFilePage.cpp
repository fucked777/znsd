#include "LoadFilePage.h"
#include "ui_LoadFilePage.h"
#include <QDebug>
#pragma execution_character_set("utf-8")
const int MAX_INSERT_NUM = 1000;

LoadFilePage::LoadFilePage(QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::LoadFilePage)
{
    ui->setupUi(this);
    initMember();
    initView();
}

LoadFilePage::~LoadFilePage() { delete ui; }

void LoadFilePage::queryBtnClicked() {}

void LoadFilePage::reportBtnClicked() {}

// void LoadFilePage::okBtnClicked()
//{
//    m_datas = freqTableView->getCheckedRowDataLSSMs();
//    emit settingDlgCloseSignal(1, m_datas.size());
//    accept();
//    QVariant index = freqTableView->getRowCount();
//    NSGlobal::RowDataLoadFileMsg dataSaveInfoMap;
//    QVector<NSGlobal::LSSMFreqTableRowData> dataSave;
//    dataSave = freqTableView->getDataInfo(dataSaveInfoMap);
//    emit updateFreTableNumber(6, 0, index.toString(), "个");  //更新频率表个数
//    m_datas = dataSave;
//    emit dataSaveSignal(dataSave);
//}

void LoadFilePage::delItemClicked(const int rowIndex)
{
    //    QVector<RowDataLoadFileMsg> datas;
    //    datas << freqTableView->getRowDataLSSM(rowIndex);
    //    freqAnalyse->dels(datas);
    //    datas.clear();
    //    datas = freqAnalyse->query();
    //    freqTableView->updateRowDataLSSM(datas);
}

void LoadFilePage::initView()
{
    ui->tableView->verticalHeader()->setVisible(false);  // 垂直不可见
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->horizontalHeader()->setDefaultAlignment(Qt::AlignVCenter);
    ui->tableView->setEditTriggers(QAbstractItemView::DoubleClicked);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);  //设置选中模式为选中行
}

void LoadFilePage::initMember()
{
    connect(ui->queryBtn, &QPushButton::clicked, this, &LoadFilePage::queryBtnClicked);

    connect(ui->reportBtn, &QPushButton::clicked, this, &LoadFilePage::reportBtnClicked);

    ui->tableView->viewport()->installEventFilter(this);
    ui->tableView->viewport()->setMouseTracking(true);

    tableModel = new QStandardItemModel(this);
    ui->tableView->setModel(tableModel);

    //    checkBoxDelegate = new CheckBoxDelegate(this);
    //    notEditableDelegate = new NotEditableDelegate(ui->tableView);
    ui->tableView->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    //    ui->tableView->setItemDelegateForColumn(0, checkBoxDelegate);
    //    ui->tableView->setItemDelegate(notEditableDelegate);
    //    connect(notEditableDelegate, &NotEditableDelegate::checkCurrRowSignal, this, &FaultMsgPage::checkCurrRowSlot);
    ui->comboBox->addItem("25");
    ui->comboBox->addItem("50");
    ui->comboBox->addItem("80");
    ui->comboBox->addItem("100");
    //    connect(ui->comboBox, &QComboBox::currentTextChanged, this, &FaultMsgPage::curTestChangedCombox);
    //    datas.clear();
    columnWidths.clear();
    columnWidths.push_back(120);
    columnWidths.push_back(120);
    columnWidths.push_back(120);
    columnWidths.push_back(120);
    columnWidths.push_back(120);
    columnWidths.push_back(120);
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
        headNames << "载荷名称"
                  << "任务编号"
                  << "任务状态"
                  << "任务实际执行时间"
                  << "L0第一行到达时间"
                  << "L0最后一行到达时间"
                  << "实际收到L0总数"
                  << "获取L0总时间"
                  << "生成L1A第一行时间"
                  << "L1A最后一个文件时间"
                  << "生成L1A总数"
                  << "L1A生成总时间";

    tableModel->setHorizontalHeaderLabels(headNames);
    //    tableModel->setRowCount(1);
    //    headerView = new HeaderView(Qt::Horizontal, this);
    //    connect(headerView, &HeaderView::selectOrDeselectAll, this, &FaultMsgPage::selectAllItems);
    //    ui->tableView->setHorizontalHeader(headerView);

    ui->tableView->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    //    m_freQuencyInput = new FreQuencyInput(this);
    //    connect(m_freQuencyInput, &FreQuencyInput::pointAddParameterValueSignal, this, &LoadFilePage::pointAddParameterValueSlot);
    //    freqTableView = new LSSMFreqTableView(ui->freqTableView);
    //    ui->freqTableView->layout()->addWidget(freqTableView);
    //    connect(freqTableView, &LSSMFreqTableView::sigDelItemClicked, this, &LoadFilePage::delItemClicked);

    //    setMode(POINT_TYPE);
    //    freqAnalyse = new FreqTableAnalyse_LSSM("Datas/LSSM/rawdata/freq.dat");
    //    if (freqAnalyse)
    //    {
    //        QVector<RowDataLoadFileMsg> datas = freqAnalyse->query();
    //        freqTableView->updateRowDataLSSM(datas);
    //    }
}

QString LoadFilePage::pasraDoubleToStr(double value, int prsc, char f) { return QString::number(value, f, prsc); }
void LoadFilePage::pointAddParameterValueSlot(const int& type, const QStringList& value1) {}
