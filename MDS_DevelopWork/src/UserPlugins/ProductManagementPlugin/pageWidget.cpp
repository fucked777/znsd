#include "pageWidget.h"
#include "ui_pageWidget.h"
#include <QKeyEvent>
#include <QMessageBox>
pageWidget::pageWidget(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::pageWidget)
{
    ui->setupUi(this);
    m_pDataModel = new CArrayModel(this);
    initMember();
    ui->comboBox->addItem("20", 20);
    ui->comboBox->addItem("25", 25);
    ui->comboBox->addItem("30", 30);
    ui->comboBox->addItem("50", 50);
    //翻页按钮
    connect(ui->firstPageBtn, SIGNAL(clicked()), this, SLOT(OnFirstButtonClick()));
    connect(ui->lastPageBtn, SIGNAL(clicked()), this, SLOT(OnLastButtonClick()));
    connect(ui->upperPageBtn, SIGNAL(clicked()), this, SLOT(OnPrevButtonClick()));
    connect(ui->nextPageBtn, SIGNAL(clicked()), this, SLOT(OnNextButtonClick()));
    //跳转按钮和跳转到页回车相应
    connect(ui->okBtn, SIGNAL(clicked()), this, SLOT(OnOkBtnPageButtonClick()));
    //    connect(switchPageLineEdit, SIGNAL(returnPressed()), this, SLOT(OnSwitchPageButtonClick()));
    //设置每页显示行数按钮
    connect(ui->comboBox, &QComboBox::currentTextChanged, this, &pageWidget::comboxCurtextChange);
}

pageWidget::~pageWidget() { delete ui; }

void pageWidget::keyPressEvent(QKeyEvent* event)
{
    switch (event->key())
    {
        //进行界面退出，重写Esc键，否则重写reject()方法
    case Qt::Key_Escape: this->close(); break;
    default: QWidget::keyPressEvent(event);
    }
}
//首页按钮按下
void pageWidget::OnFirstButtonClick()
{
    m_pDataModel->SetCurPage(0);
    UpdateStatus();
}
//末页按钮按下
void pageWidget::OnLastButtonClick()
{
    m_pDataModel->SetCurPage(m_pDataModel->GetPageCount() - 1);
    UpdateStatus();
}
//前一页按钮按下
void pageWidget::OnPrevButtonClick()
{
    m_pDataModel->SetCurPage(m_pDataModel->GetCurPage() - 1);
    UpdateStatus();
}
//后一页按钮按下
void pageWidget::OnNextButtonClick()
{
    m_pDataModel->SetCurPage(m_pDataModel->GetCurPage() + 1);
    UpdateStatus();
}

void pageWidget::OnOkBtnPageButtonClick()
{
    //得到输入字符串
    QString szText = ui->inputLineEdit->text();
    //数字正则表达式
    QRegExp regExp("-?[0-9]*");
    //判断是否为数字
    if (!regExp.exactMatch(szText))
    {
        QMessageBox::information(this, QString("提示"), QString("请输入数字"));

        return;
    }
    //是否为空
    if (szText.isEmpty())
    {
        QMessageBox::information(this, QString("提示"), QString("请输入跳转页面"));

        return;
    }
    //得到页数
    int pageIndex = szText.toInt();
    //判断是否有指定页
    if (pageIndex > m_pDataModel->GetPageCount() || pageIndex < 1)
    {
        QMessageBox::information(this, QString("提示"), QString("页面超出范围，请重新输入"));

        return;
    }
    //记录查询
    m_pDataModel->SetCurPage(pageIndex - 1);
    //刷新状态
    UpdateStatus();

    return;
}

void pageWidget::comboxCurtextChange(const QString& text)
{
    //得到输入字符串
    QString szText = text;
    //数字正则表达式
    QRegExp regExp("-?[0-9]*");
    //判断是否为数字
    if (!regExp.exactMatch(szText))
    {
        QMessageBox::information(this, QString("提示"), QString("请输入数字"));

        return;
    }
    //是否为空
    if (szText.isEmpty())
    {
        QMessageBox::information(this, QString("提示"), QString("请输入设置的行数"));

        return;
    }
    //得到行数
    int Index = szText.toInt();
    //判断范围是否合理
    if (Index > m_pDataModel->RowCount() || Index <= 0)
    {
        QMessageBox::information(this, QString("提示"), QString("设置值超出范围，请重新输入"));

        return;
    }

    //设置每页容量
    m_pDataModel->SetPageSize(Index);

    //刷新状态
    UpdateStatus();

    return;
}

void pageWidget::UpdateStatus()
{
    //刷新表格

    emit updataTableView();
    //总页数
    QString szPageCountText = QString::number(m_pDataModel->GetPageCount());
    ui->AllPageLabel->setText(szPageCountText);

    //设置当前页文本
    int iCurPage = m_pDataModel->GetCurPage() + 1;
    QString szCurrentText = QString::number(iCurPage);
    ui->CurPageLabel->setText(szCurrentText);

    //每页显示行数
    //    QString strPerPageCount = QString(QString("%1")).arg(QString::number(m_pDataModel->GetPageSize()));
    //    ui->comboBox->(strPerPageCount);

    //当前第一页，且总共只有一页
    if (1 == iCurPage && 1 == m_pDataModel->GetPageCount())
    {
        ui->firstPageBtn->setEnabled(false);
        ui->lastPageBtn->setEnabled(false);
        ui->upperPageBtn->setEnabled(false);
        ui->nextPageBtn->setEnabled(false);
    }
    //当前第一页，且总页数大于1页
    else if (1 == iCurPage && m_pDataModel->GetPageCount() > 1)
    {
        ui->firstPageBtn->setEnabled(false);
        ui->lastPageBtn->setEnabled(true);
        ui->upperPageBtn->setEnabled(false);
        ui->nextPageBtn->setEnabled(true);
    }
    //当前是最后一页
    else if (iCurPage == m_pDataModel->GetPageCount())
    {
        ui->firstPageBtn->setEnabled(true);
        ui->lastPageBtn->setEnabled(false);
        ui->upperPageBtn->setEnabled(true);
        ui->nextPageBtn->setEnabled(false);
    }
    //中间页
    else
    {
        ui->firstPageBtn->setEnabled(true);
        ui->lastPageBtn->setEnabled(true);
        ui->upperPageBtn->setEnabled(true);
        ui->nextPageBtn->setEnabled(true);
    }

    return;
}
//测试功能
void pageWidget::initMember()
{
    ImagerData data;
    ImagerDataList DATA;
    for (int i = 1; i < 101; i++)
    {
        data.taskNum = QString::number(i);
        data.outputTime = "00:13:14";
        data.fileName = "css";
        data.LocalFilePath = "c:xiaoxiao";
        data.outputFilePath = "c:xiaoxiao";
        data.sendDirection = "NRS->CVS";
        data.sendType = "FTP";
        data.accuracy = "XXXXX";
        data.outputType = "NRST100001";
        data.fileSize = QString::number(i) + "MB";
        DATA.append(data);
    }
    m_pDataModel->SetArrayData(DATA);
    m_pDataModel->SetPageSize(20);
    UpdateStatus();
}
