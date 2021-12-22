#include "FaultManagementDialog.h"
#include "FaultPageFream.h"
#include "ui_FaultManagementDialog.h"
#pragma execution_character_set("utf-8")
FaultManagementDialog::FaultManagementDialog(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::FaultManagementDialog)
{
    ui->setupUi(this);
    QStringList str;
    str << "成像仪图像定位与配准"
        << "探测仪图像定位"
        << "快速成像仪图像定位与配准"
        << "成像仪恒星预报及指令参数生成"
        << "探测仪恒星预报及指令参数生成"
        << "快速成像仪恒星预报及指令参数生成";
    for (int i = 0; i < 6; i++)
    {
        FaultPageFream* m_aultPageFream = new FaultPageFream();
        ui->tabWidget->addTab(m_aultPageFream, str.at(i));
        connect(ui->tabWidget, &QTabWidget::tabBarClicked, m_aultPageFream, &FaultPageFream::showSwitchPage);
    }

    //    ui->tabWidget->addTab(m_logMsgPage, "日志信息");
    //    ui->tabWidget->addTab(m_loadFilePage, "载荷文件输入输出");
    //    QFile file(qApp->applicationDirPath() + "/../data/style/MainManager.qss");
    //    file.open(QIODevice::ReadOnly);
    QString tabBarStyle = "QTabBar::tab {background:transparent;min-width:100px;color: white;border: 2px solid;border-top-left-radius: "
                          "10px;border-top-right-radius: 10px;padding:5px;}";
    //    ui->tabWidget->setStyleSheet(file.readAll());
    ui->tabWidget->setStyleSheet(tabBarStyle);
    //    connect(m_buttonGroup, QOverload<int>::of(&QButtonGroup::buttonClicked), this, &FaultManagementDialog::showSwitchPage);
    initMember();
}

FaultManagementDialog::~FaultManagementDialog() { delete ui; }

void FaultManagementDialog::initMember() {}
