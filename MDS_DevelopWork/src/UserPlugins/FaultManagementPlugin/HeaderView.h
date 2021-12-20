#ifndef HEADERVIEW_H
#define HEADERVIEW_H

#include <QHeaderView>
#include <QObject>
#include <QSortFilterProxyModel>
#include <QStandardItemModel>

class HeaderView : public QHeaderView
{
    Q_OBJECT

public:
    HeaderView(Qt::Orientation orientation, QWidget* parent);
    QRect getRect() const;

private:
    QPixmap uncheckedPixmap = QPixmap(":/img/img/DeviceManage/unchecked.svg");
    QPixmap checkedPixmap = QPixmap(":/img/img/DeviceManage/checked.svg");

    QRect rect;

private
    Q_SLOT : void setRect(const QRect& value);

protected:
    void paintSection(QPainter* painter, const QRect& rect, int logicalIndex) const override;
    QStandardItemModel* standard_model;
    QSortFilterProxyModel* proxy_model;
    void mousePressEvent(QMouseEvent* e) override;
    void setModel(QAbstractItemModel* model) override;

signals:
    void selectOrDeselectAll(Qt::CheckState);
    void sendRect(QRect) const;
};

#endif  // HEADERVIEW_H
