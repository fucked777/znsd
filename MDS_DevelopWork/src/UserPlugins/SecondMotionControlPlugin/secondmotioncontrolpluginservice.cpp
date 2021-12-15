#include "secondmotioncontrolpluginservice.h"
#include "SecondMotionControlDialog.h"
SecondMotionControlPluginService::SecondMotionControlPluginService(HMPPluginContext* pContext)
    : m_pContext(pContext)
{
    HMPServiceReference reference = m_pContext->getServiceReference<IMainManagerService>();
    if (reference)
    {
        IMainManagerService* manager = m_pContext->getService<IMainManagerService>(reference);
        m_SecondMotionControlDialog = new SecondMotionControlDialog;
        manager->addFunctionWidget(m_SecondMotionControlDialog);
    }
}

SecondMotionControlPluginService::~SecondMotionControlPluginService() {}
