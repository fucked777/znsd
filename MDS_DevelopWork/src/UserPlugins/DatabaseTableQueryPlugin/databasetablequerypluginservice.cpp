#include "databasetablequerypluginservice.h"
#include "DatabaseTableQueryDialog.h"
DatabaseTableQueryPluginService::DatabaseTableQueryPluginService(HMPPluginContext* pContext)
    : m_pContext(pContext)
{
    HMPServiceReference reference = m_pContext->getServiceReference<IMainManagerService>();
    if (reference)
    {
        IMainManagerService* manager = m_pContext->getService<IMainManagerService>(reference);
        m_databaseTableQueryDialog = new DatabaseTableQueryDialog;
        manager->addFunctionWidget(m_databaseTableQueryDialog);
    }
}

DatabaseTableQueryPluginService::~DatabaseTableQueryPluginService() {}
