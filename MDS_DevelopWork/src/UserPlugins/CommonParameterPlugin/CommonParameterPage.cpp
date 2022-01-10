#include "CommonParameterPage.h"
#include "CommonParameterDetailTable.h"
#include "CommonParameterTableView.h"
#include "ui_CommonParameterPage.h"
CommonParameterPage::CommonParameterPage(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::CommonParameterPage)
{
    ui->setupUi(this);
    m_commonParameterTableView = new CommonParameterTableView();
    m_commonParameterDetailTable = new CommonParameterDetailTable();
    connect(m_commonParameterTableView, &CommonParameterTableView::dataSendSignal, this, &CommonParameterPage::dataSendSlot);
    initMember();
}

CommonParameterPage::~CommonParameterPage() { delete ui; }

void CommonParameterPage::initMember()
{
    ui->tableWidget->layout()->addWidget(m_commonParameterTableView);
    ui->detailTableWidget->layout()->addWidget(m_commonParameterDetailTable);
}

void CommonParameterPage::on_pushButton_clicked() { this->close(); }

void CommonParameterPage::dataSendSlot(const QStringList& str)
{
    ui->curFileLabel->setText(str.at(1));
    ui->startTimeLabel->setText(str.at(3));
    CommonParameterDetail data;
    data.parameterName = str.at(0);
    data.chineseName = str.at(1);
    data.value = str.at(2);
    m_commonParameterDetailTable->appendRowData(data);
}
