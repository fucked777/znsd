#ifndef IDATATRANSFORMPLUGINSERVICE_H 
#define IDATATRANSFORMPLUGINSERVICE_H 

#include <QObject>
class AbsPluginManager;
class AbsCmdControl;

class iDataTransformPluginService  
{ 
public: 
   virtual ~iDataTransformPluginService() {}

/*----------------------------------------------iServic Function -----------------------------------------*/
   virtual AbsPluginManager* pluginManager() = 0;

   virtual AbsCmdControl* cmdControl() = 0;
/*----------------------------------------------iServic Function -----------------------------------------*/

}; 

#define iDataTransformPluginService_iid "org.casic.service.demo.iDataTransformPluginService" 
Q_DECLARE_INTERFACE(iDataTransformPluginService, iDataTransformPluginService_iid) 
#endif  // IDATATRANSFORMPLUGINSERVICE_H 

