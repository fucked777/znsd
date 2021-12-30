#include "LoadFilePage.h"
#include "ui_LoadFilePage.h"

LoadFilePage::LoadFilePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoadFilePage)
{
    ui->setupUi(this);
}

LoadFilePage::~LoadFilePage()
{
    delete ui;
}
