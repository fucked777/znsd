#ifndef COMMONPARAMETERPLUGINACTIVATOR_H
#define COMMONPARAMETERPLUGINACTIVATOR_H

#include "CommonParameterPage.h"
#include <HMPPluginActivator.h>
#include <QObject>
#include <QtPlugin>
class CommonParameterPluginService;

class CommonParameterPluginActivator : public QObject, public HMPPluginActivator
{
    Q_OBJECT
    Q_INTERFACES(HMPPluginActivator)

    // Qt5
#if (QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))
    Q_PLUGIN_METADATA(IID "CommonParameterPluginActivator" CommonParameterPluginActivator)
#endif

public:
    CommonParameterPluginActivator()
        : m_pService(NULL)
        , m_pContext(NULL)
    {
    }

public:
    /**
     * @brief start
     * @param context
     */
    virtual void start(HMPPluginContext* context) override;
    /**
     * @brief stop
     * @param context
     */
    virtual void stop(HMPPluginContext* context) override;

private:
    CommonParameterPluginService* m_pService;
    HMPPluginContext* m_pContext;
};

#endif  // COMMONPARAMETERPLUGINACTIVATOR_H
