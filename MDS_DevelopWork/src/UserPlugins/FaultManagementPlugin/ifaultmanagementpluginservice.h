#ifndef IFAULTMANAGEMENTPLUGINSERVICE_H 
#define IFAULTMANAGEMENTPLUGINSERVICE_H 

#include <QObject>

class iFaultManagementPluginService : public QObject 
{ 
public: 
   virtual ~iFaultManagementPluginService() override{}


/*----------------------------------------------iServic Function -----------------------------------------*/



/*----------------------------------------------iServic Function -----------------------------------------*/

}; 

#define iFaultManagementPluginService_iid "org.casic.service.demo.iFaultManagementPluginService" 
Q_DECLARE_INTERFACE(iFaultManagementPluginService, iFaultManagementPluginService_iid) 
#endif  // IFAULTMANAGEMENTPLUGINSERVICE_H 

