#include "ProductManagementDialog.h"
#include "DetectorPage.h"
#include "FastImagerPage.h"
#include "ImagerPage.h"
#include "StellarPredictionPage.h"
#include "ui_ProductManagementDialog.h"
ProductManagementDialog::ProductManagementDialog(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::ProductManagementDialog)
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
    m_buttonGroup->addButton(ui->stellarBtn, 3);
    ui->stackedWidget->addWidget(m_imagerPage);
    ui->stackedWidget->addWidget(m_fastImagerPage);
    ui->stackedWidget->addWidget(m_detectorPage);
    ui->stackedWidget->addWidget(m_stellarPredictionPage);
    connect(m_buttonGroup, QOverload<int>::of(&QButtonGroup::buttonClicked), this, &ProductManagementDialog::showSwitchPage);
    initMember();
}

ProductManagementDialog::~ProductManagementDialog() { delete ui; }

void ProductManagementDialog::initMember() {}

void ProductManagementDialog::showSwitchPage(const int& index) { ui->stackedWidget->setCurrentIndex(index); }
