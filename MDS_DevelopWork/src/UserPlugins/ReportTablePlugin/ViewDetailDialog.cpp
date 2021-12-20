#include "ViewDetailDialog.h"
#include "ui_ViewDetailDialog.h"

ViewDetailDialog::ViewDetailDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ViewDetailDialog)
{
    ui->setupUi(this);
}

ViewDetailDialog::~ViewDetailDialog()
{
    delete ui;
}
