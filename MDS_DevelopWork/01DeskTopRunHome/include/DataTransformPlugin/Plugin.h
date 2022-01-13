#ifndef Plugin_h__
#define Plugin_h__


#include <string>
#include <QMap>
#include <QJsonObject>
#include <QVariant>
#include <QObject>

typedef QMap<QString, QVariantMap> HeaderStruct;

/**
 * ���ݽ��������࣬���ڽ������ݣ�������QByteArray���ձ�����ΪHeaderStruct
 * HeaderStruct��
 *	keyΪ�����������֣���ܻὫ���ݷ��͸���Ӧ�ķ�����
 *  valueΪQVariantMap��Ϊʵ�ʵ�����
 */
class AbsDataDecoder
{
public:
    typedef std::function<AbsDataDecoder*()> CreateFunc;
	//���ݽ�����������
	virtual QString createName() = 0;
	//��������
    virtual HeaderStruct decode(QByteArray & bytes) = 0;
	//����������
	virtual CreateFunc getCreateFunc() = 0;

private:
};


/**
 *	���ݷ��������ۣ����ڽ��������������QVariantMap���͸�ҳ�棬ע�ⲻҪ��ҳ��ָ�봫������ֱ�Ӳ���ҳ��(����൥��������һ�����߳�)
 *	�������źŲ۵ķ�ʽ��ҳ�洫������
 */
class AbsDataSender
{
public:
	AbsDataSender() {}
	//�����ߵ�����
	virtual QString senderName() const = 0;
	//��������
	virtual bool sendData(const QVariantMap& obj) = 0;
	//ֹͣ������
	virtual void stop() = 0;
};


#define Version(major, minor, patch) ((major<<16)|(minor<<8)|(patch))

/**
 * ͨ�Ų�����ࣺ�ڲ������ʱ��DataTransformPluginע�ᣬ���ɽ��������ͷ�����ע�ᵽ���
 * ����ڵĽ������ͷ���������Ϊ��
 * �������ͷ���������һ�Զ࣬Ҳ���Զ��һ��ֻ��Ҫ���ֶ�Ӧ�ϼ���
 * ��������������Ӧһ�������������Դ������Plugin��ֻ��Ҫ��һ����������������
 */
class AbsPlugin 
{
public:

	virtual ~AbsPlugin() {}
	//��ȡ������
	virtual AbsDataDecoder* decoder() = 0;
	//��ȡ������
	virtual AbsDataSender* sender() = 0;
	//���������
	virtual QString name()const = 0;
	//����İ汾
	virtual unsigned int version()const = 0;

protected:
	//�����������ͷ�����
	virtual bool load() = 0;
	//ɾ���������ͷ�����
	virtual bool unload() = 0;

protected:

	AbsDataSender* _sender = nullptr;
	AbsDataDecoder* _decoder = nullptr;
};

class AbsPluginManager
{
public:
	//��Ӳ��
	virtual bool addPlugin(AbsPlugin* plugin) = 0;
	//ɾ�����
	virtual bool removePlugin(AbsPlugin* plugin) = 0;

};


class AbsCmdControl
{
public:

	//�����˷���һ��ָ��,sync ���ͺ���������
	//server ��������֣��� TestServer
	//cmd ָ��
	virtual void postMessage(QString server,QByteArray cmd) = 0;

	//�ӷ�������ȡһ������,async ͬ�����÷���
	//server ��������֣��� TestServer
	//cmd ָ��
	virtual QByteArray getMessage(QString server, QByteArray cmd) = 0;
};

#define CREATEFUNC "createFunc"

#endif // Plugin_h__
