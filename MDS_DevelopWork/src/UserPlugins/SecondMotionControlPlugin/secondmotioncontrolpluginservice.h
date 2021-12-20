#ifndef SECONDMOTIONCONTROLPLUGINSERVICE_H
#define SECONDMOTIONCONTROLPLUGINSERVICE_H

#include "HMPPluginActivator.h"
#include "MainManager/imainmanagerservice.h"
#include "isecondmotioncontrolpluginservice.h"
#include <QObject>
class SecondMotionControlDialog;
class SecondMotionControlPluginService : public QObject, public iSecondMotionControlPluginService
{
    Q_OBJECT
    Q_INTERFACES(iSecondMotionControlPluginService)
public:
    SecondMotionControlPluginService(HMPPluginContext* context);
    ~SecondMotionControlPluginService() override;

public:
    /*----------------------------------------------Servic Function -----------------------------------------*/

    /*----------------------------------------------Servic Function -----------------------------------------*/

private:
    HMPPluginContext* m_pContext;
    SecondMotionControlDialog* m_SecondMotionControlDialog;
};

#endif  // SECONDMOTIONCONTROLPLUGINSERVICE_H
