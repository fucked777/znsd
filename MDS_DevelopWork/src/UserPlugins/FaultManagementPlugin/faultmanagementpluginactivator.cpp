#include "faultmanagementpluginactivator.h" 
#include "ifaultmanagementpluginservice.h" //Service interface 
#include "MainManager/imainmanagerservice.h" 

#include "faultmanagementpluginservice.h"  //function realization
#include <QDebug>


//plugin main 
void FaultManagementPluginActivator::start(HMPPluginContext *pContext) 
{ 
   qDebug()<<"------------------>FaultManagementPluginPlugin START<-------------------"; 
   m_pContext = pContext;

   //! 00 Creat plugin Service
   if(!m_pService)
   { 
       m_pService = new FaultManagementPluginService(m_pContext);
   } 

   //! 01 Your plugin regsterService
   if(!m_pContext)
   { 
       m_pContext->registerService<iFaultManagementPluginService>(m_pService);
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
void FaultManagementPluginActivator::stop(HMPPluginContext *pContext) 
{ 
   qDebug()<<"------------------>FaultManagementPluginPlugin STOP<-------------------"; 
   
} 



//Qt4
#if(QT_VERSION < QT_VERSION_CHECK(5, 0, 0)) 
Q_EXPORT_PLUGIN2(FaultManagementPluginActivator, FaultManagementPluginActivator) 
#endif


