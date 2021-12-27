#include "ImagerPage.h"
#include "CArrayModel.h"
#include "QueryDialog_CXY.h"
#include "pageWidget.h"
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
}

ImagerPage::~ImagerPage() { delete ui; }

void ImagerPage::queryBtnClicked() { m_queryDialog_CXY->show(); }

void ImagerPage::reportBtnClicked() {}

void ImagerPage::allBtnClicked() {}

void ImagerPage::initMember()
{
    connect(ui->allBtn, &QPushButton::clicked, this, &ImagerPage::allBtnClicked);
    connect(ui->queryBtn, &QPushButton::clicked, this, &ImagerPage::queryBtnClicked);
    connect(ui->reportBtn, &QPushButton::clicked, this, &ImagerPage::reportBtnClicked);
    //    connect(ui->okBtn, &QPushButton::clicked, this, &ImagerPage::okBtnClicked);
    //    connect(ui->comboBox, &QComboBox::currentTextChanged, this, &ImagerPage::pageSizeChange);
    m_pageNavigator = new pageWidget();
    ui->widget->layout()->addWidget(m_pageNavigator);
    //更新表格
    connect(m_pageNavigator, &pageWidget::updataTableView, this, &ImagerPage::slotUpdataTable);
    //    m_imagerTableModel = new CArrayModel();

    ui->tableView->setModel(m_pageNavigator->m_pDataModel);

    //    connect(m_deviceStatusLogTableModel, &DeviceStatusLogTableModel::signalTotalCount, this, &ImagerPage::slotGetTotalCount);

    ui->tableView->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->tableView->viewport()->installEventFilter(this);
    ui->tableView->viewport()->setMouseTracking(true);

    //设置委托
    //    ui->tableView->setItemDelegateForColumn(0, new ReadOnlyDelegate(this));
    for (int i = 0; i < 10; i++)
    {
        ui->tableView->setItemDelegateForColumn(i, new ValueDelegate(this));
    }
    //刷新状态
    //    m_pageNavigator->UpdateStatus();
}
void ImagerPage::slotGetTotalCount(const int totalCount, const int currentPage)
{
    //    int pageSize = ui->comboBox->currentData().toInt();
    //    int pageNum = totalCount / pageSize + ((totalCount % pageSize) ? 1 : 0);
    //    m_pageNavigator->setMaxPage(pageNum);
    //    m_pageNavigator->setCurrentPage(currentPage);
}

void ImagerPage::searchSlot(const QStringList& taskName, const QStringList& taskNum, const QStringList& fileName, const QStringList& outputType,
                            const QDateTime& start_time, const QDateTime& end_time)
{
    //    int pageSize = ui->comboBox->currentData().toInt();
    //    m_deviceStatusLogTableModel->reset(taskName, taskNum, fileName, outputType, start_time, end_time, 1, pageSize);
}

void ImagerPage::slotUpdataTable()
{
    qDebug() << "1111";
    ui->tableView->reset();
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
    //    int pageSize = ui->comboBox->currentData().toInt();
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

QString ImagerPage::pasraDoubleToStr(double value, int prsc, char f) { return QString::number(value, f, prsc); }
