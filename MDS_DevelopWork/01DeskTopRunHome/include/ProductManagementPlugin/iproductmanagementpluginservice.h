#ifndef IPRODUCTMANAGEMENTPLUGINSERVICE_H 
#define IPRODUCTMANAGEMENTPLUGINSERVICE_H 

#include <QObject>

class iProductManagementPluginService : public QObject 
{ 
public: 
   virtual ~iProductManagementPluginService() override{}


/*----------------------------------------------iServic Function -----------------------------------------*/



/*----------------------------------------------iServic Function -----------------------------------------*/

}; 

#define iProductManagementPluginService_iid "org.casic.service.demo.iProductManagementPluginService" 
Q_DECLARE_INTERFACE(iProductManagementPluginService, iProductManagementPluginService_iid) 
#endif  // IPRODUCTMANAGEMENTPLUGINSERVICE_H 

