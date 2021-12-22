#include "FaultPageFream.h"
#include "CallProcessParameter.h"
#include "FaultLog.h"
#include "InputOutputData.h"
#include "SystemLog.h"
#include "ui_FaultPageFream.h"
#include <QDebug>
FaultPageFream::FaultPageFream(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::FaultPageFream)
{
    ui->setupUi(this);
    m_inputOutputData = new InputOutputData();
    m_faultLog = new FaultLog();
    m_systemLog = new SystemLog();
    m_callProcessParameter = new CallProcessParameter();

    ui->tabWidget->addTab(m_inputOutputData, "输入输出数据");
    ui->tabWidget->addTab(m_faultLog, "故障日志");
    ui->tabWidget->addTab(m_systemLog, "系统日志");
    ui->tabWidget->addTab(m_callProcessParameter, "调用进程参数");

    //    connect(ui->tabWidget, &QTabWidget::tabBarClicked, faultPageFream, &FaultPageFream::showSwitchPage);

    QString tabBarStyle = "QTabBar::tab {background:transparent;min-width:100px;color: white;border: 2px solid;border-top-left-radius: "
                          "10px;border-top-right-radius: 10px;padding:5px;}";
    ui->tabWidget->setStyleSheet(tabBarStyle);
    //    initMember();
}

FaultPageFream::~FaultPageFream() { delete ui; }

void FaultPageFream::showSwitchPage(const int& index) { qDebug() << "index:" << index; }
