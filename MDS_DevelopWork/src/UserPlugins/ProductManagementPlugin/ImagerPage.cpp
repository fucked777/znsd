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
#include <QToolButton>
#include <QTreeWidgetItem>

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
        if (status.taskNum.contains("AFN"))
        {
            continue;
        }
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

void ImagerPage::setArrayDataInterface(/*const QByteArray& array*/)
{
    ImagerData data;
    QList<ImagerData> DATA1;
    for (int i = 0; i < 100; i++)
    {
        if (i == 0 || i % 5 == 0)
        {
            data.taskNum = "AFNXXXXXXXXXX00" + QString::number(i);
            data.outputTime = "";
            data.fileName = "";
            data.LocalFilePath = "";
            data.outputFilePath = "";
            data.sendDirection = "";
            data.sendType = "";
            data.accuracy = "";
            data.outputType = "";
            data.fileSize = "";
        }
        else
        {
            data.taskNum = "序号:" + QString::number(i);
            data.outputTime = "00:13:14";
            data.fileName = "css";
            data.LocalFilePath = "c:xiaoxiao";
            data.outputFilePath = "c:xiaoxiao";
            data.sendDirection = "NRS->CVS";
            data.sendType = "FTP";
            data.accuracy = "XXXXX";
            data.outputType = "NRST100001";
            data.fileSize = "MB";
        }
        DATA1.append(data);
        m_pageNavigator->m_pDataModel->setImagerData(DATA1);
        m_pageNavigator->UpdateStatus();
    }
}
void ImagerPage::deal_expand_collapse()
{
    //隐藏
    QToolButton* button = dynamic_cast<QToolButton*>(sender());
    QVariant val = button->property("row");
    int row = 0;
    if (val.isValid())
    {
        row = val.toInt();
    }
    for (int i = row + 1; i < row + 5; i++)
    {
        //        ui->tableView->setRowHidden()
        ui->tableView->setRowHidden(i, status[row]);
    }
    status[row] = !status[row];
}

void ImagerPage::searchSlot(const QStringList& taskName, const QStringList& taskNum, const QStringList& fileName, const QStringList& outputType,
                            const QDateTime& start_time, const QDateTime& end_time)
{
    //    int pageSize = ui->comboBox->currentData().toInt();
    //    m_pageNavigator->m_pDataModel->reset(taskName, taskNum, fileName, outputType, start_time, end_time, 1, pageSize);
}

void ImagerPage::slotUpdataTable()
{
    ui->tableView->reset();

    QList<ImagerData> data = m_pageNavigator->m_pDataModel->GetPageArrayData();
    for (int i = 0; i < data.size(); i++)
    {
        QModelIndex indexValue = m_pageNavigator->m_pDataModel->index(i, 0);
        QVariant x = m_pageNavigator->m_pDataModel->data(indexValue, Qt::DisplayRole);
        QString str = x.toString();
        if (str.contains("AFN"))
        {
            QToolButton* detailsBtn = new QToolButton(this);
            detailsBtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
            detailsBtn->setText("AFNXXXXXXXXXX01");
            detailsBtn->setIcon(QIcon(":/znsd/image/arrow_bottom.png"));
            detailsBtn->setStyleSheet("color:rgb(0,170,255);font-size:14px;border-style:none;text-align: left;");
            detailsBtn->setProperty("row", i);

            connect(detailsBtn, &QToolButton::clicked, this, [=]() {
                if (status[i])
                    detailsBtn->setIcon(QIcon(":/znsd/image/arrow_forward.png"));
                else
                {
                    detailsBtn->setIcon(QIcon(":/znsd/image/arrow_bottom.png"));
                }
                deal_expand_collapse();
            });
            //            connect(detailsBtn, &QToolButton::clicked, this, &ImagerPage::deal_expand_collapse);

            status[i] = true;
            ui->tableView->setIndexWidget(m_pageNavigator->m_pDataModel->index(i, 0), detailsBtn);
        }
    }
}
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
    //    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);  //设置选中模式为选中行
}

QString ImagerPage::pasraDoubleToStr(double value, int prsc, char f) { return QString::number(value, f, prsc); }
