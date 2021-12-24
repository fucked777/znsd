#include "DeviceStatusLogTableModel.h"
//#include "GlobalData.h"
//#include "ProtocolXmlTypeDefine.h"
#include "SqlDeviceStatusManager.h"
//#include "StatusPersistenceMessageSerialize.h"
#include <QMessageBox>

const int loadNumberPerMore = 100;

DeviceStatusLogTableModel::DeviceStatusLogTableModel(QObject* parent)
    : QAbstractTableModel(parent)
{
    mHeaders /*<< "序号"*/
        << "任务编号"
        << "输出时间"
        << "文件名称"
        << "本地文件路径"
        << "输出文件路径"
        << "传输方向"
        << "传输方式"
        << "精度"
        << "输出类型"
        << "文件大小";
    //    mHeaders << tr("时间") << tr("设备") << tr("模式") << tr("单元") << tr("参数") << tr("参数大小");
    //    this->setHorizontalHeaderLabels(mHeaders);
    status_query_ = new SqlDeviceStatusManager;
    status_query_->moveToThread(&status_thread_);
    connect(&status_thread_, &QThread::finished, status_query_, &QObject::deleteLater);
    qRegisterMetaType<DeviceStatusLogDataList>("DeviceStatusLogDataList");

    connect(this, &DeviceStatusLogTableModel::searchLog, status_query_, &SqlDeviceStatusManager::searchLog, Qt::QueuedConnection);
    connect(status_query_, &SqlDeviceStatusManager::searchLogAck, this, &DeviceStatusLogTableModel::searchLogAck, Qt::QueuedConnection);
    connect(this, &DeviceStatusLogTableModel::totalCount, status_query_, &SqlDeviceStatusManager::totalCount, Qt::QueuedConnection);
    connect(status_query_, &SqlDeviceStatusManager::totalCountAck, this, &DeviceStatusLogTableModel::totalCountAck, Qt::QueuedConnection);
    //    res = connect(this, &DeviceStatusLogTableModel::load, status_query_, &SqlDeviceStatusManager::load, Qt::QueuedConnection);
    //    res = connect(status_query_, &SqlDeviceStatusManager::moreStatus, this, &DeviceStatusLogTableModel::moreStatus, Qt::QueuedConnection);
    //    res = connect(this, &DeviceStatusLogTableModel::search, status_query_, &SqlDeviceStatusManager::search, Qt::QueuedConnection);

    status_thread_.start();
}

DeviceStatusLogTableModel::~DeviceStatusLogTableModel() {}

int DeviceStatusLogTableModel::rowCount(const QModelIndex& parent) const { return parent.isValid() ? 0 : status_list_.size(); }

int DeviceStatusLogTableModel::columnCount(const QModelIndex& parent) const { return parent.isValid() ? 0 : mHeaders.size(); }

QVariant DeviceStatusLogTableModel::data(const QModelIndex& index, int role) const
{
    if (!index.isValid())
    {
        return QVariant();
    }

    auto row = index.row();
    auto col = index.column();
    if (row < 0 || row > status_list_.size() || col < 0 || col > mHeaders.size())
    {
        return QVariant();
    }

    switch (role)
    {
    case Qt::DisplayRole:
    {
        const auto& data = status_list_.at(row);
        switch (col)
        {
        case taskNum: return data.taskNum;
        case outputTime: return data.outputTime;
        case fileName: return data.fileName;
        case LocalFilePath: return data.LocalFilePath;
        case outputFilePath: return data.outputFilePath;
        case sendDirection: return data.sendDirection;
        case sendType: return data.sendType;
        case accuracy: return data.accuracy;
        case outputType: return data.outputType;
        case fileSize: return data.fileSize;
        }
    }
    break;
    }
    return QVariant();
}

QVariant DeviceStatusLogTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    switch (role)
    {
    case Qt::TextAlignmentRole: return QVariant(Qt::AlignCenter);
    case Qt::DisplayRole:
    {
        if (orientation == Qt::Horizontal)
        {
            return mHeaders.at(section);
        }
    }
    default: return QVariant();
    }

    return QVariant();
}

Qt::ItemFlags DeviceStatusLogTableModel::flags(const QModelIndex& index) const
{
    if (!index.isValid())
        return QAbstractTableModel::flags(index);
    Qt::ItemFlags flag = Qt::ItemIsEnabled | Qt::ItemIsSelectable;

    return flag;
}

void DeviceStatusLogTableModel::setDeviceStatusLogData(const QList<DeviceStatusLogData>& deviceStatusLogDatas)
{
    status_query_->insert(deviceStatusLogDatas);
    beginResetModel();
    status_list_ = deviceStatusLogDatas;
    endResetModel();
}

QList<DeviceStatusLogData> DeviceStatusLogTableModel::getDeviceStatusLogData() const { return status_list_; }

void DeviceStatusLogTableModel::appendDeviceStatusLogData(const DeviceStatusLogData& deviceStatusLogData)
{
    beginInsertRows(QModelIndex(), status_list_.size(), status_list_.size());
    status_list_ << deviceStatusLogData;
    endInsertRows();
}

void DeviceStatusLogTableModel::reset(const QStringList& devices, const QStringList& units, const QStringList& units1, const QStringList& sids,
                                      const QDateTime& start_time, const QDateTime& end_time, int currentPage, int pageSize)
{
    if (!status_query_->queryFinished())
    {
        QMessageBox::information(nullptr, "提示", "上次状态数据还未查询完成", "确定");
        return;
    }
    emit searchLog(devices, units, sids, sids, start_time, end_time, currentPage, pageSize);
    emit totalCount(devices, units, sids, sids, start_time, end_time, currentPage, pageSize);

    beginResetModel();
    status_list_.clear();
    endResetModel();
}

// void DeviceStatusLogTableModel::resetLog(const QString device, const QString deviceType, const QDateTime& start_time, const QDateTime& end_time)
//{
//    emit logsearch(device, deviceType, start_time, end_time);

//    beginResetModel();
//    status_list_.clear();
//    endResetModel();
//}

// void DeviceStatusLogTableModel::moreStatus(const DeviceStatusLogDataList& status)
//{
//    if (!status.isEmpty())
//    {
//        beginInsertRows(QModelIndex(), status_list_.count(), status_list_.count() + status.count() - 1);
//        status_list_ += status;
//        endInsertRows();
//        emit loaded(status.count());
//    }
//}

void DeviceStatusLogTableModel::searchLogAck(const DeviceStatusLogDataList& status)
{
    for (auto& s : status)
    {
        appendDeviceStatusLogData(s);
    }
}

void DeviceStatusLogTableModel::totalCountAck(const int totalCount, const int currentPage) { emit signalTotalCount(totalCount, currentPage); }

bool DeviceStatusLogTableModel::canFetchMore(const QModelIndex& /*parent*/) const { return /*status_query_->hasRecord()*/ false; }

void DeviceStatusLogTableModel::fetchMore(const QModelIndex& /*parent*/) { emit load(loadNumberPerMore); }
