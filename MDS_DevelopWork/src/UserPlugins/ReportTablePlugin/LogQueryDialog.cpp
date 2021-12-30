#include "LogQueryDialog.h"
#include "ui_LogQueryDialog.h"

LogQueryDialog::LogQueryDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LogQueryDialog)
{
    ui->setupUi(this);
}

LogQueryDialog::~LogQueryDialog()
{
    delete ui;
}
