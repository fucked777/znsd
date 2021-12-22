#include "CallProcessParameter.h"
#include "ui_CallProcessParameter.h"

CallProcessParameter::CallProcessParameter(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CallProcessParameter)
{
    ui->setupUi(this);
}

CallProcessParameter::~CallProcessParameter()
{
    delete ui;
}
