#ifndef IMAINFRAMESERVICE_H
#define IMAINFRAMESERVICE_H

#include <QObject>

/**
 * @brief The IMainFrameService class
 * 主程序接口：提供主程序入口、系统关闭服务等；
 */
class IMainFrameService:public QObject
{
public:
    virtual ~IMainFrameService() override{}
    /**
     * @brief closePluginFrame      关闭主框架1
     */
    virtual void closePluginFrame() = 0;

    /**
     * @brief closeSystem           关闭主框架2
     */
    virtual void closeSystem() = 0;

    /**
     * @brief close                 关闭组框架3
     */
    virtual void close() = 0;


};


#define IMainFrameService_iid "org.casic.service.demo.IMainFrameService"
Q_DECLARE_INTERFACE(IMainFrameService, IMainFrameService_iid)

#endif // IMAINFRAMESERVICE_H
