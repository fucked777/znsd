#include "FaultPageFream.h"
#include "ui_FaultPageFream.h"
#include <QDebug>
FaultPageFream::FaultPageFream(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::FaultPageFream)
{
    ui->setupUi(this);
}

FaultPageFream::~FaultPageFream() { delete ui; }

void FaultPageFream::showSwitchPage(const int& index) { qDebug() << "index:" << index; }
