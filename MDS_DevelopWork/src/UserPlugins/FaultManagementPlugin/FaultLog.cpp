#include "FaultLog.h"
#include "ui_FaultLog.h"

FaultLog::FaultLog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FaultLog)
{
    ui->setupUi(this);
}

FaultLog::~FaultLog()
{
    delete ui;
}
