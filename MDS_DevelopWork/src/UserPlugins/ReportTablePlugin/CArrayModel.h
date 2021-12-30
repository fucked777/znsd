#ifndef CARRAYMODEL_H
#define CARRAYMODEL_H
#include <QAbstractItemModel>
#include <QItemDelegate>
#include <QObject>
#include <QStyledItemDelegate>
#include <QThread>
#include <QtWidgets/QWidget>
#include <vector>
struct FaultMsgData
{
    QString faultLevel;
    QString dateTime;
    QString taskNum;
    QString faultCode;
    QString systemName;
    QString dealStatus;
    QString faultInfor;
    QString internalFault;
    QString remarks;
};

using FaultMsgDataList = QList<FaultMsgData>;
class CArrayModel : public QAbstractTableModel
{
    enum Cloumn
    {
        faultLevel,     // 故障等级
        dateTime,       // 日期
        taskNum,        // 任务编号
        faultCode,      // 故障代码
        systemName,     // 分系统名称
        dealStatus,     // 处理状态
        faultInfor,     // 故障信息
        internalFault,  // 内部故障
        remarks         // 备注
    };
    //    Q_OBJECT
public:
    CArrayModel(QObject* parent = 0);
    //设置总数据
    void SetArrayData(const QList<FaultMsgData>& Datas);

    //获得总数据
    QList<FaultMsgData> GetArrayData() const;
    void setImagerData(const QList<FaultMsgData>& Datas);
    //设置页数据
    void SetCurPage(int iPage);
    //获得当前页
    int GetCurPage();
    //获得总页数
    int GetPageCount();
    //设置每页数据条数
    void SetPageSize(int iPageSize);
    //获得每页数据条数
    int GetPageSize();

    //总行数
    int RowCount() const;
    int ColumnCount() const;

public:
    int rowCount(const QModelIndex& parent) const;
    int columnCount(const QModelIndex& parent) const;
    QVariant data(const QModelIndex& index, int role) const;
    Qt::ItemFlags flags(const QModelIndex& index) const;
    //    bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole);
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    void refrushModel();

private:
    QList<FaultMsgData> m_mpData;  //总数据
    int m_iPageSize;               //每页数据条数
    int m_iCurPage;                //当前页
    QStringList mHeaders;          //表头
    QThread status_thread_;        //线程，后续可能使用
};
#endif  // CARRAYMODEL_H
