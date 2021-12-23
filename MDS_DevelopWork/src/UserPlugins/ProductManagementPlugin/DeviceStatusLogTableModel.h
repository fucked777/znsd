#ifndef DEVICESTATUSLOGTABLEMODEL_H
#define DEVICESTATUSLOGTABLEMODEL_H

#include <QAbstractTableModel>
#include <QDateTime>
#include <QThread>
struct DeviceStatusLogData
{
    QString taskNum;         //任务编号
    QString outputTime;      //输出时间
    QString fileName;        //文件名称
    QString LocalFilePath;   //本地文件路径
    QString outputFilePath;  //输出文件路径
    QString sendDirection;   //传输方向
    QString sendType;        //传输方式
    QString accuracy;        //精度
    QString outputType;      //输出类型
    QString fileSize;        //文件大小
};
class SqlDeviceStatusManager;
// struct DeviceStatusLogData;
using DeviceStatusLogDataList = QList<DeviceStatusLogData>;
class DeviceStatusLogTableModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    enum Cloumn
    {
        taskNum,         // 任务编号
        outputTime,      // 输出时间
        fileName,        // 文件名称
        LocalFilePath,   // 本地文件路径
        outputFilePath,  // 输出文件路径
        sendDirection,   // 传输方向
        sendType,        // 传输方式
        accuracy,        // 精度
        outputType,      // 输出类型
        fileSize,        // 文件大小
    };

    explicit DeviceStatusLogTableModel(QObject* parent = nullptr);
    ~DeviceStatusLogTableModel();

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    Qt::ItemFlags flags(const QModelIndex& index = QModelIndex()) const override;

    void setDeviceStatusLogData(const QList<DeviceStatusLogData>& systemLogDatas);
    QList<DeviceStatusLogData> getDeviceStatusLogData() const;

    void appendDeviceStatusLogData(const DeviceStatusLogData& systemLogData);

    void reset(const QStringList& devices, const QStringList& units, const QStringList& units1, const QStringList& sids, const QDateTime& start_time,
               const QDateTime& end_time, int currentPage, int pageSize);

    //    void resetLog(const QString device, const QString deviceType, const QDateTime& start_time, const QDateTime& end_time);

signals:
    void load(int n);
    void loaded(int n);
    void search(const QStringList& devices, const QStringList& units, const QStringList& sids, const QDateTime& start_time, const QDateTime& end_time,
                const QList<int>& modes, int currentPage, int pageSize);
    void searchLog(const QStringList& devices, const QStringList& units, const QStringList& sids, const QStringList& aa, const QDateTime& start_time,
                   const QDateTime& end_time, int currentPage, int pageSize);
    void totalCount(const QStringList& devices, const QStringList& units, const QStringList& sids, const QStringList& aa, const QDateTime& start_time,
                    const QDateTime& end_time, int currentPage, int pageSize);
    void signalTotalCount(const int totalCount, const int currentPage);
    //    void logsearch(const QString device, const QString deviceType, const QDateTime start_time, const QDateTime end_time);

public slots:
    //    void moreStatus(const DeviceStatusLogDataList& status);
    void searchLogAck(const DeviceStatusLogDataList& status);
    void totalCountAck(const int totalCount, const int currentPage);

protected:
    bool canFetchMore(const QModelIndex& parent) const override;
    void fetchMore(const QModelIndex& parent) override;

private:
    QStringList mHeaders;

    DeviceStatusLogDataList status_list_;
    DeviceStatusLogDataList more_status_;

    SqlDeviceStatusManager* status_query_;
    QThread status_thread_;
};

#endif  // DEVICESTATUSLOGTABLEMODEL_H
