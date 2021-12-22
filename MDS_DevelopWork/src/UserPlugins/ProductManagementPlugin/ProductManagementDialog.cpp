#include "ProductManagementDialog.h"
#include "DetectorPage.h"
#include "FastImagerPage.h"
#include "ImagerPage.h"
#include "StellarPredictionPage.h"
#include "ui_ProductManagementDialog.h"
#include <QFile>
#pragma execution_character_set("utf-8")
ProductManagementDialog::ProductManagementDialog(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::ProductManagementDialog)
{
    ui->setupUi(this);
    m_imagerPage = new ImagerPage();
    m_fastImagerPage = new FastImagerPage();
    m_detectorPage = new DetectorPage();
    m_stellarPredictionPage = new StellarPredictionPage();

    ui->tabWidget->addTab(m_imagerPage, "成像仪产品");
    ui->tabWidget->addTab(m_fastImagerPage, "快速成像仪产品");
    ui->tabWidget->addTab(m_detectorPage, "探测仪产品");
    ui->tabWidget->addTab(m_stellarPredictionPage, "恒星预报产品");
    //    QFile file(qApp->applicationDirPath() + "/../data/style/MainManager.qss");
    //    file.open(QIODevice::ReadOnly);
    QString tabBarStyle = "QTabBar::tab {background:transparent;min-width:100px;color: white;border: 2px solid;border-top-left-radius: "
                          "10px;border-top-right-radius: 10px;padding:5px;}";
    //    ui->tabWidget->setStyleSheet(file.readAll());
    ui->tabWidget->setStyleSheet(tabBarStyle);
}

ProductManagementDialog::~ProductManagementDialog() { delete ui; }
