#ifndef COMMONPARAMETERPLUGINSERVICE_H
#define COMMONPARAMETERPLUGINSERVICE_H

#include "HMPPluginActivator.h"
#include "MainManager/imainmanagerservice.h"
#include "icommonparameterpluginservice.h"
#include <QObject>
class CommonParameterPage;
class CommonParameterPluginService : public QObject, public iCommonParameterPluginService
{
    Q_OBJECT
    Q_INTERFACES(iCommonParameterPluginService)
public:
    CommonParameterPluginService(HMPPluginContext* context);
    ~CommonParameterPluginService() override;

public:
    /*----------------------------------------------Servic Function -----------------------------------------*/

    /*----------------------------------------------Servic Function -----------------------------------------*/

private:
    HMPPluginContext* m_pContext;
    CommonParameterPage* m_CommonParameterPage;
};

#endif  // COMMONPARAMETERPLUGINSERVICE_H
