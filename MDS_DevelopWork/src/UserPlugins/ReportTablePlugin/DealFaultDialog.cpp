#include "DealFaultDialog.h"
#include "ui_DealFaultDialog.h"

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
    ui->comboBox->addItem("暂未处理");
    ui->comboBox->addItem("已经处理");
    ui->comboBox->addItem("处理失败");
}
