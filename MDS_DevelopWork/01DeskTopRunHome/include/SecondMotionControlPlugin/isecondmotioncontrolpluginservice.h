#ifndef ISECONDMOTIONCONTROLPLUGINSERVICE_H 
#define ISECONDMOTIONCONTROLPLUGINSERVICE_H 

#include <QObject>

class iSecondMotionControlPluginService : public QObject 
{ 
public: 
   virtual ~iSecondMotionControlPluginService() override{}


/*----------------------------------------------iServic Function -----------------------------------------*/



/*----------------------------------------------iServic Function -----------------------------------------*/

}; 

#define iSecondMotionControlPluginService_iid "org.casic.service.demo.iSecondMotionControlPluginService" 
Q_DECLARE_INTERFACE(iSecondMotionControlPluginService, iSecondMotionControlPluginService_iid) 
#endif  // ISECONDMOTIONCONTROLPLUGINSERVICE_H 

