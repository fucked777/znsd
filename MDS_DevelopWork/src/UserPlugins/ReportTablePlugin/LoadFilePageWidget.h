#ifndef LoadFilePageWidget_H
#define LoadFilePageWidget_H
#include "LoadFileArrayModel.h"
#include <QPushButton>
#include <QWidget>
namespace Ui
{
    class LoadFilePageWidget;
}
class LoadFileArrayModel;
class LoadFilePageWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LoadFilePageWidget(QWidget* parent = nullptr);
    ~LoadFilePageWidget();

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
    LoadFileArrayModel* m_pDataModel;  //数据模型
private:
    Ui::LoadFilePageWidget* ui;
};

#endif  // LoadFilePageWidget_H
