#include "ReportTablePage.h"
#include "DataTransformPlugin/Plugin.h"
#include "DataTransformPlugin/idatatransformpluginservice.h"
#include "FaultMsgPage.h"
#include "LoadFilePage.h"
#include "LogMsgPage.h"
#include "ui_ReportTablePage.h"
#include <QFile>
ReportTablePage::ReportTablePage(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::ReportTablePage)
{
    ui->setupUi(this);
    m_faultMsgPage = new FaultMsgPage();
    m_logMsgPage = new LogMsgPage();
    m_loadFilePage = new LoadFilePage();
    ui->tabWidget->addTab(m_faultMsgPage, "故障信息");
    ui->tabWidget->addTab(m_logMsgPage, "日志信息");
    ui->tabWidget->addTab(m_loadFilePage, "载荷文件输入输出统计");
    QFile file(qApp->applicationDirPath() + "/../data/style/MainManager.qss");
    connect(this, &ReportTablePage::sendServerAndData, m_faultMsgPage, &FaultMsgPage::reciveServerAndData);
    file.open(QIODevice::ReadOnly);
    QString tabBarStyle = "QTabBar::tab {background:transparent;min-width:100px;color: white;border: 2px solid;border-top-left-radius: "
                          "10px;border-top-right-radius: 10px;padding:5px;}";
    //    ui->tabWidget->setStyleSheet(file.readAll());
    ui->tabWidget->setStyleSheet(tabBarStyle);
}
ReportTablePage::~ReportTablePage() { delete ui; }

void ReportTablePage::initMember() {}

void ReportTablePage::setServer(iDataTransformPluginService* server)
{
    //
    _server = server;
}

void ReportTablePage::reciveByteArray(QByteArray byteArrray)
{  //
    array = byteArrray;
}
