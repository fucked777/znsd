#include "HeaderView.h"

#include <QMouseEvent>
#include <QPainter>
#include <QDebug>

HeaderView::HeaderView(Qt::Orientation orientation, QWidget *parent) : QHeaderView(orientation, parent)
{
    setSectionsClickable(true);
    connect(this, &HeaderView::sendRect, this, &HeaderView::setRect);
}

QRect HeaderView::getRect() const
{
    return rect;
}

void HeaderView::setRect(const QRect &value)
{
    rect = value;
}

void HeaderView::paintSection(QPainter *painter, const QRect &rect, int logicalIndex) const
{
#ifdef false
    painter->save();
    QHeaderView::paintSection(painter, rect, logicalIndex);
    painter->restore();
    if (standard_model && orientation() == Qt::Horizontal) {
        QStandardItem* item = standard_model->horizontalHeaderItem(logicalIndex);
        if (item && item->isCheckable()) {
            int offset = (height() - style()->pixelMetric(QStyle::PM_IndicatorHeight)) / 2;
            int pos = sectionViewportPosition(logicalIndex);
            QStyleOptionButton option;
            option.rect = QRect(offset + pos, offset,
                                style()->pixelMetric(QStyle::PM_IndicatorWidth),
                                style()->pixelMetric(QStyle::PM_IndicatorHeight));
            if (item->checkState() == Qt::Checked) {
                option.state = QStyle::State_On;
            } else {
                option.state = QStyle::State_Off;
            }
            option.state |= QStyle::State_Enabled;

            style()->drawPrimitive(QStyle::PE_IndicatorCheckBox, &option, painter);
        }
    }
#endif

    painter->save();
    QHeaderView::paintSection(painter, rect, logicalIndex);
    painter->restore();

    if(logicalIndex == 0 ) {
        emit sendRect(rect);

        QStandardItem * item = proxy_model ? qobject_cast<QStandardItemModel*>(proxy_model->sourceModel())->horizontalHeaderItem(0) \
                               : standard_model->horizontalHeaderItem(0);
        if (item->checkState() == Qt::Checked) {
            style()->drawItemPixmap(painter, rect, Qt::AlignHCenter | Qt::AlignVCenter, checkedPixmap );
        }
        else {
            style()->drawItemPixmap(painter, rect, Qt::AlignHCenter | Qt::AlignVCenter, uncheckedPixmap );
        }
    }
}

void HeaderView::mousePressEvent(QMouseEvent * event)
{
    QRect rect(this->getRect().center().x() - uncheckedPixmap.width() / 2 - 5, this->getRect().center().y() - uncheckedPixmap.height() / 2 - 5,
               uncheckedPixmap.width() + 5,
               uncheckedPixmap.height() + 5);

    if (rect.contains(event->pos())) {
        QStandardItem * item = proxy_model ? qobject_cast<QStandardItemModel*>(proxy_model->sourceModel())->horizontalHeaderItem(0)\
                               : standard_model->horizontalHeaderItem(0);
        item->setCheckState(item->checkState() == Qt::Checked ? Qt::Unchecked : Qt::Checked);
        emit selectOrDeselectAll(item->checkState());
    }
    else
        QHeaderView::mousePressEvent(event);
}

void HeaderView::setModel(QAbstractItemModel * model)
{
    QHeaderView::setModel(model);
    standard_model = qobject_cast<QStandardItemModel*>(model);
    proxy_model = qobject_cast<QSortFilterProxyModel*>(model);
}

//usage

//QTableView  view;
//QStandardItemModel model;
//model.setColumnCount(5);
//QStandardItem* item0 = new QStandardItem("some text");
//item0->setCheckable(true);
//item0->setCheckState(Qt::Checked);
//item0->setText("some text");
//model.setHorizontalHeaderItem(0, item0);
//view.setModel(&model);
//MyHeader *myHeader = new MyHeader(Qt::Horizontal, &view);
//view.setHorizontalHeader(myHeader);
//view.show();
