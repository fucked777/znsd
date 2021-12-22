#include "ReceiveNodeNetworkStatus.h"
#include "ui_ReceiveNodeNetworkStatus.h"

ReceiveNodeNetworkStatus::ReceiveNodeNetworkStatus(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::ReceiveNodeNetworkStatus)
{
    ui->setupUi(this);
    ui->comboBox->addItem("192.168.20.1", "");
    ui->comboBox->addItem("192.168.20.1", "");
    ui->comboBox->addItem("192.168.20.1", "");
    ui->comboBox->addItem("192.168.20.1", "");
}

ReceiveNodeNetworkStatus::~ReceiveNodeNetworkStatus() { delete ui; }
