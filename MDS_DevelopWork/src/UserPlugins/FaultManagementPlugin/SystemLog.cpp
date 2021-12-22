#include "SystemLog.h"
#include "ui_SystemLog.h"

SystemLog::SystemLog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SystemLog)
{
    ui->setupUi(this);
}

SystemLog::~SystemLog()
{
    delete ui;
}
