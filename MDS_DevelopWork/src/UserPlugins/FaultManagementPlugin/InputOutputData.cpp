#include "InputOutputData.h"
#include "ui_InputOutputData.h"

InputOutputData::InputOutputData(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InputOutputData)
{
    ui->setupUi(this);
}

InputOutputData::~InputOutputData()
{
    delete ui;
}
