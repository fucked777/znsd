#include "ImagerPage.h"
#include "CArrayModel.h"
#include "QueryDialog_CXY.h"
#include "SqlImagerManager.h"
#include "pageWidget.h"
#include "ui_ImagerPage.h"
#include <QDebug>
#include <QFile>
const int MAX_INSERT_NUM = 1000;

ImagerPage::ImagerPage(QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::ImagerPage)
{
    ui->setupUi(this);
    m_queryDialog_CXY = new QueryDialog_CXY();
    m_queryDialog_CXY->setWindowModality(Qt::ApplicationModal);
    m_sqlImagerManager = new SqlImagerManager();
    connect(m_queryDialog_CXY, &QueryDialog_CXY::search, this, &ImagerPage::searchSlot);
    initMember();
    initView();
}

ImagerPage::~ImagerPage() { delete ui; }

void ImagerPage::queryBtnClicked() { m_queryDialog_CXY->show(); }

void ImagerPage::reportBtnClicked()
{
    QFile f("test.csv");
    f.open(QIODevice::WriteOnly);
    QStringList text;
    for (int i = 0; i < m_pageNavigator->m_pDataModel->RowCount(); ++i)
    {
        for (int j = 0; j < m_pageNavigator->m_pDataModel->ColumnCount(); ++j)
        {
            //            QString item = ui->tableView.it
            //            QVariant item=  m_pageNavigator->m_pDataModel->data(Qt::DisplayRole).toString();
            //            text << item;
        }
        f.write(text.join(",").toUtf8() + "\r\n");
        text.clear();
    }
    f.close();
}

void ImagerPage::allBtnClicked() {}

void ImagerPage::initMember()
{
    m_pageNavigator = new pageWidget();
    ui->widget->layout()->addWidget(m_pageNavigator);
    ui->tableView->setModel(m_pageNavigator->m_pDataModel);
    //更新表格
    connect(m_pageNavigator, &pageWidget::updataTableView, this, &ImagerPage::slotUpdataTable);
    ImagerData data;
    ImagerDataList DATA;
    for (int i = 1; i < 101; i++)
    {
        data.taskNum = QString::number(i);
        data.outputTime = "00:13:14";
        data.fileName = "css";
        data.LocalFilePath = "c:xiaoxiao";
        data.outputFilePath = "c:xiaoxiao";
        data.sendDirection = "NRS->CVS";
        data.sendType = "FTP";
        data.accuracy = "XXXXX";
        data.outputType = "NRST100001";
        data.fileSize = QString::number(i) + "MB";
        DATA.append(data);
    }
    m_sqlImagerManager->insert(DATA);
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

    connect(ui->allBtn, &QPushButton::clicked, this, &ImagerPage::allBtnClicked);
    connect(ui->queryBtn, &QPushButton::clicked, this, &ImagerPage::queryBtnClicked);
    connect(ui->reportBtn, &QPushButton::clicked, this, &ImagerPage::reportBtnClicked);
}

void ImagerPage::searchSlot(const QStringList& taskName, const QStringList& taskNum, const QStringList& fileName, const QStringList& outputType,
                            const QDateTime& start_time, const QDateTime& end_time)
{
    //    int pageSize = ui->comboBox->currentData().toInt();
    //    m_deviceStatusLogTableModel->reset(taskName, taskNum, fileName, outputType, start_time, end_time, 1, pageSize);
}

void ImagerPage::slotUpdataTable() { ui->tableView->reset(); }
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
    ui->tableView->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->tableView->viewport()->installEventFilter(this);
    ui->tableView->viewport()->setMouseTracking(true);
    ui->tableView->verticalHeader()->setVisible(false);  // 垂直不可见
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->horizontalHeader()->setDefaultAlignment(Qt::AlignVCenter);
    ui->tableView->setEditTriggers(QAbstractItemView::DoubleClicked);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);  //设置选中模式为选中行
}

QString ImagerPage::pasraDoubleToStr(double value, int prsc, char f) { return QString::number(value, f, prsc); }
