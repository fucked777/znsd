#include "NotEditableDelegate.h"
#include <QCheckBox>
#include <QApplication>
#include <QDebug>
#include <QMouseEvent>
#include <QCommonStyle>
#include <QStandardItemModel>


NotEditableDelegate::NotEditableDelegate(QObject *parent, NotEditableDelegate::CheckMode tableType)
    : QStyledItemDelegate(parent), tableType(tableType)
{

}


NotEditableDelegate::~NotEditableDelegate()
{

}

void NotEditableDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QStyledItemDelegate::paint(painter, option, index);//paint should be before draw*
    if(index.column() == 0) {
        if(index.model()->data(index, Qt::UserRole).toBool())
            QApplication::style()->drawItemPixmap(painter, option.rect, Qt::AlignHCenter | Qt::AlignVCenter, checkedPixmap );
        else
            QApplication::style()->drawItemPixmap(painter, option.rect, Qt::AlignHCenter | Qt::AlignVCenter, uncheckedPixmap );
    }

}



// 响应鼠标事件，更新数据
bool NotEditableDelegate::editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index)
{
    if(index.column() == 0) {
        if ( event->type() == QEvent::MouseButtonPress ) {
            bool data = model->data(index, Qt::UserRole).toBool();
            if(tableType == NotEditableDelegate::CheckMode::SingleSelect)
                for(int i = 0; i < model->rowCount(); i++)
                    model->setData(model->index(i, 0), false, Qt::UserRole); //互斥,单选

            model->setData(index, !data, Qt::UserRole);

            emit checkCurrRowSignal(index.row(), !data);
        }

        return QStyledItemDelegate::editorEvent(event, model, option, index);
    } else
        return false;
}

QWidget *NotEditableDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    return nullptr;
}




