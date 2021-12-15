#include "CommonParameterDetailTable.h"
//#include "HeaderView.h"
//#include "NotEditableDelegate.h"
#include "QStandardItemModel"
#include "ui_CommonParameterDetailTable.h"
#include <QMessageBox>
#include <QMouseEvent>
#include <QPushButton>
#include <QRandomGenerator>
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

void CommonParameterDetailTable::updateRowData(QVector<CommonParameterDetail>& values)
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
int CommonParameterDetailTable::getRowCount() { return tableModel->rowCount(); }

// void CommonParameterDetailTable::appendRowDataLSSM(RowDataKZQ value)
//{
//    QList<QStandardItem*> itemList;
//    itemList << new QStandardItem << new QStandardItem(QString::number(tableModel->rowCount() + 1)) << new QStandardItem(value.KZQ_ID)
//             << new QStandardItem(value.recive_signal) << new QStandardItem(parseDoubleToStr(value.Voltage, 'f', 3))
//             << new QStandardItem /*(values[i].Equipment_status)*/ << new QStandardItem;

//    QPushButton* handleBtn = new QPushButton("删除", this);
//    handleBtn->setFlat(true);
//    handleBtn->setStyleSheet("color:rgb(0,170,255);font-size:18px;background-color:transparent;border-style:none;text-align: left;");
//    connect(handleBtn, &QPushButton::clicked, this, &CommonParameterDetailTable::delItemClicked);
//    handleBtn->setProperty("row", tableModel->rowCount() - 1);
//    ui->KZQTable->setIndexWidget(tableModel->index(tableModel->rowCount() - 1, tableModel->columnCount() - 1), handleBtn);

//    tableModel->appendRow(itemList);
//    ui->KZQTable->clearSelection();
//}

// QVector<RowDataKZQ> CommonParameterDetailTable::getCheckedRowDataLSSMs()
//{
//    QVector<RowDataKZQ> datas;
//    for (int i = 0; i < tableModel->rowCount(); i++)
//    {
//        bool isSelected = tableModel->item(i, 0)->data(Qt::UserRole).toBool();
//        if (isSelected)
//        {
//            datas << getRowDataLSSM(i);
//        }
//    }
//    return datas;
//}
// QVector<NSGlobal::LSSMFreqTableRowData> CommonParameterDetailTable::getDataInfo(RowDataKZQ)
//{
//    QAbstractItemModel* model = ui->KZQTable->model();
//    RowDataKZQ values;
//    QVector<NSGlobal::LSSMFreqTableRowData> dataSave;
//    for (int i = 0; i < tableModel->rowCount(); i++)
//    {
//        QModelIndex indexValue = model->index(i, 2);
//        QVariant datafre = model->data(indexValue);  //获取中心频率
//        QModelIndex indexUnit = model->index(i, 3);
//        QVariant databand = model->data(indexUnit);  //获取中频带宽
//                                                     //        values.centerFreq = datafre.toDouble() * 1000;
//                                                     //        values.span = databand.toDouble() * 1000;
//                                                     //        if (removeRowIndexs.contains(i))
//                                                     //        {
//                                                     //            dataSave.push_back(values);
//                                                     //        }
//                                                     //        else
//                                                     //        {
//                                                     //            continue;
//                                                     //        }
//    }
//    return dataSave;
//}
// CommonParameterDetailTable::getRowDataLSSM(const int rowNum)
//{
//    RowDataKZQ data;
//    //    if (rowNum >= 0 && rowNum < tableModel->rowCount())
//    //    {
//    //        data.centerFreq = tableModel->item(rowNum, 2)->data(Qt::DisplayRole).toDouble();
//    //        data.span = tableModel->item(rowNum, 3)->data(Qt::DisplayRole).toDouble();
//    //    }
//    return data;
//}

QString CommonParameterDetailTable::parseDoubleToStr(double value, char f, int prsc) { return QString::number(value, f, prsc); }

int CommonParameterDetailTable::getBlueColumn() const { return blueColumn; }

void CommonParameterDetailTable::checkCurrRowSlot(int rowIndex, bool checked)
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
void CommonParameterDetailTable::selectAllItems(Qt::CheckState state)
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

void CommonParameterDetailTable::mouseDoubleClickEvent(QMouseEvent* event) {}

void CommonParameterDetailTable::initMember()
{
    headNames << "参数名称"
              << "中文名称"
              << "参数";
    columnWidths.clear();
    columnWidths.push_back(53);
    columnWidths.push_back(53);
    columnWidths.push_back(53);

    for (int i = 0; i < headNames.size(); i++)
    {
        totleColumnWidth += columnWidths.at(i);
    }

    tableModel = new QStandardItemModel(this);
    ui->TableView->setModel(tableModel);

    tableModel->setHorizontalHeaderLabels(headNames);
    ui->TableView->horizontalHeader()->setVisible(true);

    //    horeHeaderView = ui->TableView->horizontalHeader();
    //    horeHeaderView->setDefaultAlignment(Qt::AlignVCenter);
    //    horeHeaderView->setSectionResizeMode(QHeaderView::Fixed);
}

void CommonParameterDetailTable::destroyMember() {}

void CommonParameterDetailTable::initView()
{
    //    ui->KZQTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //    ui->KZQTable->horizontalHeader()->setDefaultAlignment(Qt::AlignVCenter);
    ui->TableView->setEditTriggers(QAbstractItemView::DoubleClicked);
}

void CommonParameterDetailTable::resizeEvent(QResizeEvent* event)
{
    Q_UNUSED(event);

    m_scale = ui->TableView->width() / totleColumnWidth;

    for (int i = 0; i < 3; i++)
        ui->TableView->setColumnWidth(i, columnWidths.at(i) * m_scale);
}

bool CommonParameterDetailTable::eventFilter(QObject* obj, QEvent* event)
{
    if (blueColumn >= 0)
        if (event->type() == QEvent::MouseButtonRelease)
        {
            int selectedRow = ui->TableView->selectionModel()->selectedRows()[0].row();
            QStandardItem* itemCurrSelected = tableModel->item(selectedRow, blueColumn);
            itemCurrSelected->setForeground(QBrush(QColor(0, 0, 0)));  ////unsolved:when selected turn black
            if (itemLastSelected)
                itemLastSelected->setForeground(QBrush(QColor(0, 170, 255)));
            itemLastSelected = itemCurrSelected;
        }
    return QWidget::eventFilter(obj, event);
}
