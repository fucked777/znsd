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
void DealFaultDialog::parameterSet(const QStringList& data)
{
    QString dealStatus = data.at(5);

    ui->comboBox->setCurrentText(dealStatus);
}

void DealFaultDialog::comboxCurtextChange(const QString& text)
{
    //得到输入字符串
    comboxText = text;

    //    int Index = szText.toInt();
    //    dealRemarks = ui->textEdit->textChanged()
}

void DealFaultDialog::textCurtextChange()
{
    //    ui->textEdit->;
}
