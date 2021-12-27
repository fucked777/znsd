#include "CArrayModel.h"
#include <QDateTime>
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

void CArrayModel::SetArrayData(const QList<ImagerData>& Datas)
{
    m_mpData = Datas;
    //    setImagerData(m_mpData);
}

QList<ImagerData> CArrayModel::GetArrayData() const { return m_mpData; }

//设置Model数据
// void CArrayModel::SetArrayData(const std::map<int, QString>& map) { m_mpData = map; }

//获得总数据
// std::map<int, QString> CArrayModel::GetArrayData() { return m_mpData; }

//总行数
int CArrayModel::RowCount() const { return m_mpData.size(); }

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
            iend = iStart + m_iPageSize;
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
            //            if (it == m_mpData.last())
            //            {
            //                return;
            //            }
            m_mpPageData.insert(i, it);
            //            m_mpPageData.insert(std::pair<int, QString>(i, it->second));
        }
    }

    return;
}

//获得当前页
int CArrayModel::GetCurPage() { return m_iCurPage; }

//获得总页数
int CArrayModel::GetPageCount() { return (RowCount() % m_iPageSize == 0) ? (RowCount() / m_iPageSize) : (RowCount() / m_iPageSize + 1); }

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
int CArrayModel::rowCount(const QModelIndex& parent) const { return m_iPageSize; }

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
    m_mpData = imagerDatas;
    endResetModel();
}
QVariant CArrayModel::data(const QModelIndex& index, int role) const
{
    auto row = index.row();
    auto col = index.column();
    if (row < 0 || row > m_mpData.size() || col < 0 || col > mHeaders.size())
    {
        return QVariant();
    }

    switch (role)
    {
    case Qt::DisplayRole:
    {
        const auto& data = m_mpData.at(row);
        switch (col)
        {
        case taskNum: return data.taskNum;
        case outputTime:
        {
            return QDateTime::fromString(data.outputTime, "yyyy-MM-dd hh:mm:ss").toString(DATETIME_DISPLAY_FORMAT2);
        }
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
    break;
    }
    return QVariant();

    //    if (!index.isValid())
    //    {
    //        return QVariant();
    //    }

    //    if (role == Qt::TextAlignmentRole)
    //    {
    //        return int(Qt::AlignCenter | Qt::AlignVCenter);
    //    }
    //    else if (role == Qt::DisplayRole)
    //    {
    //        if (0 == index.column())
    //        {
    //            //如果处于最后一页，索引没必要全部列出，只列出范围内的
    //            if (index.row() + m_iCurPage * m_iPageSize > this->RowCount())
    //            {
    //                return QVariant();
    //            }

    //            return index.row() + m_iCurPage * m_iPageSize;
    //        }
    //        else if (1 == index.column())
    //        {
    //            auto it = m_mpPageData.find(index.row() + m_iCurPage * m_iPageSize);
    //            if (it != m_mpPageData.end())
    //            {
    //                return it->second;
    //            }
    //        }
    //    }

    //    return QVariant();
}

Qt::ItemFlags CArrayModel::flags(const QModelIndex& index) const
{
    if (!index.isValid())
        return Qt::ItemIsEnabled;

    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}

bool CArrayModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
    //    if (index.isValid() && role == Qt::EditRole)
    //    {
    //        QVariant oldData = data(index, Qt::EditRole);
    //        QString strold = oldData.toString();
    //        QString strnew = value.toString();
    //        //相同则不编辑
    //        if (strnew.compare(strold) == 0)
    //        {
    //            return true;
    //        }

    //        //计算实际数据的下标
    //        int dataindex = index.row() + m_iCurPage * m_iPageSize;

    //        //改变总数据集
    //        auto it = m_mpData.at(dataindex);
    //        if (it != m_mpData.end())
    //        {
    //            it->second = strnew;
    //        }

    //        //改变当页数据集
    //        auto itcur = m_mpPageData.at(dataindex);
    //        auto end = m_mpPageData.at(m_mpPageData.size() - 1);
    //        if (itcur != end)
    //        {
    //            itcur->second = strnew;
    //        }
    //        return true;
    //    }
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
    //    if (role != Qt::DisplayRole)
    //    {
    //        return QVariant();
    //    }

    //    if (0 == section)
    //    {
    //        return QStringLiteral("索引");
    //    }
    //    else if (1 == section)
    //    {
    //        return QStringLiteral("值");
    //    }

    //    return QVariant();
}

QString CArrayModel::currencyAt(int offset) const
{
    //    auto it = m_mpData.at(offset);
    //    if (it != m_mpData.end())
    //    {
    //        return it->second;
    //    }

    return QString();
}

//样式定制
void ValueDelegate::paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
    if (!index.isValid())
    {
        // 如果当前项具有焦点，它就绘制一个焦点矩形(不重要)
        drawFocus(painter, option, option.rect);
    }
    else
    {
        QItemDelegate::paint(painter, option, index);
    }
}

QWidget* ValueDelegate::createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
    QLineEdit* editor = new QLineEdit(parent);
    return editor;
}

void ValueDelegate::setEditorData(QWidget* editor, const QModelIndex& index) const
{
    QString text = index.model()->data(index, Qt::EditRole).toString();
    QLineEdit* lineEdit = static_cast<QLineEdit*>(editor);
    lineEdit->setText(text);
}

void ValueDelegate::setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const
{
    QLineEdit* lineEdit = static_cast<QLineEdit*>(editor);
    QString text = lineEdit->text();
    model->setData(index, text, Qt::EditRole);
}

void ValueDelegate::updateEditorGeometry(QWidget* editor, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
    editor->setGeometry(option.rect);
}
