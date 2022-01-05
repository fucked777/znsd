#include "ImagerPage.h"
#include "CArrayModel.h"
#include "QueryDialog_CXY.h"
#include "SqlImagerManager.h"
#include "pageWidget.h"
#include "ui_ImagerPage.h"
#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
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
    setArrayDataInterface();
}

ImagerPage::~ImagerPage() { delete ui; }

void ImagerPage::queryBtnClicked() { m_queryDialog_CXY->show(); }

void ImagerPage::exportStatus()
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

void ImagerPage::processExport(const QString& fileName)
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
        stream << QString("任务编号：").toUtf8() << status.taskNum << QString("     ").toUtf8() << QString("输出时间：").toUtf8()
               << status.outputTime.toUtf8() << QString("     ").toUtf8() << QString("文件名称：").toUtf8() << status.fileName.toUtf8()
               << QString("     ").toUtf8() << QString("本地文件路径：").toUtf8() << status.LocalFilePath.toUtf8() << QString("     ").toUtf8()
               << QString("输出文件路径").toUtf8() << status.outputFilePath.toUtf8() << QString("     ").toUtf8() << QString("传输方向：").toUtf8()
               << status.sendDirection.toUtf8() << QString("     ").toUtf8() << QString("传输方式：").toUtf8() << status.sendType.toUtf8()
               << QString("     ").toUtf8() << QString("精度：").toUtf8() << status.accuracy.toUtf8() << QString("     ").toUtf8()
               << QString("输出类型：").toUtf8() << status.outputType.toUtf8() << QString("     ").toUtf8() << QString("文件大小：").toUtf8()
               << status.fileSize.toUtf8() << QString("     ").toUtf8() << '\n';
    }
    file.close();
}

void ImagerPage::allBtnClicked() {}

void ImagerPage::initMember()
{
    m_pageNavigator = new pageWidget();
    ui->widget->layout()->addWidget(m_pageNavigator);
    ui->tableView->setModel(m_pageNavigator->m_pDataModel);
    //更新表格
    connect(m_pageNavigator, &pageWidget::updataTableView, this, &ImagerPage::slotUpdataTable);
    connect(ui->allBtn, &QPushButton::clicked, this, &ImagerPage::allBtnClicked);
    connect(ui->queryBtn, &QPushButton::clicked, this, &ImagerPage::queryBtnClicked);
    connect(ui->reportBtn, &QPushButton::clicked, this, &ImagerPage::exportStatus);
}

void ImagerPage::setArrayDataInterface()
{
    ImagerData data;
    ImagerDataList DATA;
    for (int i = 1; i < 101; i++)
    {
        data.taskNum = QString::number(1);
        if (!data.taskNum.isEmpty())
        {
            break;
        }
        else
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
        }

        DATA.append(data);
    }
    //    m_sqlImagerManager->insert(DATA);
    m_pageNavigator->m_pDataModel->SetArrayData(DATA);
    m_pageNavigator->m_pDataModel->SetPageSize(20);
    m_pageNavigator->UpdateStatus();
}

void ImagerPage::searchSlot(const QStringList& taskName, const QStringList& taskNum, const QStringList& fileName, const QStringList& outputType,
                            const QDateTime& start_time, const QDateTime& end_time)
{
    //    int pageSize = ui->comboBox->currentData().toInt();
    //    m_pageNavigator->m_pDataModel->reset(taskName, taskNum, fileName, outputType, start_time, end_time, 1, pageSize);
}

void ImagerPage::slotUpdataTable() { ui->tableView->reset(); }
void ImagerPage::initView()
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

QString ImagerPage::pasraDoubleToStr(double value, int prsc, char f) { return QString::number(value, f, prsc); }
