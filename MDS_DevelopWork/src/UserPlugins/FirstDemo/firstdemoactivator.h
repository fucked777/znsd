#ifndef FIRSTDEMOACTIVATOR_H 
#define FIRSTDEMOACTIVATOR_H 

#include <QObject>
#include <QtPlugin>
#include <HMPPluginActivator.h>
#include"dialog.h"
class FirstDemoService;

class FirstDemoActivator : public QObject, public HMPPluginActivator
{ 
   Q_OBJECT 
   Q_INTERFACES(HMPPluginActivator)

   //Qt5 
#if(QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))
   Q_PLUGIN_METADATA(IID "FirstDemoActivator" FirstDemoActivator)
#endif

public:
   FirstDemoActivator():m_pService(NULL),m_pContext(NULL) {}

public:
   /**
    * @brief start     
    * @param context   
    */
    virtual void start(HMPPluginContext* context) override;
   /**
    * @brief stop      
    * @param context   
    */
    virtual void stop(HMPPluginContext* context) override;
private:
   FirstDemoService *m_pService;             
   HMPPluginContext *m_pContext;     
}; 

#endif  // FIRSTDEMOACTIVATOR_H 

