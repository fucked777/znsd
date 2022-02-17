#ifndef SECONDMOTIONCONTROLPLUGINACTIVATOR_H
#define SECONDMOTIONCONTROLPLUGINACTIVATOR_H

#include <HMPPluginActivator.h>
#include <QObject>
#include <QtPlugin>

class SecondMotionControlPluginService;

class SecondMotionControlPluginActivator : public QObject, public HMPPluginActivator
{
    Q_OBJECT
    Q_INTERFACES(HMPPluginActivator)

    // Qt5
#if (QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))
    Q_PLUGIN_METADATA(IID "SecondMotionControlPluginActivator" SecondMotionControlPluginActivator)
#endif

public:
    SecondMotionControlPluginActivator()
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
    SecondMotionControlPluginService* m_pService;
    HMPPluginContext* m_pContext;
};

#endif  // SECONDMOTIONCONTROLPLUGINACTIVATOR_H
