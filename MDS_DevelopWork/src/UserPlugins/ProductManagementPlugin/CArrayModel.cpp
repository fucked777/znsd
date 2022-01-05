#include "CArrayModel.h"
#include <QDateTime>
#include <QDebug>
#include <QLineEdit>
#define DATETIME_DISPLAY_FORMAT2 "yyyy年MM月dd日 HH:mm:ss"
CArrayModel::CArrayModel(QObject* parent)
    : QAbstractTableModel(parent)
{
    mHeaders /*<< "序号"*/
        << "任务编号"
        << "输出时间"
        << "文件名称"
        << "本地文件路径"
        << "输出文件路径"
        << "传输方向"
        << "传输方式"
        << "精度"
        << "输出类型"
        << "文件大小";
}

void CArrayModel::SetArrayData(const QList<ImagerData>& Datas) { m_mpData = Datas; }

QList<ImagerData> CArrayModel::GetArrayData() const { return m_mpData; }

//总行数
int CArrayModel::RowCount() const { return m_mpData.size(); }
//总行数
int CArrayModel::ColumnCount() const { return mHeaders.size() - 1; }

//设置页数据
void CArrayModel::SetCurPage(int iPage)
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
int CArrayModel::GetCurPage() { return m_iCurPage; }

//获得总页数
int CArrayModel::GetPageCount()
{
    int pageNum;
    pageNum = (RowCount() % m_iPageSize == 0) ? (RowCount() / m_iPageSize) : (RowCount() / m_iPageSize + 1);
    return pageNum;
}

//设置每页数据条数
void CArrayModel::SetPageSize(int iPageSize)
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
int CArrayModel::GetPageSize() { return m_iPageSize; }

//行数
int CArrayModel::rowCount(const QModelIndex& parent) const { return m_mpPageData.size(); }

//列数
int CArrayModel::columnCount(const QModelIndex& parent) const { return parent.isValid() ? 0 : mHeaders.size(); }

void CArrayModel::refrushModel()
{
    beginResetModel();
    endResetModel();
}
void CArrayModel::setImagerData(const QList<ImagerData>& imagerDatas)
{
    beginResetModel();
    endResetModel();
}
QVariant CArrayModel::data(const QModelIndex& index, int role) const
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
            ImagerData data = m_mpData.at(row + m_iCurPage * m_iPageSize);
            switch (col)
            {
            case taskNum: return data.taskNum;
            case outputTime: return data.outputTime;
            case fileName: return data.fileName;
            case LocalFilePath: return data.LocalFilePath;
            case outputFilePath: return data.outputFilePath;
            case sendDirection: return data.sendDirection;
            case sendType: return data.sendType;
            case accuracy: return data.accuracy;
            case outputType: return data.outputType;
            case fileSize: return data.fileSize;
            }
        }
    }
    break;
    }
    return QVariant();
}

Qt::ItemFlags CArrayModel::flags(const QModelIndex& index) const
{
    if (!index.isValid())
        return QAbstractTableModel::flags(index);
    Qt::ItemFlags flag = Qt::ItemIsEnabled | Qt::ItemIsSelectable;
    return flag;
}

bool CArrayModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
    if (index.isValid() && role == Qt::EditRole)
    {
        QVariant oldData = data(index, Qt::EditRole);
        QString strold = oldData.toString();
        QVariant strnew = value;
        //相同则不编辑
        //        if (strnew.compare(strold) == 0)
        //        {
        //            return true;
        //        }

        //计算实际数据的下标
        int dataindex = index.row() + m_iCurPage * m_iPageSize;
        int pageindex = index.row();

        //改变总数据集
        //        if (index.column() == 8)  //备注
        //        {
        //            auto it = m_mpData.at(dataindex);
        //            it.remarks = strnew.toString();
        //            //        it.dealStatus = strnew;
        //            m_mpData.replace(dataindex, it);

        //            //改变当页数据集
        //            auto itcur = m_mpPageData.at(pageindex);
        //            itcur.remarks = strnew.toString();
        //            //        itcur.dealStatus = strnew;
        //            m_mpPageData.replace(pageindex, itcur);
        //        }
        //        else if (index.column() == 5)  //处理状态
        //        {
        //            auto it = m_mpData.at(dataindex);
        //            it.dealStatus = strnew.toStringList().at(0);
        //            it.remarks = strnew.toStringList().at(1);
        //            m_mpData.replace(dataindex, it);

        //            //改变当页数据集
        //            auto itcur = m_mpPageData.at(pageindex);
        //            itcur.dealStatus = strnew.toStringList().at(0);
        //            itcur.remarks = strnew.toStringList().at(1);
        //            m_mpPageData.replace(pageindex, itcur);
        //        }
        return true;
    }
    return false;
}

QVariant CArrayModel::headerData(int section, Qt::Orientation orientation, int role) const
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
