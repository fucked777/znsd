#include "commonparameterpluginactivator.h" 
#include "icommonparameterpluginservice.h" //Service interface 
#include "MainManager/imainmanagerservice.h" 

#include "commonparameterpluginservice.h"  //function realization
#include <QDebug>


//plugin main 
void CommonParameterPluginActivator::start(HMPPluginContext *pContext) 
{ 
   qDebug()<<"------------------>CommonParameterPluginPlugin START<-------------------"; 
   m_pContext = pContext;

   //! 00 Creat plugin Service
   if(!m_pService)
   { 
       m_pService = new CommonParameterPluginService(m_pContext);
   } 

   //! 01 Your plugin regsterService
   if(!m_pContext)
   { 
       m_pContext->registerService<iCommonParameterPluginService>(m_pService);
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
void CommonParameterPluginActivator::stop(HMPPluginContext *pContext) 
{ 
   qDebug()<<"------------------>CommonParameterPluginPlugin STOP<-------------------"; 
   
} 



//Qt4
#if(QT_VERSION < QT_VERSION_CHECK(5, 0, 0)) 
Q_EXPORT_PLUGIN2(CommonParameterPluginActivator, CommonParameterPluginActivator) 
#endif


