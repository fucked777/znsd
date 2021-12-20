#include "FaultManagementDialog.h"
#include "DetectorPage.h"
#include "FastImagerPage.h"
#include "ImagerPage.h"
#include "StellarPredictionPage.h"
#include "ui_FaultManagementDialog.h"
FaultManagementDialog::FaultManagementDialog(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::FaultManagementDialog)
{
    ui->setupUi(this);
    m_imagerPage = new ImagerPage();
    m_fastImagerPage = new FastImagerPage();
    m_detectorPage = new DetectorPage();
    m_stellarPredictionPage = new StellarPredictionPage();
    m_buttonGroup = new QButtonGroup();
    m_buttonGroup->addButton(ui->imagerBtn, 0);
    m_buttonGroup->addButton(ui->fastImagerBtn, 1);
    m_buttonGroup->addButton(ui->detectorBtn, 2);
    //    m_buttonGroup->addButton(ui->stellarBtn, 3);
    ui->DataStackedWidget->addWidget(m_imagerPage);
    ui->DataStackedWidget->addWidget(m_fastImagerPage);
    ui->DataStackedWidget->addWidget(m_detectorPage);
    ui->DataStackedWidget->addWidget(m_stellarPredictionPage);
    connect(m_buttonGroup, QOverload<int>::of(&QButtonGroup::buttonClicked), this, &FaultManagementDialog::showSwitchPage);
    initMember();
}

FaultManagementDialog::~FaultManagementDialog() { delete ui; }

void FaultManagementDialog::initMember() {}

void FaultManagementDialog::showSwitchPage(const int& index) { ui->DataStackedWidget->setCurrentIndex(index); }
