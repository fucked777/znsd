#ifndef IOBSERVICEINTERFACE_H
#define IOBSERVICEINTERFACE_H

#include <QString>
#include <QObject>

/**
 * @brief The iObServiceInterface class
 * 通信公共函数：由信息接收者实现，注册至通信主服务内
 */
class iObServiceInterface :public QObject
{
public:
    /**
     * @brief showMessageInfo       接受信息
     * @param messgae
     */
    virtual void showMessageInfo(const QString &messgae) =0;

    /**
     * @brief getThemeName      返回主题名称
     * @return
     */
    virtual QString getThemeName() =0;

    /**
     * @brief setThemeName
     */
    virtual void setThemeName(const QString &messgae ) =0;

};

#endif // IOBSERVICEINTERFACE_H
