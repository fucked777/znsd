#ifndef  IMAINMANAGERSERVICE_H
#define  IMAINMANAGERSERVICE_H

#include <QObject>
#include <QWidget>

class QString;
class QIcon;
class QWidget;

/**
 * @brief The IMainManagerService class
 * 主界面插件对外服务类：提供各类使用方法
 *
 */
class IMainManagerService: public QObject
{
    Q_OBJECT
 public:
     IMainManagerService(){}
     virtual ~IMainManagerService() {}

 public:
     /**
      * @brief addCenterWidget  添加窗口
      * @param icon             图标
      * @param name             名称
      * @param intro            简介
      * @param addWidget        添加的窗口
      */
     virtual void addCenterWidget(QIcon icon, const QString name,const QString intro,QWidget * addWidget) = 0;

     /**
      * @brief removeWidget     删除窗口
      * @param widget
      */
     virtual void removeWidget(QWidget * widget) = 0;


     /**
      * @brief removeWidget     添加插件窗口
      * @param widget
      */
     virtual void addFunctionWidget(QString plugName, QWidget* plugWidget) = 0;

     /**
      * @brief removeWidget     添加插件窗口
      * @param widget
      */
     virtual void addFunctionWidget(QWidget* plugWidget) = 0;

     /**
      * @brief pushUtcTime      设置utc时间
      * @param utcTime
      */
     virtual void pushUtcTime(QString utcTime) = 0;

     unsigned char** mark_0250;
     unsigned char** mark_0500;
     unsigned char** mark_1000;
     unsigned char** mark_2000;
     unsigned char** mark_4000;
 };


#define IMainManagerService_iid "org.casic.service.demo.IMainManagerService"
Q_DECLARE_INTERFACE(IMainManagerService, IMainManagerService_iid)

#endif //  IMAINMANAGERSERVICE_H
