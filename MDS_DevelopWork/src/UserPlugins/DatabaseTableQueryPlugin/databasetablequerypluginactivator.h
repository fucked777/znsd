#ifndef DATABASETABLEQUERYPLUGINACTIVATOR_H 
#define DATABASETABLEQUERYPLUGINACTIVATOR_H 

#include <QObject>
#include <QtPlugin>
#include <HMPPluginActivator.h>

class DatabaseTableQueryPluginService;

class DatabaseTableQueryPluginActivator : public QObject, public HMPPluginActivator
{ 
   Q_OBJECT 
   Q_INTERFACES(HMPPluginActivator)

   //Qt5 
#if(QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))
   Q_PLUGIN_METADATA(IID "DatabaseTableQueryPluginActivator" DatabaseTableQueryPluginActivator)
#endif

public:
   DatabaseTableQueryPluginActivator():m_pService(NULL),m_pContext(NULL) {}

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
   DatabaseTableQueryPluginService *m_pService;             
   HMPPluginContext *m_pContext;     
}; 

#endif  // DATABASETABLEQUERYPLUGINACTIVATOR_H 

