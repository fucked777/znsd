#include "reporttablepluginactivator.h" 
#include "ireporttablepluginservice.h" //Service interface 
#include "MainManager/imainmanagerservice.h" 

#include "reporttablepluginservice.h"  //function realization
#include <QDebug>


//plugin main 
void ReportTablePluginActivator::start(HMPPluginContext *pContext) 
{ 
   qDebug()<<"------------------>ReportTablePluginPlugin START<-------------------"; 
   m_pContext = pContext;

   //! 00 Creat plugin Service
   if(!m_pService)
   { 
       m_pService = new ReportTablePluginService(m_pContext);
   } 

   //! 01 Your plugin regsterService
   if(!m_pContext)
   { 
       m_pContext->registerService<iReportTablePluginService>(m_pService);
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
void ReportTablePluginActivator::stop(HMPPluginContext *pContext) 
{ 
   qDebug()<<"------------------>ReportTablePluginPlugin STOP<-------------------"; 
   
} 



//Qt4
#if(QT_VERSION < QT_VERSION_CHECK(5, 0, 0)) 
Q_EXPORT_PLUGIN2(ReportTablePluginActivator, ReportTablePluginActivator) 
#endif


