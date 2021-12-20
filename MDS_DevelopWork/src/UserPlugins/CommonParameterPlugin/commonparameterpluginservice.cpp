#include "commonparameterpluginservice.h"
#include "CommonParameterPage.h"
CommonParameterPluginService::CommonParameterPluginService(HMPPluginContext* pContext)
    : m_pContext(pContext)
{
    HMPServiceReference reference = m_pContext->getServiceReference<IMainManagerService>();
    if (reference)
    {
        IMainManagerService* manager = m_pContext->getService<IMainManagerService>(reference);
        m_CommonParameterPage = new CommonParameterPage;
        manager->addFunctionWidget(m_CommonParameterPage);
    }
}

CommonParameterPluginService::~CommonParameterPluginService() {}
