#include "DatabaseTableQueryDialog.h"
#include "ui_DatabaseTableQueryDialog.h"
#include <QCloseEvent>
#include <QDebug>
#include <QMessageBox>

DatabaseTableQueryDialog::DatabaseTableQueryDialog(QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::DatabaseTableQueryDialog)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint);  // 只显示关闭按钮
    ui->treeWidget->setHeaderLabels(QStringList() << "数据库表查询");

    ui->treeWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    initUI();
}

DatabaseTableQueryDialog::~DatabaseTableQueryDialog() { delete ui; }

void DatabaseTableQueryDialog::initUI()
{
    str << "STUDENT"
        << "TEACHER"
        << "CLASS"
        << "TABLE"
        << "SAHDSAD";

    QTreeWidgetItem* topItem1 = new QTreeWidgetItem(ui->treeWidget);
    topItem1->setText(0, "表名");
    ui->treeWidget->addTopLevelItem(topItem1);

    //隐藏表头
    ui->treeWidget->setHeaderHidden(true);
    //设置展开
    ui->treeWidget->expandAll();
    for (int i = 0; i < str.size(); i++)
    {
        QTreeWidgetItem* item11 = new QTreeWidgetItem(topItem1);
        item11->setText(0, str.at(i));
    }
    // 初始化信号槽连接
    initSlot();
}
void DatabaseTableQueryDialog::initSlot()
{
    connect(ui->treeWidget, &QTreeWidget::itemClicked, this, &DatabaseTableQueryDialog::slotMotionControlModeTreeWidgetClicked);
    connect(ui->okBtn, &QPushButton::clicked, this, &DatabaseTableQueryDialog::slotOkBtnClicked);
    connect(ui->cancelBtn, &QPushButton::clicked, this, &DatabaseTableQueryDialog::close);
}

void DatabaseTableQueryDialog::setWidgetMode(const DatabaseTableQueryDialog::WidgetMode& currentUIMode)
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

void DatabaseTableQueryDialog::closeEvent(QCloseEvent* event)
{
    if (!QMessageBox::information(this, "提示", "是否关闭当前界面", QString("确定"), QString("取消")))
    {
        slotOkBtnClicked();
    }
    else
    {
        event->ignore();
    }
}

void DatabaseTableQueryDialog::slotMotionControlModeTreeWidgetClicked(QTreeWidgetItem* item, int column)
{
    //    QString tableName = item->data(column, Qt::DisplayRole).toString();
    //    if (tableName == "表名")
    //        return;
    ui->sqlTextEdit->setText("selset * from   " + item->text(column));
}

void DatabaseTableQueryDialog::slotOkBtnClicked()
{
    qDebug() << "data send";
    qDebug() << "data send";
}

void DatabaseTableQueryDialog::on_doSqlBtn_clicked()
{
    //获取sql语句，发送出去。进行查找
    QString sql = ui->sqlTextEdit->toPlainText();
    emit sqlSelsctSignal(sql);
}
