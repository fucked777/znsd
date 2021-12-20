#ifndef FAULTMANAGEMENTPLUGINSERVICE_H
#define FAULTMANAGEMENTPLUGINSERVICE_H

#include "HMPPluginActivator.h"
#include "MainManager/imainmanagerservice.h"
#include "ifaultmanagementpluginservice.h"
#include <QObject>
class FaultManagementDialog;
class FaultManagementPluginService : public QObject, public iFaultManagementPluginService
{
    Q_OBJECT
    Q_INTERFACES(iFaultManagementPluginService)
public:
    FaultManagementPluginService(HMPPluginContext* context);
    ~FaultManagementPluginService() override;

public:
    /*----------------------------------------------Servic Function -----------------------------------------*/

    /*----------------------------------------------Servic Function -----------------------------------------*/

private:
    HMPPluginContext* m_pContext;
    FaultManagementDialog* m_faultManagementDialog;
};

#endif  // FAULTMANAGEMENTPLUGINSERVICE_H
