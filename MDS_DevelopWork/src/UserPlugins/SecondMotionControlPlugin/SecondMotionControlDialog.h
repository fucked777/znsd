#ifndef SecondMotionControlDialog_H
#define SecondMotionControlDialog_H

#include <QDialog>
#include <QTreeWidgetItem>
namespace Ui
{
    class SecondMotionControlDialog;
}
struct MotionControlModeInfo
{
    QString m_modeName;
    QString m_frequencyList;
};
class SecondMotionControlDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SecondMotionControlDialog(QWidget* parent = nullptr);
    ~SecondMotionControlDialog();

    enum WidgetMode
    {
        Add = 0,  // 添加
        Edit,     // 编辑
        Look      // 查看
    };

    void initUI();
    void initSlot();

    void setWidgetMode(const WidgetMode& currentUIMode);

    // 设置生成参数界面数据
    void setMotionControlModeInfoList(const QList<MotionControlModeInfo>& ModeInfoList);

protected:
    void closeEvent(QCloseEvent* event);

public slots:

private slots:
    // 左边树结构点击
    void slotMotionControlModeTreeWidgetClicked(QTreeWidgetItem* item, int column);
    // 确定按钮点击
    void slotOkBtnClicked();
    // 左边树结构右键点击
    void slotMotionControlModeTreeWidgetCustomContextMenuRequested(const QPoint& pos);

private:
    Ui::SecondMotionControlDialog* ui;

    QList<MotionControlModeInfo> mModeInfoList;           // 生成界面的配置
    QMap<QTreeWidgetItem*, QTreeWidget*> mTreeWidgetMap;  // 树节点对应旁边的参数设置界面
    QString mTipsMessage;
};

#endif  // SecondMotionControlDialog_H
