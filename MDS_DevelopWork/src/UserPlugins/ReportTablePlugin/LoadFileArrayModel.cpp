#include "LoadFileArrayModel.h"
#include <QDateTime>
#include <QDebug>
#include <QLineEdit>
#define DATETIME_DISPLAY_FORMAT2 "yyyy年MM月dd日 HH:mm:ss"
LoadFileArrayModel::LoadFileArrayModel(QObject* parent)
    : QAbstractTableModel(parent)
{
    mHeaders /*<< "序号"*/
        << "载荷名称"
        << "任务编号"
        << "任务状态"
        << "任务实际执行时间"
        << "l0第一行到达时间"
        << "l0最后一行到达时间"
        << "实际收到l0总数"
        << "获取l0总时间"
        << "生成l1A第一行时间"
        << "l1A最后一个文件时间"
        << "生成l1A总数"
        << "l1A生成总时间";
}

void LoadFileArrayModel::SetArrayData(const QList<LoadFileData>& Datas) { m_mpData = Datas; }

QList<LoadFileData> LoadFileArrayModel::GetArrayData() const { return m_mpData; }

//总行数
int LoadFileArrayModel::RowCount() const { return m_mpData.size(); }
//总行数
int LoadFileArrayModel::ColumnCount() const { return mHeaders.size() - 1; }

//设置页数据
void LoadFileArrayModel::SetCurPage(int iPage)
{
    //当前页必须小于总页数
    if (iPage < GetPageCount())
    {
        m_iCurPage = iPage;
    }
    return;
}

//获得当前页
int LoadFileArrayModel::GetCurPage() { return m_iCurPage; }

//获得总页数
int LoadFileArrayModel::GetPageCount()
{
    int pageNum;
    pageNum = (RowCount() % m_iPageSize == 0) ? (RowCount() / m_iPageSize) : (RowCount() / m_iPageSize + 1);
    return pageNum;
}

//设置每页数据条数
void LoadFileArrayModel::SetPageSize(int iPageSize)
{
    if (iPageSize <= 0)
    {
        return;
    }

    m_iPageSize = iPageSize;
    SetCurPage(0);

    //刷新Model，否则TableView不会刷新显示
    refrushModel();
}

//获得每页数据条数
int LoadFileArrayModel::GetPageSize() { return m_iPageSize; }

//行数
int LoadFileArrayModel::rowCount(const QModelIndex& parent) const { return m_iPageSize; }

//列数
int LoadFileArrayModel::columnCount(const QModelIndex& parent) const { return parent.isValid() ? 0 : mHeaders.size(); }

void LoadFileArrayModel::refrushModel()
{
    beginResetModel();
    endResetModel();
}
void LoadFileArrayModel::setImagerData(const QList<LoadFileData>& logMsgDatas)
{
    beginResetModel();
    m_mpData << logMsgDatas;
    endResetModel();
}
QVariant LoadFileArrayModel::data(const QModelIndex& index, int role) const
{
    if (!index.isValid())
    {
        return QVariant();
    }
    int row = index.row();
    int col = index.column();
    if (row < 0 || row > m_mpData.size() || col < 0 || col > mHeaders.size())
    {
        return QVariant();
    }

    switch (role)
    {
    case Qt::DisplayRole:
    {
        //如果处于最后一页，索引没必要全部列出，只列出范围内的
        if (row + m_iCurPage * m_iPageSize > this->RowCount())
        {
            return QVariant();
        }
        else
        {
            if ((row + m_iCurPage * m_iPageSize) < m_mpData.size())  //确保不越界
            {
                LoadFileData data = m_mpData.at(row + m_iCurPage * m_iPageSize);
                switch (col)
                {
                case loadName: return data.loadName;
                case taskNum: return data.taskNum;
                case taskStatus: return data.taskStatus;
                case taskActualExetime: return data.taskActualExetime;
                case l0FirstArrivaltime: return data.l0FirstArrivaltime;
                case l0LastArrivaltime: return data.l0LastArrivaltime;
                case L0ActualReceiveNum: return data.L0ActualReceiveNum;
                case getL0Alltime: return data.getL0Alltime;
                case l1AFirsttime: return data.l1AFirsttime;
                case l1ALasttime: return data.l1ALasttime;
                case l1ANum: return data.l1ANum;
                case l1A_Alltime: return data.l1A_Alltime;
                }
            }
        }
    }
    break;
    }
    return QVariant();
}

Qt::ItemFlags LoadFileArrayModel::flags(const QModelIndex& index) const
{
    if (!index.isValid())
        return QAbstractTableModel::flags(index);
    Qt::ItemFlags flag = Qt::ItemIsEnabled | Qt::ItemIsSelectable;
    return flag;
}

QVariant LoadFileArrayModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    switch (role)
    {
    case Qt::TextAlignmentRole: return QVariant(Qt::AlignCenter);
    case Qt::DisplayRole:
    {
        if (orientation == Qt::Horizontal)
        {
            return mHeaders.at(section);
        }
    }
    default: return QVariant();
    }

    return QVariant();
}
