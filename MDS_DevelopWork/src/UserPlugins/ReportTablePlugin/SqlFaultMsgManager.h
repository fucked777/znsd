#ifndef SqlFaultMsgManager_H
#define SqlFaultMsgManager_H
#include "CArrayModel.h"
//#include "StatusPersistenceMessageSerialize.h"
//#include "Utility.h"
#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QThread>
struct FaultMsgData;
class SqlFaultMsgManager : public QObject
{
    Q_OBJECT
public:
    explicit SqlFaultMsgManager(QObject* parent = nullptr);

    bool queryFinished();
    void insert(const QList<FaultMsgData>& imager);
signals:
    void searchLogAck(const FaultMsgDataList& status);
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

#endif  // SqlFaultMsgManager_H
