#ifndef IDATASYSTEMPLUGINSERVICE_H 
#define IDATASYSTEMPLUGINSERVICE_H 

#include <QObject>

#include "iobserviceinterface.h"

#include <QList>

class IDataDispatch;

class iDataSystemPluginService 
{ 
public: 
   virtual ~iDataSystemPluginService() {}


/*----------------------------------------------iServic Function -----------------------------------------*/


    //被观察者注册
    virtual void registerObService(iObServiceInterface *pIObService) =0;

    //被观察者反注册
    virtual void unregisterObService(iObServiceInterface *pIObService) =0;

    //请求数据
    virtual void requestObServiceMessgae(iObServiceInterface *pIObService)=0;

    //反请求数据
    virtual void unrequestObServiceMessgae(iObServiceInterface *pIObService)=0;

    virtual IDataDispatch* dispatcher() = 0;

    virtual void registServerStateSlot(QObject* recv,const char* slot) = 0;
/*----------------------------------------------iServic Function -----------------------------------------*/

}; 

#define iDataSystemPluginService_iid "org.casic.service.demo.iDataSystemPluginService" 
Q_DECLARE_INTERFACE(iDataSystemPluginService, iDataSystemPluginService_iid) 
#endif  // IDATASYSTEMPLUGINSERVICE_H 

