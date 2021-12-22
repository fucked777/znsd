#include "DealFaultDialog.h"
#include "ui_DealFaultDialog.h"
#pragma execution_character_set("utf-8")
DealFaultDialog::DealFaultDialog(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::DealFaultDialog)
{
    ui->setupUi(this);
    initMember();
}

DealFaultDialog::~DealFaultDialog() { delete ui; }

void DealFaultDialog::initMember()
{
    ui->comboBox->addItem("未处理");
    ui->comboBox->addItem("已处理");
    ui->comboBox->addItem("处理失败");
}
