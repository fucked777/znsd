#ifndef LoadFileArrayModel_H
#define LoadFileArrayModel_H
#include <QAbstractItemModel>
#include <QItemDelegate>
#include <QObject>
#include <QStyledItemDelegate>
#include <QThread>
#include <QtWidgets/QWidget>
#include <vector>
struct LoadFileData
{
    QString loadName;
    QString taskNum;
    QString taskStatus;
    QString taskActualExetime;  //任务实际执行时间
    QString l0FirstArrivaltime;
    QString l0LastArrivaltime;
    QString L0ActualReceiveNum;
    QString getL0Alltime;
    QString l1AFirsttime;
    QString l1ALasttime;
    QString l1ANum;
    QString l1A_Alltime;
};

using LoadFileDataList = QList<LoadFileData>;
class LoadFileArrayModel : public QAbstractTableModel
{
    enum Cloumn
    {
        loadName,            //载荷名称
        taskNum,             //任务编号
        taskStatus,          //任务状态
        taskActualExetime,   //任务实际执行时间
        l0FirstArrivaltime,  // l0第一行到达时间
        l0LastArrivaltime,   // l0最后一行到达时间
        L0ActualReceiveNum,  //实际收到l0总数
        getL0Alltime,        //获取l0总时间
        l1AFirsttime,        //生成l1A第一行时间
        l1ALasttime,         // l1A最后一个文件时间
        l1ANum,              //生成l1A总数
        l1A_Alltime          // l1A生成总时间
    };
    //    Q_OBJECT
public:
    LoadFileArrayModel(QObject* parent = 0);
    //设置总数据
    void SetArrayData(const QList<LoadFileData>& Datas);

    //获得总数据
    QList<LoadFileData> GetArrayData() const;
    void setImagerData(const QList<LoadFileData>& Datas);
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
    QList<LoadFileData> m_mpData;  //总数据
    int m_iPageSize;               //每页数据条数
    int m_iCurPage;                //当前页
    QStringList mHeaders;          //表头
    QThread status_thread_;        //线程，后续可能使用
};
#endif  // LoadFileArrayModel_H
