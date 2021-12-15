#include "SecondMotionControlDialog.h"
#include "ui_SecondMotionControlDialog.h"
#include <QAction>
#include <QCloseEvent>
#include <QGroupBox>
#include <QMenu>
#include <QMessageBox>

SecondMotionControlDialog::SecondMotionControlDialog(QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::SecondMotionControlDialog)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint);  // 只显示关闭按钮
    //    ui->treeWidget->setHeaderLabels(QStringList() << "系统参数");

    ui->treeWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    initUI();
}

SecondMotionControlDialog::~SecondMotionControlDialog() { delete ui; }

void SecondMotionControlDialog::initUI()
{
    QTreeWidgetItem* topItem1 = new QTreeWidgetItem(ui->treeWidget);
    topItem1->setText(0, "系统参数");
    ui->treeWidget->addTopLevelItem(topItem1);

    QStringList systemValue;
    systemValue << "外部系统相关参数"
                << "FTP相关"
                << "FTP上传文件给MCS相关";
    //隐藏表头
    ui->treeWidget->setHeaderHidden(true);
    //设置展开
    ui->treeWidget->expandAll();

    for (int i = 0; i < 3; i++)
    {
        QTreeWidgetItem* item11 = new QTreeWidgetItem(topItem1);
        item11->setText(0, systemValue.at(i));
    }

    QTreeWidgetItem* topItem2 = new QTreeWidgetItem(ui->treeWidget);
    topItem2->setText(0, "TLQ参数");
    ui->treeWidget->addTopLevelItem(topItem2);
    QStringList TLQValue;
    TLQValue << "TLQ相关参数"
             << "CVSTLQ相关参数";
    //隐藏表头
    ui->treeWidget->setHeaderHidden(true);
    //设置展开
    ui->treeWidget->expandAll();

    for (int i = 0; i < 2; i++)
    {
        QTreeWidgetItem* item01 = new QTreeWidgetItem(topItem2);
        item01->setText(0, TLQValue.at(i));
    }

    // 初始化信号槽连接
    initSlot();
}
void SecondMotionControlDialog::initSlot()
{
    connect(ui->treeWidget, &QTreeWidget::itemClicked, this, &SecondMotionControlDialog::slotMotionControlModeTreeWidgetClicked);
    connect(ui->treeWidget, &QTreeWidget::customContextMenuRequested, this,
            &SecondMotionControlDialog::slotMotionControlModeTreeWidgetCustomContextMenuRequested);

    connect(ui->okBtn, &QPushButton::clicked, this, &SecondMotionControlDialog::slotOkBtnClicked);
    connect(ui->cancelBtn, &QPushButton::clicked, this, &SecondMotionControlDialog::close);
}

void SecondMotionControlDialog::setWidgetMode(const SecondMotionControlDialog::WidgetMode& currentUIMode)
{
    switch (currentUIMode)
    {
    case WidgetMode::Add:
    {
        mTipsMessage = QString("添加");
    }
    break;
    case WidgetMode::Edit:
    {
        mTipsMessage = QString("编辑");
    }
    break;
    }
}

void SecondMotionControlDialog::closeEvent(QCloseEvent* event)
{
    //    if (!QMessageBox::information(this, "提示", "是否关闭当前界面？", QString("确定"),
    //                                  QString("取消")))  //点击确定结果是0,取消是1,所以用1
    //    {
    //        slotOkBtnClicked();  //点击确定就触发一次保存运动控制的按钮后关闭界面  取消的话就直接关闭界面
    //    }
    //    else
    //    {
    event->ignore();
    //    }
}

void SecondMotionControlDialog::slotMotionControlModeTreeWidgetClicked(QTreeWidgetItem* item, int column) {}

void SecondMotionControlDialog::slotOkBtnClicked() {}

void SecondMotionControlDialog::slotMotionControlModeTreeWidgetCustomContextMenuRequested(const QPoint& pos) {}
