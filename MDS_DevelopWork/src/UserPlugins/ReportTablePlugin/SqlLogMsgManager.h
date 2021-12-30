#ifndef SqlLogMsgManager_H
#define SqlLogMsgManager_H
#include "LogArrayModel.h"
#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QThread>
struct LogMsgData;
class SqlLogMsgManager : public QObject
{
    Q_OBJECT
public:
    explicit SqlLogMsgManager(QObject* parent = nullptr);

    bool queryFinished();
    void insert(const QList<LogMsgData>& imager);
signals:
    void searchLogAck(const LogMsgDataList& status);
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

#endif  // SqlLogMsgManager_H
