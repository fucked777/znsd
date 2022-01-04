#include "DealFaultDialog.h"
#include "ui_DealFaultDialog.h"
DealFaultDialog::DealFaultDialog(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::DealFaultDialog)
{
    ui->setupUi(this);
    initMember();
    connect(ui->comboBox, &QComboBox::currentTextChanged, this, &DealFaultDialog::comboxCurtextChange);
    connect(ui->textEdit, &QTextEdit::textChanged, this, &DealFaultDialog::textCurtextChange);
}

DealFaultDialog::~DealFaultDialog() { delete ui; }

void DealFaultDialog::initMember()
{
    ui->comboBox->addItem("暂未处理");
    ui->comboBox->addItem("已处理");
    ui->comboBox->addItem("处理失败");
}
void DealFaultDialog::parameterSet(const QStringList& data, int row) { rowIndex = row; }

void DealFaultDialog::comboxCurtextChange(const QString& text) { comboxText = text; }

void DealFaultDialog::textCurtextChange() { dealRemarks = ui->textEdit->toPlainText(); }

//确定按钮
void DealFaultDialog::on_pushButton_clicked()
{
    emit dealRemarksSignal(dealRemarks, comboxText, rowIndex);
    this->close();
}
//取消
void DealFaultDialog::on_pushButton_2_clicked() { this->close(); }
