#ifndef LogPageWidget_H
#define LogPageWidget_H
#include "LogArrayModel.h"
#include <QPushButton>
#include <QWidget>
namespace Ui
{
    class LogPageWidget;
}
class LogArrayModel;
class LogPageWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LogPageWidget(QWidget* parent = nullptr);
    ~LogPageWidget();

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
    LogArrayModel* m_pDataModel;  //数据模型
private:
    Ui::LogPageWidget* ui;
};

#endif  // LogPageWidget_H
