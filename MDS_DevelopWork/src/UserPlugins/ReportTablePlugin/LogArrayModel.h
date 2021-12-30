#ifndef LogArrayModel_H
#define LogArrayModel_H
#include <QAbstractItemModel>
#include <QItemDelegate>
#include <QObject>
#include <QStyledItemDelegate>
#include <QThread>
#include <QtWidgets/QWidget>
#include <vector>
struct LogMsgData
{
    QString dateTime;
    QString systemName;
    QString taskNum;
    QString logMsg;
    QString logProperty;
};

using LogMsgDataList = QList<LogMsgData>;
class LogArrayModel : public QAbstractTableModel
{
    enum Cloumn
    {
        dateTime,    // 日期
        systemName,  // 分系统名称
        taskNum,     // 任务编号
        logMsg,      // 故障信息
        logProperty  // 日志属性
    };
    //    Q_OBJECT
public:
    LogArrayModel(QObject* parent = 0);
    //设置总数据
    void SetArrayData(const QList<LogMsgData>& Datas);

    //获得总数据
    QList<LogMsgData> GetArrayData() const;
    void setImagerData(const QList<LogMsgData>& Datas);
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
    QList<LogMsgData> m_mpData;  //总数据
    int m_iPageSize;             //每页数据条数
    int m_iCurPage;              //当前页
    QStringList mHeaders;        //表头
    QThread status_thread_;      //线程，后续可能使用
};
#endif  // LogArrayModel_H
