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
    initMember();  //我爱西巴
}

CommonParameterPage::~CommonParameterPage() { delete ui; }

void CommonParameterPage::initMember()
{
    ui->tableWidget->layout()->addWidget(m_commonParameterTableView);
    ui->detailTableWidget->layout()->addWidget(m_commonParameterDetailTable);
}

void CommonParameterPage::on_pushButton_clicked() { this->close(); }
