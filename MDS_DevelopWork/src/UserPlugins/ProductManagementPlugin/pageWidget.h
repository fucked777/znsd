#ifndef PAGEWIDGET_H
#define PAGEWIDGET_H
#include "CArrayModel.h"
#include <QLabel>
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
    //槽函数
private slots:
    void OnFirstButtonClick();                      //首页按钮按下
    void OnLastButtonClick();                       //末页按钮按下
    void OnPrevButtonClick();                       //前一页按钮按下
    void OnNextButtonClick();                       //后一页按钮按下
    void OnOkBtnPageButtonClick();                  //转到页按钮按下
                                                    //    void OnIndexButtonClick();        //转到索引按钮按下
    void comboxCurtextChange(const QString& text);  //设置每页显示行数按钮按下
public:
    CArrayModel* m_pDataModel;  //数据模型
private:
    //    QTableView* tableView;               //数据表
    //    QLineEdit* switchPageLineEdit;  //转到页输入框
    //    QPushButton* m_pFirstPageBtn;        //首页按钮
    //    QPushButton* m_pLastPageBtn;         //末页按钮
    //    QPushButton* prevButton;             //前一页按钮
    //    QPushButton* nextButton;             //下一页按钮
    //    QPushButton* switchPageButton;       //转到页按钮
    //    QLineEdit* m_pIndexEdit;             //索引输入框
    //    QPushButton* m_pGoIndexBtn;          //按索引跳转按钮
    //    QLabel* totalPageLabel;              //总数页文本
    //    QLabel* currentPageLabel;            //当前页文本
    //    QLineEdit* m_pPerPageCountEdit;      //每页显示行数
    //    QPushButton* m_pSetPerPageCountBtn;  //设置每页显示行数按钮
    //    enum
    //    {
    //        PageRecordCount = 10
    //    };  //默认每页显示记录数

private:
    Ui::pageWidget* ui;
};

#endif  // PAGEWIDGET_H
