#ifndef DATATRANSFORM_H
#define DATATRANSFORM_H

#include "DataTransform_global.h"

#include <QObject>
#include<QString>
#include<QByteArray>
#include<QtGlobal>
#include "iTransformServer.h"

class DataTransformPrivate;

class AbsDataServer
{
public:
    //处理由客户端发送过来的异步请求
    virtual iTransformServer::Result postMessage(const QByteArray& cmd) = 0;
    //处理由客户端发送过来的同步请求
    virtual QByteArray getMessage(const QByteArray& cmd) = 0;
};

/**
 * 数据中转
 * transformMessage可以主动向客户端发送数据，数据将发送给所有客户端
 * 客户端发送过来的请求将通过AbsDataServer进行处理
 */

class DATATRANSFORM_EXPORT DataTransform :public QObject
{
    Q_OBJECT
public:
    // 创建服务
    // name:服务的名字
    // port:服务端口号
    DataTransform(QString name,QString port,QObject * parent = nullptr);

    //向客户端发送数据
    // decoder:解析器的名字
    // data:实际数据
    bool transformMessage(QString decoder,QByteArray data);

    //设置dataserver
    void setDataServer(AbsDataServer* server);

private slots:

    void connectHost();

private:
    Q_DECLARE_PRIVATE(DataTransform)

    DataTransformPrivate* d_ptr;
};

#endif // DATATRANSFORM_H
