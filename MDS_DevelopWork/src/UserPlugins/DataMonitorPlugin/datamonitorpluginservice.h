#ifndef DATAMONITORPLUGINSERVICE_H
#define DATAMONITORPLUGINSERVICE_H

#include "HMPPluginActivator.h"
#include "MainManager/imainmanagerservice.h"
#include "idatamonitorpluginservice.h"
#include <QObject>
class DataMonitorDialog;
class DataMonitorPluginService : public QObject, public iDataMonitorPluginService
{
    Q_OBJECT
    Q_INTERFACES(iDataMonitorPluginService)
public:
    DataMonitorPluginService(HMPPluginContext* context);
    ~DataMonitorPluginService() override;

public:
    /*----------------------------------------------Servic Function -----------------------------------------*/

    /*----------------------------------------------Servic Function -----------------------------------------*/

private:
    HMPPluginContext* m_pContext;
    DataMonitorDialog* m_dataMonitorDialog;
};

#endif  // DATAMONITORPLUGINSERVICE_H
