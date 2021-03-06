#include "SqlImagerManager.h"
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

SqlImagerManager::SqlImagerManager(QObject* parent)
    : QObject(parent)
    //    , m_dbConnectName(DBInterface::createConnectName())
    , hasQueryFinished(true)
{
    QString host = "localhost";
    QString user = "root";
    QString passwd = "123456";
    QString dbname = "f41";
    int port = 3306;
    //    database = QSqlDatabase::addDatabase("QODBC", connectName);

    db = QSqlDatabase::addDatabase("QODBC");
    db.setHostName(host);
    db.setDatabaseName(dbname);
    db.setUserName(user);
    db.setPassword(passwd);
    db.setPort(port);
    query_ = QSqlQuery(db);
    tablelist = db.tables();
    bool isOk = db.open();
    if (!isOk)
    {
        qDebug() << "error info :" << db.lastError();
    }
    else
    {
        if (tablelist.count() == 0)
        {
            QString creatTableStr = "CREATE TABLE IF NOT EXISTS imager("
                                    "taskNum VARCHAR(100) , "
                                    "outputTime VARCHAR(50), "
                                    "fileName VARCHAR(100), "
                                    "LocalFilePath VARCHAR(50), "
                                    "outputFilePath VARCHAR(100), "
                                    "sendDirection VARCHAR(100), "
                                    "sendType VARCHAR(50), "
                                    "accuracy VARCHAR(50), "
                                    "outputType VARCHAR(50), "
                                    "fileSize VARCHAR(100));";

            query_.prepare(creatTableStr);
            if (!query_.exec())
            {
                qDebug() << "query error :" << query_.lastError();
            }
            else
            {
                qDebug() << "creat table success!";
            }
        }
    }
    //        db.close();
}
bool SqlImagerManager::queryFinished() { return hasQueryFinished; }

void SqlImagerManager::insert(const QList<ImagerData>& imager)
{
    QString sql = "INSERT INTO imager ("
                  "taskNum        ,"
                  "outputTime      ,"
                  "fileName        ,"
                  "LocalFilePath     ,"
                  "outputFilePath          ,"
                  "sendDirection        ,"
                  "sendType ,"
                  "accuracy       ,"
                  "outputType       ,"
                  "fileSize          )"
                  "VALUES (?,?,?,?,?,?,?,?,?,?);";
    query_ = db.exec(sql);
    query_.prepare(sql);
    for (auto& item : imager)
    {
        query_.bindValue(0, item.taskNum);
        query_.bindValue(1, item.outputTime);
        query_.bindValue(2, item.fileName);
        query_.bindValue(3, item.LocalFilePath);
        query_.bindValue(4, item.outputFilePath);
        query_.bindValue(5, item.sendDirection);
        query_.bindValue(6, item.sendType);
        query_.bindValue(7, item.accuracy);
        query_.bindValue(8, item.outputType);
        query_.bindValue(9, item.fileSize);
        query_.exec();
    }
    db.commit();
}

void SqlImagerManager::searchLog(const QStringList& devices, const QStringList& units, const QStringList& sids, const QStringList& aa,
                                 const QDateTime& start_time, const QDateTime& end_time, int currentPage, int pageSize)
{
    hasQueryFinished = false;
    QString sql = QString("SELECT * FROM STATUS_HISTORY WHERE (1=1) ");

    // deviceId????????????
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

    // Time????????????
    sql += QString("AND (Time BETWEEN '%2' AND '%3')").arg(start_time.toString("yyyy-MM-dd HH:mm:ss")).arg(end_time.toString("yyyy-MM-dd HH:mm:ss"));

    //??????????????????
    //    sql += QString(" order by time asc limit %4,%5;").arg((currentPage - 1) * pageSize).arg(pageSize);
    sql += QString(" limit %4,%5;").arg((currentPage - 1) * pageSize).arg(pageSize);

    ImagerDataList records;
    ImagerData data;

    bool hasRecord = query_.exec(sql) && query_.first();
    while (hasRecord)
    {
        auto record = query_.record();
        records.clear();
        QString time = record.field("Time").value().toString();
        QByteArray content = record.field("Content").value().toByteArray();
        //        QString proId = record.field("ProId").value().toString();
        //        QString deviceId = record.field("deviceId").value().toString();
        time.replace("T", " ");  //????????????????????????T?????????
        hasRecord = query_.next();
        emit searchLogAck(records);
    }
    hasQueryFinished = true;
}

void SqlImagerManager::totalCount(const QStringList& devices, const QStringList&, const QStringList&, const QStringList&, const QDateTime& start_time,
                                  const QDateTime& end_time, int currentPage, int)
{
    int totalCount = -1;
    //    QString sql = QString("SELECT count(*) FROM STATUS_HISTORY WHERE (1=1) ");
    QString sql = QString("SELECT count(id) FROM STATUS_HISTORY WHERE (1=1) ");

    // deviceId????????????
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

    // Time????????????
    sql += QString("AND (Time BETWEEN '%2' AND '%3')").arg(start_time.toString("yyyy-MM-dd HH:mm:ss")).arg(end_time.toString("yyyy-MM-dd HH:mm:ss"));

    query_.exec(sql);
    if (query_.next())
    {
        totalCount = query_.value(0).toInt();
    }
    emit totalCountAck(totalCount, currentPage);
}
