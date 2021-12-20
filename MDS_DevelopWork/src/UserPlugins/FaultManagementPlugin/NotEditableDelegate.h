#ifndef NotEditableDelegate_H
#define NotEditableDelegate_H

#include <QPainter>
#include <QStandardItemModel>
#include <QStyledItemDelegate>

class NotEditableDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    enum CheckMode
    {
        MultiSelect,
        SingleSelect,
    };
    NotEditableDelegate(QObject* parent, NotEditableDelegate::CheckMode tableType = NotEditableDelegate::CheckMode::MultiSelect);
    ~NotEditableDelegate();

protected:
    virtual void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const;
    virtual bool editorEvent(QEvent* event, QAbstractItemModel* model, const QStyleOptionViewItem& option, const QModelIndex& index);
    //    virtual bool eventFilter(QObject *editor, QEvent *event) override;
    QWidget* createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const override;

Q_SIGNALS:
    void checkCurrRowSignal(int row, bool checked);

private:
    QPixmap uncheckedPixmap = QPixmap(":/img/img/DeviceManage/unchecked.svg");
    QPixmap checkedPixmap = QPixmap(":/img/img/DeviceManage/checked.svg");
    NotEditableDelegate::CheckMode tableType;
};

#endif  // NotEditableDelegate_H
