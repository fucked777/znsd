#ifndef SqlDeviceStatusManager_H
#define SqlDeviceStatusManager_H

//#include "StatusPersistenceMessageSerialize.h"
//#include "Utility.h"
#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QThread>

class SqlDeviceStatusManager : public QObject
{
    Q_OBJECT
public:
    explicit SqlDeviceStatusManager(QObject* parent = nullptr);

    bool queryFinished();

signals:
    //    void searchLogAck(const DeviceStatusLogDataList& status);
    void totalCountAck(const int count, const int currentPage);

public slots:
    void searchLog(const QStringList& devices, const QStringList& units, const QStringList& sids, const QDateTime& start_time,
                   const QDateTime& end_time, const QList<int>& modes, int currentPage, int pageSize);
    void totalCount(const QStringList& devices, const QStringList& units, const QStringList& sids, const QDateTime& start_time,
                    const QDateTime& end_time, const QList<int>& modes, int currentPage, int pageSize);

private:
    QSqlQuery query_;

    QString m_dbConnectName;

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
