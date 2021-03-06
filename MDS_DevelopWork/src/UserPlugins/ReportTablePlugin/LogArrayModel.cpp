#include "LogArrayModel.h"
#include <QDateTime>
#include <QDebug>
#include <QLineEdit>
#define DATETIME_DISPLAY_FORMAT2 "yyyy年MM月dd日 HH:mm:ss"
LogArrayModel::LogArrayModel(QObject* parent)
    : QAbstractTableModel(parent)
{
    mHeaders /*<< "序号"*/
        << "日期"
        << "分系统名称"
        << "任务编号"
        << "日志信息"
        << "日志属性";
}

void LogArrayModel::SetArrayData(const QList<LogMsgData>& Datas) { m_mpData = Datas; }

QList<LogMsgData> LogArrayModel::GetArrayData() const { return m_mpData; }

//总行数
int LogArrayModel::RowCount() const { return m_mpData.size(); }
//总行数
int LogArrayModel::ColumnCount() const { return mHeaders.size() - 1; }

//设置页数据
void LogArrayModel::SetCurPage(int iPage)
{
    //当前页必须小于总页数
    if (iPage < GetPageCount())
    {
        m_iCurPage = iPage;
        //查询起始索引
        int iStart = m_iPageSize * m_iCurPage;
        //查询结束索引
        int iend = 0;
        //如果本页可以填满
        if (iStart + m_iPageSize < RowCount())
        {
            iend = iStart + m_iPageSize - 1;
        }
        //如果本页不可以填满
        else
        {
            iend = RowCount() - 1;
        }

        //填充当前页数据
        m_mpPageData.clear();
        for (int i = iStart; i <= iend; ++i)
        {
            auto it = m_mpData.at(i);
            m_mpPageData.push_back(it);
        }
    }
    return;
}

//获得当前页
int LogArrayModel::GetCurPage() { return m_iCurPage; }

//获得总页数
int LogArrayModel::GetPageCount()
{
    int pageNum;
    pageNum = (RowCount() % m_iPageSize == 0) ? (RowCount() / m_iPageSize) : (RowCount() / m_iPageSize + 1);
    return pageNum;
}

//设置每页数据条数
void LogArrayModel::SetPageSize(int iPageSize)
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
int LogArrayModel::GetPageSize() { return m_iPageSize; }

//行数
int LogArrayModel::rowCount(const QModelIndex& parent) const { return m_mpPageData.size(); }

//列数
int LogArrayModel::columnCount(const QModelIndex& parent) const { return parent.isValid() ? 0 : mHeaders.size(); }

void LogArrayModel::refrushModel()
{
    beginResetModel();
    endResetModel();
}
void LogArrayModel::setImagerData(const QList<LogMsgData>& logMsgDatas)
{
    beginResetModel();
    m_mpData << logMsgDatas;
    endResetModel();
}
QVariant LogArrayModel::data(const QModelIndex& index, int role) const
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

        if ((row + m_iCurPage * m_iPageSize) < m_mpData.size())  //确保不越界
        {
            LogMsgData data = m_mpData.at(row + m_iCurPage * m_iPageSize);
            switch (col)
            {
            case dateTime: return data.dateTime;
            case systemName: return data.systemName;
            case taskNum: return data.taskNum;
            case logMsg: return data.logMsg;
            case logProperty: return data.logProperty;
            }
        }
    }
    break;
    }
    return QVariant();
}

Qt::ItemFlags LogArrayModel::flags(const QModelIndex& index) const
{
    if (!index.isValid())
        return QAbstractTableModel::flags(index);
    Qt::ItemFlags flag = Qt::ItemIsEnabled | Qt::ItemIsSelectable;
    return flag;
}

QVariant LogArrayModel::headerData(int section, Qt::Orientation orientation, int role) const
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
