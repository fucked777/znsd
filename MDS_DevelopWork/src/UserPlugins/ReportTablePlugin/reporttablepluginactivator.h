#ifndef REPORTTABLEPLUGINACTIVATOR_H
#define REPORTTABLEPLUGINACTIVATOR_H

#include <HMPPluginActivator.h>
#include <QObject>
#include <QtPlugin>

class ReportTablePluginService;

class ReportTablePluginActivator : public QObject, public HMPPluginActivator
{
    Q_OBJECT
    Q_INTERFACES(HMPPluginActivator)

    // Qt5
#if (QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))
    Q_PLUGIN_METADATA(IID "ReportTablePluginActivator" ReportTablePluginActivator)
#endif

public:
    ReportTablePluginActivator()
        : m_pService(NULL)
        , m_pContext(NULL)
    {
    }
    virtual ~ReportTablePluginActivator();

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
    ReportTablePluginService* m_pService;
    HMPPluginContext* m_pContext;
};

#endif  // REPORTTABLEPLUGINACTIVATOR_H
