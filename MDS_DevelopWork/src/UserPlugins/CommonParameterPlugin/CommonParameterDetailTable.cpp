#include "CommonParameterDetailTable.h"
#include "QStandardItemModel"
#include "ui_CommonParameterDetailTable.h"
#include <QMessageBox>
#include <QMouseEvent>
#include <QPushButton>
#include <QStandardItem>

CommonParameterDetailTable::CommonParameterDetailTable(QWidget* parent, int blueColumn, QStringList headNames)
    : QWidget(parent)
    , ui(new Ui::CommonParameterDetailTable)
    , headNames(headNames)
    , blueColumn(blueColumn)
{
    ui->setupUi(this);
    initMember();
    initView();
}

CommonParameterDetailTable::~CommonParameterDetailTable() { delete ui; }

void CommonParameterDetailTable::updateRowData(QList<CommonParameterDetail>& values)
{
    tableModel->clear();
    tableModel->setHorizontalHeaderLabels(headNames);
    for (int i = 0; i < values.size(); i++)
    {
        QList<QStandardItem*> itemList;
        itemList << new QStandardItem(values[i].parameterName) << new QStandardItem(values[i].chineseName)
                 << new QStandardItem(values[i].value.toString());
        tableModel->appendRow(itemList);
    }
}

void CommonParameterDetailTable::appendRowData(CommonParameterDetail value)
{
    tableModel->clear();
    QList<QStandardItem*> itemList;
    itemList << new QStandardItem(value.parameterName) << new QStandardItem(value.chineseName) << new QStandardItem(value.value.toString());
    tableModel->appendRow(itemList);
    //    ui->TableView->clearSelection();
}

QString CommonParameterDetailTable::parseDoubleToStr(double value, char f, int prsc) { return QString::number(value, f, prsc); }

void CommonParameterDetailTable::mouseDoubleClickEvent(QMouseEvent* event) {}

void CommonParameterDetailTable::initMember()
{
    headNames << "参数名称"
              << "中文名称"
              << "参数";

    tableModel = new QStandardItemModel(this);
    ui->TableView->setModel(tableModel);

    tableModel->setHorizontalHeaderLabels(headNames);
    ui->TableView->horizontalHeader()->setVisible(true);
}

void CommonParameterDetailTable::destroyMember() {}

void CommonParameterDetailTable::initView()
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
