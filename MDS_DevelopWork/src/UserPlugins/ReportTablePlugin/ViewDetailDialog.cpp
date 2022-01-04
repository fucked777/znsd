#include "ViewDetailDialog.h"
#include "ui_ViewDetailDialog.h"
#include <QDateTime>
#include <QDebug>
#define DISPLAY_TIME_FORMAT "yyyy-MM-dd HH:mm:ss"
ViewDetailDialog::ViewDetailDialog(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::ViewDetailDialog)
{
    ui->setupUi(this);
    ui->faultMsgtextEdit->setEnabled(false);
    ui->dateTimeEdit->setEnabled(false);
    connect(ui->dealRemarktextEdit, &QTextEdit::textChanged, this, &ViewDetailDialog::textCurtextChange);
}

ViewDetailDialog::~ViewDetailDialog() { delete ui; }

void ViewDetailDialog::parameterSet(const QStringList& data, int row)
{
    rowIndex = row;
    dealRemarks = data.at(8);
    ui->systemLabel->setText(data.at(4));
    ui->taskNameLabel->setText(data.at(3));
    ui->taskNumLabel->setText(data.at(2));
    ui->faultLabel->setText(data.at(0) + "(" + data.at(5) + ")");
    ui->dealRemarktextEdit->setText(data.at(8));

    ui->faultMsgtextEdit->setText(data.at(6));

    QDateTime startTime = dateTimeFromStr(data.at(1));
    //    startTime->setDisplayFormat(DISPLAY_TIME_FORMAT);
    ui->dateTimeEdit->setDateTime(startTime);
}
void ViewDetailDialog::textCurtextChange()
{
    dealRemarks = ui->dealRemarktextEdit->toPlainText();
    //    qDebug() << "dealRemarks" << dealRemarks;
}
//保存备注
void ViewDetailDialog::on_pushButton_clicked()
{
    emit saveRemarksSignal(dealRemarks, rowIndex);
    this->close();
}

QDateTime ViewDetailDialog::dateTimeFromStr(const QString& str) { return QDateTime::fromString(str, "yyyy-MM-dd HH:mm:ss"); }

QString ViewDetailDialog::dateTimeToStr(const QDateTime& t) { return t.toString("yyyy-MM-dd HH:mm:ss"); }
