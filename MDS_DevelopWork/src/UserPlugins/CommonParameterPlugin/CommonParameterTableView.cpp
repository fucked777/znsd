#include "CommonParameterTableView.h"
//#include "HeaderView.h"
//#include "NotEditableDelegate.h"
#include "QStandardItemModel"
#include "ui_CommonParameterTableView.h"
#include <QMessageBox>
#include <QMouseEvent>
#include <QPushButton>
#include <QRandomGenerator>
#include <QStandardItem>

CommonParameterTableView::CommonParameterTableView(QWidget* parent, int blueColumn, QStringList headNames)
    : QWidget(parent)
    , ui(new Ui::CommonParameterTableView)
    , headNames(headNames)
    , blueColumn(blueColumn)
{
    ui->setupUi(this);
    initMember();
    initView();
}

CommonParameterTableView::~CommonParameterTableView() { delete ui; }

void CommonParameterTableView::updateRowData(QList<CommonParameter>& values)
{
    tableModel->clear();
    tableModel->setHorizontalHeaderLabels(headNames);
    for (int i = 0; i < values.size(); i++)
    {
        QList<QStandardItem*> itemList;
        itemList << new QStandardItem(values[i].fileType) << new QStandardItem(values[i].fileName)
                 << new QStandardItem(values[i].getTime /*.toString("yyyy-MM-dd hh:mm:ss")*/)
                 << new QStandardItem(values[i].useTime /*.toString("yyyy-MM-dd hh:mm:ss")*/) << new QStandardItem;
        tableModel->appendRow(itemList);

        QPushButton* handleBtn = new QPushButton("查看详情", this);
        handleBtn->setFlat(true);
        handleBtn->setStyleSheet("color:rgb(0,170,255);font-size:14px;border-style:none;text-align: left;");
        connect(handleBtn, &QPushButton::clicked, this, &CommonParameterTableView::ViewDetailsBtnClicked);
        handleBtn->setProperty("row", i);
        ui->TableView->setIndexWidget(tableModel->index(i, tableModel->columnCount() - 1), handleBtn);
    }
}

void CommonParameterTableView::appendRowData(CommonParameter value)
{
    QList<QStandardItem*> itemList;
    itemList << new QStandardItem(value.fileType) << new QStandardItem(value.fileName)
             << new QStandardItem(value.getTime /*.toString("yyyy-MM-dd hh:mm:ss")*/)
             << new QStandardItem(value.useTime /*.toString("yyyy-MM-dd hh:mm:ss")*/) << new QStandardItem;
    tableModel->appendRow(itemList);

    QPushButton* handleBtn = new QPushButton("删除", this);
    handleBtn->setFlat(true);
    handleBtn->setStyleSheet("color:rgb(0,170,255);font-size:18px;background-color:transparent;border-style:none;text-align: left;");
    connect(handleBtn, &QPushButton::clicked, this, &CommonParameterTableView::ViewDetailsBtnClicked);
    handleBtn->setProperty("row", tableModel->rowCount() - 1);
    ui->TableView->setIndexWidget(tableModel->index(tableModel->rowCount() - 1, tableModel->columnCount() - 1), handleBtn);
}

QString CommonParameterTableView::parseDoubleToStr(double value, char f, int prsc) { return QString::number(value, f, prsc); }

void CommonParameterTableView::ViewDetailsBtnClicked()
{
    QStringList Parameter;
    QPushButton* button = dynamic_cast<QPushButton*>(sender());
    QVariant val = button->property("row");
    int row = 0;
    if (val.isValid())
    {
        row = val.toInt();
    }
    for (int i = 0; i < tableModel->columnCount() - 1; i++)
    {
        QModelIndex indexValue = tableModel->index(row, i);
        QVariant dataValue = tableModel->data(indexValue, Qt::DisplayRole);
        Parameter << dataValue.toString();
    }
    emit dataSendSignal(Parameter);
}

void CommonParameterTableView::mouseDoubleClickEvent(QMouseEvent* event) {}

void CommonParameterTableView::initMember()
{
    headNames << "参数类型"
              << "参数文件名称"
              << "获取时间"
              << "启用时间"
              << "操作";
    //    paraNames << "卫星平台参数"
    //              << "指令参数生成相关参数";
    tableModel = new QStandardItemModel(/*paraNames.size(), headNames.size(),*/ this);
    ui->TableView->setModel(tableModel);

    tableModel->setHorizontalHeaderLabels(headNames);

    //    for (int i = 0; i < paraNames.size(); i++)
    //    {
    //        tableModel->setData(tableModel->index(i, 0), paraNames.at(i));
    //    }
    CommonParameterDataList dataList;
    CommonParameter data;
    for (int i = 0; i < 50; i++)
    {
        data.fileType = "卫星平台参数" + QString::number(i);
        data.fileName = "IFLSatPlatPara.xml" + QString::number(i);
        data.getTime = "11";
        data.useTime = "11" + QString::number(i);
        dataList << data;
    }
    updateRowData(dataList);
}

void CommonParameterTableView::destroyMember() {}

void CommonParameterTableView::initView()
{
    ui->TableView->setShowGrid(false);
    //    ui->tableView->horizontalHeader()->setVisible(false);  // 水平不可见
    ui->TableView->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->TableView->viewport()->installEventFilter(this);
    ui->TableView->viewport()->setMouseTracking(true);
    ui->TableView->verticalHeader()->setVisible(false);  // 垂直不可见
    ui->TableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->TableView->horizontalHeader()->setDefaultAlignment(Qt::AlignVCenter);
    ui->TableView->setEditTriggers(QAbstractItemView::DoubleClicked);
    ui->TableView->setSelectionBehavior(QAbstractItemView::SelectRows);  //设置选中模式为选中行
}
