#include "datamonitorpluginactivator.h" 
#include "idatamonitorpluginservice.h" //Service interface 
#include "MainManager/imainmanagerservice.h" 

#include "datamonitorpluginservice.h"  //function realization
#include <QDebug>


//plugin main 
void DataMonitorPluginActivator::start(HMPPluginContext *pContext) 
{ 
   qDebug()<<"------------------>DataMonitorPluginPlugin START<-------------------"; 
   m_pContext = pContext;

   //! 00 Creat plugin Service
   if(!m_pService)
   { 
       m_pService = new DataMonitorPluginService(m_pContext);
   } 

   //! 01 Your plugin regsterService
   if(!m_pContext)
   { 
       m_pContext->registerService<iDataMonitorPluginService>(m_pService);
   } 

   //! 02 GET MainManager Service 
   HMPServiceReference reference= m_pContext->getServiceReference<IMainManagerService>(); 
   if(reference)
   { 
       IMainManagerService *phello = m_pContext->getService<IMainManagerService>(reference);
       //! 03 CALL other pluginService function 
   } 
   
} 

//plugin end  
void DataMonitorPluginActivator::stop(HMPPluginContext *pContext) 
{ 
   qDebug()<<"------------------>DataMonitorPluginPlugin STOP<-------------------"; 
   
} 



//Qt4
#if(QT_VERSION < QT_VERSION_CHECK(5, 0, 0)) 
Q_EXPORT_PLUGIN2(DataMonitorPluginActivator, DataMonitorPluginActivator) 
#endif


