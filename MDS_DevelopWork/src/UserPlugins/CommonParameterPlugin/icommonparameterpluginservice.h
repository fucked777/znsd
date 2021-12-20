#ifndef ICOMMONPARAMETERPLUGINSERVICE_H 
#define ICOMMONPARAMETERPLUGINSERVICE_H 

#include <QObject>

class iCommonParameterPluginService : public QObject 
{ 
public: 
   virtual ~iCommonParameterPluginService() override{}


/*----------------------------------------------iServic Function -----------------------------------------*/



/*----------------------------------------------iServic Function -----------------------------------------*/

}; 

#define iCommonParameterPluginService_iid "org.casic.service.demo.iCommonParameterPluginService" 
Q_DECLARE_INTERFACE(iCommonParameterPluginService, iCommonParameterPluginService_iid) 
#endif  // ICOMMONPARAMETERPLUGINSERVICE_H 

