#ifndef FIRSTDEMOSERVICE_H 
#define FIRSTDEMOSERVICE_H 

#include "ifirstdemoservice.h" 
#include "HMPPluginActivator.h" 
#include <QObject> 

class FirstDemoService : public QObject, public iFirstDemoService 
{ 
    Q_OBJECT 
    Q_INTERFACES(iFirstDemoService) 
public: 
    FirstDemoService( HMPPluginContext* context); 
    ~FirstDemoService() override; 


public: 
/*----------------------------------------------Servic Function -----------------------------------------*/



/*----------------------------------------------Servic Function -----------------------------------------*/

private: 
   HMPPluginContext *m_pContext;
}; 

#endif  // FIRSTDEMOSERVICE_H 

