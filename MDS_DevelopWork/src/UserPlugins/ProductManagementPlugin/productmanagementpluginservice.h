#ifndef PRODUCTMANAGEMENTPLUGINSERVICE_H
#define PRODUCTMANAGEMENTPLUGINSERVICE_H

#include "HMPPluginActivator.h"
#include "MainManager/imainmanagerservice.h"
#include "iproductmanagementpluginservice.h"
#include <QObject>
class ProductManagementDialog;
class ProductManagementPluginService : public QObject, public iProductManagementPluginService
{
    Q_OBJECT
    Q_INTERFACES(iProductManagementPluginService)
public:
    ProductManagementPluginService(HMPPluginContext* context);
    ~ProductManagementPluginService() override;

public:
    /*----------------------------------------------Servic Function -----------------------------------------*/

    /*----------------------------------------------Servic Function -----------------------------------------*/

private:
    HMPPluginContext* m_pContext;
    ProductManagementDialog* m_productManagementDialog;
};

#endif  // PRODUCTMANAGEMENTPLUGINSERVICE_H
