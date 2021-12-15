#ifndef IDATAMONITORPLUGINSERVICE_H 
#define IDATAMONITORPLUGINSERVICE_H 

#include <QObject>

class iDataMonitorPluginService : public QObject 
{ 
public: 
   virtual ~iDataMonitorPluginService() override{}


/*----------------------------------------------iServic Function -----------------------------------------*/



/*----------------------------------------------iServic Function -----------------------------------------*/

}; 

#define iDataMonitorPluginService_iid "org.casic.service.demo.iDataMonitorPluginService" 
Q_DECLARE_INTERFACE(iDataMonitorPluginService, iDataMonitorPluginService_iid) 
#endif  // IDATAMONITORPLUGINSERVICE_H 

