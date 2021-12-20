#include "reporttablepluginservice.h"
#include "ReportTablePage.h"
ReportTablePluginService::ReportTablePluginService(HMPPluginContext* pContext)
    : m_pContext(pContext)
{
    HMPServiceReference reference = m_pContext->getServiceReference<IMainManagerService>();
    if (reference)
    {
        IMainManagerService* manager = m_pContext->getService<IMainManagerService>(reference);
        m_reportTablePage = new ReportTablePage;
        manager->addFunctionWidget(m_reportTablePage);
    }
}

ReportTablePluginService::~ReportTablePluginService() {}
