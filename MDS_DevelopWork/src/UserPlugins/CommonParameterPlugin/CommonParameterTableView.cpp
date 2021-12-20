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

void CommonParameterTableView::updateRowData(QVector<CommonParameter>& values)
{
    tableModel->clear();
    tableModel->setHorizontalHeaderLabels(headNames);
    for (int i = 0; i < values.size(); i++)
    {
        QList<QStandardItem*> itemList;
        itemList << new QStandardItem(values[i].fileType) << new QStandardItem(values[i].fileName)
                 << new QStandardItem(values[i].getTime.toString("yyyy-MM-dd hh:mm:ss"))
                 << new QStandardItem(values[i].useTime.toString("yyyy-MM-dd hh:mm:ss")) << new QStandardItem;
        tableModel->appendRow(itemList);

        QPushButton* handleBtn = new QPushButton("查看详情", this);
        handleBtn->setFlat(true);
        handleBtn->setStyleSheet("color:white;font-size:18px;border-style:none;text-align: left;");
        connect(handleBtn, &QPushButton::clicked, this, &CommonParameterTableView::ViewDetailsBtnClicked);
        handleBtn->setProperty("row", i);
        ui->TableView->setIndexWidget(tableModel->index(i, tableModel->columnCount() - 1), handleBtn);
    }
}
int CommonParameterTableView::getRowCount() { return tableModel->rowCount(); }

// void CommonParameterTableView::appendRowDataLSSM(RowDataKZQ value)
//{
//    QList<QStandardItem*> itemList;
//    itemList << new QStandardItem << new QStandardItem(QString::number(tableModel->rowCount() + 1)) << new QStandardItem(value.KZQ_ID)
//             << new QStandardItem(value.recive_signal) << new QStandardItem(parseDoubleToStr(value.Voltage, 'f', 3))
//             << new QStandardItem /*(values[i].Equipment_status)*/ << new QStandardItem;

//    QPushButton* handleBtn = new QPushButton("删除", this);
//    handleBtn->setFlat(true);
//    handleBtn->setStyleSheet("color:rgb(0,170,255);font-size:18px;background-color:transparent;border-style:none;text-align: left;");
//    connect(handleBtn, &QPushButton::clicked, this, &CommonParameterTableView::delItemClicked);
//    handleBtn->setProperty("row", tableModel->rowCount() - 1);
//    ui->KZQTable->setIndexWidget(tableModel->index(tableModel->rowCount() - 1, tableModel->columnCount() - 1), handleBtn);

//    tableModel->appendRow(itemList);
//    ui->KZQTable->clearSelection();
//}

// QVector<RowDataKZQ> CommonParameterTableView::getCheckedRowDataLSSMs()
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
// QVector<NSGlobal::LSSMFreqTableRowData> CommonParameterTableView::getDataInfo(RowDataKZQ)
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
// CommonParameterTableView::getRowDataLSSM(const int rowNum)
//{
//    RowDataKZQ data;
//    //    if (rowNum >= 0 && rowNum < tableModel->rowCount())
//    //    {
//    //        data.centerFreq = tableModel->item(rowNum, 2)->data(Qt::DisplayRole).toDouble();
//    //        data.span = tableModel->item(rowNum, 3)->data(Qt::DisplayRole).toDouble();
//    //    }
//    return data;
//}

QString CommonParameterTableView::parseDoubleToStr(double value, char f, int prsc) { return QString::number(value, f, prsc); }

int CommonParameterTableView::getBlueColumn() const { return blueColumn; }

void CommonParameterTableView::ViewDetailsBtnClicked()
{
    //    int rowIndex = ui->TableView->currentIndex().row();
    //    int pos = -1;
    //    for (int i = 0; i < removeRowIndexs.size(); i++)
    //    {
    //        if (removeRowIndexs.at(i) == rowIndex)
    //            pos = i;
    //        else if (removeRowIndexs.at(i) > rowIndex)
    //            removeRowIndexs[i]--;
    //    }
    //    if (pos != -1)
    //        removeRowIndexs.removeAt(pos);
    //    QPushButton* button = dynamic_cast<QPushButton*>(sender());
    //    QVariant val = button->property("row");
    //    if (val.isValid())
    //    {
    //        int row = val.toInt();
    //        emit sigDelItemClicked(row);
    //    }
}
void CommonParameterTableView::checkCurrRowSlot(int rowIndex, bool checked)
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
void CommonParameterTableView::selectAllItems(Qt::CheckState state)
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

void CommonParameterTableView::mouseDoubleClickEvent(QMouseEvent* event) {}

void CommonParameterTableView::initMember()
{
    headNames << "参数类型"
              << "参数文件名称"
              << "获取时间"
              << "启用时间"
              << "操作";
    paraNames << "卫星平台参数"
              << "指令参数生成相关参数";

    columnWidths.clear();

    columnWidths.push_back(112);
    columnWidths.push_back(53);
    columnWidths.push_back(53);
    columnWidths.push_back(53);
    columnWidths.push_back(53);

    for (int i = 0; i < headNames.size(); i++)
    {
        totleColumnWidth += columnWidths.at(i);
    }

    tableModel = new QStandardItemModel(paraNames.size(), headNames.size(), this);
    ui->TableView->setModel(tableModel);

    tableModel->setHorizontalHeaderLabels(headNames);
    ui->TableView->horizontalHeader()->setVisible(true);

    //    horeHeaderView = ui->TableView->horizontalHeader();
    //    horeHeaderView->setDefaultAlignment(Qt::AlignVCenter);
    //    horeHeaderView->setSectionResizeMode(QHeaderView::Fixed);

    for (int i = 0; i < paraNames.size(); i++)
    {
        tableModel->setData(tableModel->index(i, 0), paraNames.at(i));
    }
}

void CommonParameterTableView::destroyMember() {}

void CommonParameterTableView::initView()
{
    //    ui->TableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //    ui->TableView->horizontalHeader()->setDefaultAlignment(Qt::AlignVCenter);
    ui->TableView->setEditTriggers(QAbstractItemView::DoubleClicked);
}

void CommonParameterTableView::resizeEvent(QResizeEvent* event)
{
    Q_UNUSED(event);

    m_scale = ui->TableView->width() / totleColumnWidth;

    for (int i = 0; i < 5; i++)
    {
        ui->TableView->setColumnWidth(i, columnWidths.at(i) * m_scale);
    }
}

bool CommonParameterTableView::eventFilter(QObject* obj, QEvent* event)
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

QStringList CommonParameterTableView::getParaNames() const { return paraNames; }
