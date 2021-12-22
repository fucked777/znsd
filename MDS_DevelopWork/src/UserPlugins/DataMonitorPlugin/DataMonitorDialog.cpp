#include "DataMonitorDialog.h"
#include "ReceiveNodeNetworkStatus.h"
#include "SendNodeNetworkStatus.h"
#include "ui_DataMonitorDialog.h"
#pragma execution_character_set("utf-8")
DataMonitorDialog::DataMonitorDialog(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::DataMonitorDialog)
{
    ui->setupUi(this);
    m_sendNodeNetworkStatus = new SendNodeNetworkStatus();
    m_receiveNodeNetworkStatus = new ReceiveNodeNetworkStatus();
    ui->tabWidget->addTab(m_sendNodeNetworkStatus, "发送节点网络连接状态");
    ui->tabWidget->addTab(m_receiveNodeNetworkStatus, "接收节点网络连接状态");
    QString tabBarStyle = "QTabBar::tab {background:transparent;min-width:100px;color: white;border: 2px solid;}";
    ui->tabWidget->setStyleSheet(tabBarStyle);
}

DataMonitorDialog::~DataMonitorDialog() { delete ui; }
