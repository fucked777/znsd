#ifndef SqlDeviceStatusManager_H
#define SqlDeviceStatusManager_H
#include "CArrayModel.h"
//#include "StatusPersistenceMessageSerialize.h"
//#include "Utility.h"
#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QThread>
struct ImagerData;
class SqlDeviceStatusManager : public QObject
{
    Q_OBJECT
public:
    explicit SqlDeviceStatusManager(QObject* parent = nullptr);

    bool queryFinished();
    void insert(const QList<ImagerData>& imager);
signals:
    void searchLogAck(const ImagerDataList& status);
    void totalCountAck(const int count, const int currentPage);

public slots:
    void searchLog(const QStringList& devices, const QStringList& units, const QStringList& sids, const QStringList& aa, const QDateTime& start_time,
                   const QDateTime& end_time, int currentPage, int pageSize);
    void totalCount(const QStringList& devices, const QStringList&, const QStringList&, const QStringList&, const QDateTime& start_time,
                    const QDateTime& end_time, int currentPage, int pageSize);

private:
    QSqlQuery query_;
    QSqlDatabase db;
    QString m_dbConnectName;
    QStringList tablelist;  //库里的表列表
    bool hasQueryFinished;
};

// class SqlDeviceStatusManager : public QObject
//{
//    Q_OBJECT
// public:
//    explicit SqlDeviceStatusManager(QObject* parent = nullptr);
//    //    bool hasRecord() const;

// signals:
//    //    void moreStatus(const DeviceStatusLogDataList& status);
//    void searchLogAck(const DeviceStatusLogDataList& status);

// public slots:
//    //    void load(int n);
//    //    void search(const QStringList& devices, const QStringList& units, const QStringList& sids, const QDateTime& start_time, const QDateTime&
//    //    end_time,
//    //                const QList<int>& modes, int currentPage, int pageSize);
//    //    void logsearch(const QString device, const QString deviceType, const QDateTime start_time, const QDateTime end_time);

//    void searchLog(const QStringList& devices, const QStringList& units, const QStringList& sids, const QDateTime& start_time,
//                   const QDateTime& end_time, const QList<int>& modes, int currentPage, int pageSize);

// private:
//    QSqlQuery query_;

//    QString m_dbConnectName;
//    //    bool has_record_ = true;
//    //    QStringList unit_list_;
//    //    QStringList status_list_;
//    //    QList<int> mode_list_;
//};

#endif  // SqlDeviceStatusManager_H
