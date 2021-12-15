#ifndef FAULTMANAGEMENTPLUGINACTIVATOR_H 
#define FAULTMANAGEMENTPLUGINACTIVATOR_H 

#include <QObject>
#include <QtPlugin>
#include <HMPPluginActivator.h>

class FaultManagementPluginService;

class FaultManagementPluginActivator : public QObject, public HMPPluginActivator
{ 
   Q_OBJECT 
   Q_INTERFACES(HMPPluginActivator)

   //Qt5 
#if(QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))
   Q_PLUGIN_METADATA(IID "FaultManagementPluginActivator" FaultManagementPluginActivator)
#endif

public:
   FaultManagementPluginActivator():m_pService(NULL),m_pContext(NULL) {}

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
   FaultManagementPluginService *m_pService;             
   HMPPluginContext *m_pContext;     
}; 

#endif  // FAULTMANAGEMENTPLUGINACTIVATOR_H 

