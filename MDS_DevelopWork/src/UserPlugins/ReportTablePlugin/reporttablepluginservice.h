#ifndef REPORTTABLEPLUGINSERVICE_H
#define REPORTTABLEPLUGINSERVICE_H

#include "HMPPluginActivator.h"
#include "MainManager/imainmanagerservice.h"
#include "ireporttablepluginservice.h"
#include <QObject>
class ReportTablePage;
class ReportTablePlugin;
class ReportTablePluginService : public QObject, public iReportTablePluginService
{
    Q_OBJECT
    Q_INTERFACES(iReportTablePluginService)
public:
    ReportTablePluginService(HMPPluginContext* context);
    ~ReportTablePluginService() override;

public:
    /*----------------------------------------------Servic Function -----------------------------------------*/
    ReportTablePage* m_reportTablePage;

    ReportTablePlugin* reportTablePlugin;
    /*----------------------------------------------Servic Function -----------------------------------------*/

private:
    HMPPluginContext* m_pContext;
};

#endif  // REPORTTABLEPLUGINSERVICE_H
