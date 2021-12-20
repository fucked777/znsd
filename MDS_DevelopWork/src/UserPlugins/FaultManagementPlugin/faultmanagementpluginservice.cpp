#include "faultmanagementpluginservice.h"
#include "FaultManagementDialog.h"
FaultManagementPluginService::FaultManagementPluginService(HMPPluginContext* pContext)
    : m_pContext(pContext)
{
    HMPServiceReference reference = m_pContext->getServiceReference<IMainManagerService>();
    if (reference)
    {
        IMainManagerService* manager = m_pContext->getService<IMainManagerService>(reference);
        m_faultManagementDialog = new FaultManagementDialog;
        manager->addFunctionWidget(m_faultManagementDialog);
    }
}

FaultManagementPluginService::~FaultManagementPluginService() {}
