#ifndef PAGEWIDGET_H
#define PAGEWIDGET_H
#include "CArrayModel.h"
#include <QPushButton>
#include <QWidget>
namespace Ui
{
    class pageWidget;
}

class pageWidget : public QWidget
{
    Q_OBJECT

public:
    explicit pageWidget(QWidget* parent = nullptr);
    ~pageWidget();

    void keyPressEvent(QKeyEvent* event);
    void UpdateStatus();  //刷新状态
signals:
    void updataTableView();
private slots:
    void OnFirstButtonClick();                      //首页按钮按下
    void OnLastButtonClick();                       //末页按钮按下
    void OnPrevButtonClick();                       //前一页按钮按下
    void OnNextButtonClick();                       //后一页按钮按下
    void OnOkBtnPageButtonClick();                  //转到页按钮按下
    void comboxCurtextChange(const QString& text);  //设置每页显示行数
public:
    CArrayModel* m_pDataModel;  //数据模型
private:
    Ui::pageWidget* ui;
};

#endif  // PAGEWIDGET_H
