#include "datamonitorpluginservice.h"
#include "DataMonitorDialog.h"
DataMonitorPluginService::DataMonitorPluginService(HMPPluginContext* pContext)
    : m_pContext(pContext)
{
    HMPServiceReference reference = m_pContext->getServiceReference<IMainManagerService>();
    if (reference)
    {
        IMainManagerService* manager = m_pContext->getService<IMainManagerService>(reference);
        m_dataMonitorDialog = new DataMonitorDialog;
        manager->addFunctionWidget(m_dataMonitorDialog);
    }
}

DataMonitorPluginService::~DataMonitorPluginService() {}
