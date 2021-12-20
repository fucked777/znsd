#include "ReportTablePage.h"
#include "FaultMsgPage.h"
#include "LoadFilePage.h"
#include "LogMsgPage.h"
#include "ui_ReportTablePage.h"
ReportTablePage::ReportTablePage(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::ReportTablePage)
{
    ui->setupUi(this);
    m_faultMsgPage = new FaultMsgPage();
    m_logMsgPage = new LogMsgPage();
    m_loadFilePage = new LoadFilePage();
    m_buttonGroup = new QButtonGroup();
    m_buttonGroup->addButton(ui->faultMsgBtn, 0);
    m_buttonGroup->addButton(ui->logMsgBtn, 1);
    m_buttonGroup->addButton(ui->fileBtn, 2);
    ui->stackedWidget->addWidget(m_faultMsgPage);
    ui->stackedWidget->addWidget(m_logMsgPage);
    ui->stackedWidget->addWidget(m_loadFilePage);
    connect(m_buttonGroup, QOverload<int>::of(&QButtonGroup::buttonClicked), this, &ReportTablePage::showSwitchPage);
    initMember();
}

ReportTablePage::~ReportTablePage() { delete ui; }

void ReportTablePage::initMember() {}

void ReportTablePage::showSwitchPage(const int& index) { ui->stackedWidget->setCurrentIndex(index); }
