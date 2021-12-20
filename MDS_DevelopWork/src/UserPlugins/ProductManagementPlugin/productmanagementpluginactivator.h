#ifndef PRODUCTMANAGEMENTPLUGINACTIVATOR_H 
#define PRODUCTMANAGEMENTPLUGINACTIVATOR_H 

#include <QObject>
#include <QtPlugin>
#include <HMPPluginActivator.h>

class ProductManagementPluginService;

class ProductManagementPluginActivator : public QObject, public HMPPluginActivator
{ 
   Q_OBJECT 
   Q_INTERFACES(HMPPluginActivator)

   //Qt5 
#if(QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))
   Q_PLUGIN_METADATA(IID "ProductManagementPluginActivator" ProductManagementPluginActivator)
#endif

public:
   ProductManagementPluginActivator():m_pService(NULL),m_pContext(NULL) {}

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
   ProductManagementPluginService *m_pService;             
   HMPPluginContext *m_pContext;     
}; 

#endif  // PRODUCTMANAGEMENTPLUGINACTIVATOR_H 

