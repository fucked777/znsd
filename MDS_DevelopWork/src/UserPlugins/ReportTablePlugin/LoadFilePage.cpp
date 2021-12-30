#include "LoadFilePage.h"
#include "ui_LoadFilePage.h"

LoadFilePage::LoadFilePage(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::LoadFilePage)
{
    ui->setupUi(this);
    initMember();
}

LoadFilePage::~LoadFilePage() { delete ui; }

void LoadFilePage::initMember()
{
    ui->comboBox->addItem("成像仪", -1);
    ui->comboBox->addItem("快速成像仪", -1);
    ui->comboBox->addItem("探测仪", -1);
}
