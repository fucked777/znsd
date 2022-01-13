#ifndef Plugin_h__
#define Plugin_h__


#include <string>
#include <QMap>
#include <QJsonObject>
#include <QVariant>
#include <QObject>

typedef QMap<QString, QVariantMap> HeaderStruct;

/**
 * 数据解析器基类，用于解析数据，数据有QByteArray最终被解析为HeaderStruct
 * HeaderStruct：
 *	key为发送器的名字，框架会将数据发送给对应的发送器
 *  value为QVariantMap，为实际的数据
 */
class AbsDataDecoder
{
public:
    typedef std::function<AbsDataDecoder*()> CreateFunc;
	//数据解析器的名称
	virtual QString createName() = 0;
	//解析数据
    virtual HeaderStruct decode(QByteArray & bytes) = 0;
	//创建解析器
	virtual CreateFunc getCreateFunc() = 0;

private:
};


/**
 *	数据发送器积累，用于将解析器解析完的QVariantMap发送给页面，注意不要将页面指针传到子类直接操作页面(这个类单独运行在一个子线程)
 *	建议用信号槽的方式向页面传送数据
 */
class AbsDataSender
{
public:
	AbsDataSender() {}
	//发送者的名称
	virtual QString senderName() const = 0;
	//发送数据
	virtual bool sendData(const QVariantMap& obj) = 0;
	//停止发送器
	virtual void stop() = 0;
};


#define Version(major, minor, patch) ((major<<16)|(minor<<8)|(patch))

/**
 * 通信插件基类：在插件加载时向DataTransformPlugin注册，即可将解析器和发送器注册到框架
 * 插件内的解析器和发送器可以为空
 * 解析器和发送器可以一对多，也可以多对一，只需要名字对应上即可
 * 例如多个解析器对应一个发送器，可以创建多个Plugin，只需要有一个创建发送器即可
 */
class AbsPlugin 
{
public:

	virtual ~AbsPlugin() {}
	//获取解析器
	virtual AbsDataDecoder* decoder() = 0;
	//获取发送器
	virtual AbsDataSender* sender() = 0;
	//插件的名称
	virtual QString name()const = 0;
	//插件的版本
	virtual unsigned int version()const = 0;

protected:
	//创建解析器和发送器
	virtual bool load() = 0;
	//删除解析器和发送器
	virtual bool unload() = 0;

protected:

	AbsDataSender* _sender = nullptr;
	AbsDataDecoder* _decoder = nullptr;
};

class AbsPluginManager
{
public:
	//添加插件
	virtual bool addPlugin(AbsPlugin* plugin) = 0;
	//删除插件
	virtual bool removePlugin(AbsPlugin* plugin) = 0;

};


class AbsCmdControl
{
public:

	//向服务端发送一条指令,sync 发送后立即返回
	//server 服务的名字：如 TestServer
	//cmd 指令
	virtual void postMessage(QString server,QByteArray cmd) = 0;

	//从服务器获取一条数据,async 同步调用返回
	//server 服务的名字：如 TestServer
	//cmd 指令
	virtual QByteArray getMessage(QString server, QByteArray cmd) = 0;
};

#define CREATEFUNC "createFunc"

#endif // Plugin_h__
