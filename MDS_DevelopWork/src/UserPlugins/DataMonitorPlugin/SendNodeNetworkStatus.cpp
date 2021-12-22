#include "SendNodeNetworkStatus.h"
#include "ui_SendNodeNetworkStatus.h"

SendNodeNetworkStatus::SendNodeNetworkStatus(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SendNodeNetworkStatus)
{
    ui->setupUi(this);
}

SendNodeNetworkStatus::~SendNodeNetworkStatus()
{
    delete ui;
}
