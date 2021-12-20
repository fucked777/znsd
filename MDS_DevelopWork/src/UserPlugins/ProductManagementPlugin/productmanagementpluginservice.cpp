#include "productmanagementpluginservice.h"
#include "ProductManagementDialog.h"
ProductManagementPluginService::ProductManagementPluginService(HMPPluginContext* pContext)
    : m_pContext(pContext)
{
    HMPServiceReference reference = m_pContext->getServiceReference<IMainManagerService>();
    if (reference)
    {
        IMainManagerService* manager = m_pContext->getService<IMainManagerService>(reference);
        m_productManagementDialog = new ProductManagementDialog;
        manager->addFunctionWidget(m_productManagementDialog);
    }
}

ProductManagementPluginService::~ProductManagementPluginService() {}
