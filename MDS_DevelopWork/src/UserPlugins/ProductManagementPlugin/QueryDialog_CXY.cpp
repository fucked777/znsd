#include "QueryDialog_CXY.h"
#include "ui_QueryDialog_CXY.h"
#include <QMessageBox>
QueryDialog_CXY::QueryDialog_CXY(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::QueryDialog_CXY)
{
    ui->setupUi(this);
    ui->comboBox->addItem("全员盘常规观测", -1);
    ui->comboBox->addItem("恒星观测", -1);
}

QueryDialog_CXY::~QueryDialog_CXY() { delete ui; }

//查询
void QueryDialog_CXY::on_pushButton_clicked()
{
    QDateTime startTime = ui->startDateTimeEdit->dateTime();
    QDateTime endTime = ui->endDateTimeEdit->dateTime();
    if (startTime > endTime)
    {
        QMessageBox::warning(this, "提示", "查询开始时间不能晚于结束时间", QString("确定"));
        return;
    }

    QStringList taskName_list;
    if (!ui->comboBox->currentData().toString().isEmpty())
    {
        taskName_list.append(ui->comboBox->currentText());
    }

    QStringList taskNum_list;
    if (!ui->taskNumLineEdit->text().isEmpty())
    {
        taskNum_list.append(ui->taskNumLineEdit->text());
    }

    QStringList fileName_list;
    if (!ui->fileNameLineEdit->text().isEmpty())
    {
        fileName_list.append(ui->fileNameLineEdit->text());
    }

    QStringList outputType_list;
    if (!ui->outputTypeLineEdit->text().isEmpty())
    {
        outputType_list.append(ui->outputTypeLineEdit->text());
    }
    emit search(taskName_list, taskNum_list, fileName_list, outputType_list, startTime, endTime);
}

void QueryDialog_CXY::on_pushButton_2_clicked() { this->close(); }
