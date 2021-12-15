#ifndef DATABASETABLEQUERYPLUGINSERVICE_H
#define DATABASETABLEQUERYPLUGINSERVICE_H

#include "HMPPluginActivator.h"
#include "MainManager/imainmanagerservice.h"
#include "idatabasetablequerypluginservice.h"
#include <QObject>
class DatabaseTableQueryDialog;
class DatabaseTableQueryPluginService : public QObject, public iDatabaseTableQueryPluginService
{
    Q_OBJECT
    Q_INTERFACES(iDatabaseTableQueryPluginService)
public:
    DatabaseTableQueryPluginService(HMPPluginContext* context);
    ~DatabaseTableQueryPluginService() override;

public:
    /*----------------------------------------------Servic Function -----------------------------------------*/

    /*----------------------------------------------Servic Function -----------------------------------------*/

private:
    HMPPluginContext* m_pContext;
    DatabaseTableQueryDialog* m_databaseTableQueryDialog;
};

#endif  // DATABASETABLEQUERYPLUGINSERVICE_H
