#include "reporttablepluginservice.h"
#include "DataTransformPlugin/idatatransformpluginservice.h"
#include "ReportTablePage.h"

#include "ReportTablePlugin.h"
ReportTablePluginService::ReportTablePluginService(HMPPluginContext* pContext)
    : m_pContext(pContext)
{
    HMPServiceReference reference = m_pContext->getServiceReference<IMainManagerService>();
    if (reference)
    {
        IMainManagerService* manager = m_pContext->getService<IMainManagerService>(reference);
        m_reportTablePage = new ReportTablePage;
        manager->addFunctionWidget(m_reportTablePage);
    }

    HMPServiceReference trans_rerence = m_pContext->getServiceReference<iDataTransformPluginService>();
    if (trans_rerence)
    {
        iDataTransformPluginService* s = m_pContext->getService<iDataTransformPluginService>(trans_rerence);
        if (s)
        {
            m_reportTablePage->setServer(s);
            reportTablePlugin = new ReportTablePlugin;
            //
            // TestSender* sender = qobject_cast<TestSender*>(testPlugin->sender()->object());
            reportTableSender* sender = dynamic_cast<reportTableSender*>(reportTablePlugin->sender());
            //            connect(sender, QOverload<QString>::of(&reportTableSender::push_label), m_reportTablePage,
            //            QOverload<QString>::of(&Test::testLabel)); connect(sender, QOverload<QPixmap>::of(&reportTableSender::push_label),
            //            m_reportTablePage, QOverload<QPixmap>::of(&Test::testLabel));

            s->pluginManager()->addPlugin(reportTablePlugin);
        }
    }
}

ReportTablePluginService::~ReportTablePluginService()
{
    HMPServiceReference trans_rerence = m_pContext->getServiceReference<iDataTransformPluginService>();
    if (trans_rerence)
    {
        iDataTransformPluginService* s = m_pContext->getService<iDataTransformPluginService>(trans_rerence);
        if (s)
        {
            s->pluginManager()->removePlugin(reportTablePlugin);
            delete reportTablePlugin;
            reportTablePlugin = nullptr;
        }
    }

    m_reportTablePage->deleteLater();
    m_pContext = 0;
}
