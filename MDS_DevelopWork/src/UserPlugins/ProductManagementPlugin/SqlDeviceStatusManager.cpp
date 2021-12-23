#include "SqlDeviceStatusManager.h"
//#include "DBInterface.h"
//#include "StatusPersistenceMessageSerialize.h"
#include <QDateTime>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlField>
#include <QSqlRecord>
#include <QUuid>

const int loadNumberPerMore = 200;

SqlDeviceStatusManager::SqlDeviceStatusManager(QObject* parent)
    : QObject(parent)
//    , m_dbConnectName(DBInterface::createConnectName())
//    , hasQueryFinished(true)
{
    //    auto db = DBInterface::getDefaultConnect(m_dbConnectName);
    //    query_ = QSqlQuery(db.value());
}

bool SqlDeviceStatusManager::queryFinished() { return hasQueryFinished; }

void SqlDeviceStatusManager::searchLog(const QStringList& devices, const QStringList& units, const QStringList& /*sids*/, const QDateTime& start_time,
                                       const QDateTime& end_time, const QList<int>& modes, int currentPage, int pageSize)
{
    hasQueryFinished = false;
    QString sql = QString("SELECT * FROM STATUS_HISTORY WHERE (1=1) ");

    // deviceId条件查询
    if (!devices.isEmpty())
    {
        QStringList device_list_str;
        bool selAllDevice = false;

        foreach (const auto& device, devices)
        {
            if (device == "-1")
            {
                selAllDevice = true;
                break;
            }
            device_list_str.append(QString("'%1'").arg(device));
        }

        if (!selAllDevice)
        {
            sql += QString("AND (DeviceId IN (%1)) ").arg(device_list_str.join(','));
        }
    }

    // Time条件查询
    sql += QString("AND (Time BETWEEN '%2' AND '%3')").arg(start_time.toString("yyyy-MM-dd HH:mm:ss")).arg(end_time.toString("yyyy-MM-dd HH:mm:ss"));

    //分页条件查询
    //    sql += QString(" order by time asc limit %4,%5;").arg((currentPage - 1) * pageSize).arg(pageSize);
    sql += QString(" limit %4,%5;").arg((currentPage - 1) * pageSize).arg(pageSize);

    //    DeviceStatusLogDataList records;
    //    DeviceStatusLogData data;

    bool hasRecord = query_.exec(sql) && query_.first();
    //    while (hasRecord)
    //    {
    //        auto record = query_.record();
    //        records.clear();
    //        QString time = record.field("Time").value().toString();
    //        QByteArray content = record.field("Content").value().toByteArray();
    //        //        QString proId = record.field("ProId").value().toString();
    //        //        QString deviceId = record.field("deviceId").value().toString();
    //        time.replace("T", " ");  //去除掉时间里面带T的字符

    //        DeviceStatusData deviceStatusData;
    //        content >> deviceStatusData;
    //        QString device_name = deviceStatusData.deviceName;

    //        QString parName, value;
    //        auto paramStatusMap = deviceStatusData.unitParamMap;

    //        if (!modes.isEmpty())
    //        {
    //            if (!modes.contains(deviceStatusData.modeId))
    //            {
    //                hasRecord = query_.next();
    //                continue;
    //            }
    //        }

    //        foreach (const auto& unitId, paramStatusMap.keys())
    //        {
    //            if (units.isEmpty() || units.contains(unitId))
    //            {
    //                auto paramStatuss = paramStatusMap.value(unitId).paramStatusMap;

    //                for (const auto& paramStatus : paramStatuss.values())
    //                {
    //                    parName = paramStatus.parName;
    //                    value = paramStatus.value.toString();
    //                    data.id = loadNumberPerMore;
    //                    data.createTime = time;
    //                    int deviceId;
    //                    deviceStatusData.deviceID >> deviceId;
    //                    data.deviceId = QString::number(deviceId);
    //                    data.unitId = unitId;
    //                    data.param = parName;
    //                    if (!paramStatus.enumValueDesc.isEmpty())
    //                    {
    //                        data.paramValue = paramStatus.enumValueDesc;
    //                    }
    //                    else
    //                    {
    //                        data.paramValue = paramStatus.value.toString();
    //                        if (!paramStatus.unit.isEmpty())
    //                        {
    //                            data.paramValue += QString(" (%1)").arg(paramStatus.unit);
    //                        }
    //                    }
    //                    data.modeId = deviceStatusData.modeId;

    //                    if (!data.param.contains("保留"))
    //                    {
    //                        records.append(data);
    //                    }
    //                }
    //            }
    //        }
    //        hasRecord = query_.next();
    //        emit searchLogAck(records);
    //    }
    hasQueryFinished = true;
}

void SqlDeviceStatusManager::totalCount(const QStringList& devices, const QStringList&, const QStringList&, const QDateTime& start_time,
                                        const QDateTime& end_time, const QList<int>&, int currentPage, int)
{
    int totalCount = -1;
    //    QString sql = QString("SELECT count(*) FROM STATUS_HISTORY WHERE (1=1) ");
    QString sql = QString("SELECT count(id) FROM STATUS_HISTORY WHERE (1=1) ");

    // deviceId条件查询
    if (!devices.isEmpty())
    {
        QStringList device_list_str;
        bool selAllDevice = false;

        foreach (const auto& device, devices)
        {
            if (device == "-1")
            {
                selAllDevice = true;
                break;
            }
            device_list_str.append(QString("'%1'").arg(device));
        }

        if (!selAllDevice)
        {
            sql += QString("AND (DeviceId IN (%1)) ").arg(device_list_str.join(','));
        }
    }

    // Time条件查询
    sql += QString("AND (Time BETWEEN '%2' AND '%3')").arg(start_time.toString("yyyy-MM-dd HH:mm:ss")).arg(end_time.toString("yyyy-MM-dd HH:mm:ss"));

    query_.exec(sql);
    if (query_.next())
    {
        totalCount = query_.value(0).toInt();
    }
    emit totalCountAck(totalCount, currentPage);
}
