#include "DataMonitorDialog.h"
#include "ui_DataMonitorDialog.h"

DataMonitorDialog::DataMonitorDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DataMonitorDialog)
{
    ui->setupUi(this);
}

DataMonitorDialog::~DataMonitorDialog()
{
    delete ui;
}
