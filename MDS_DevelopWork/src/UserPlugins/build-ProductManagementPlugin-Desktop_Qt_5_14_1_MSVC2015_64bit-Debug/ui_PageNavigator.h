/********************************************************************************
** Form generated from reading UI file 'PageNavigator.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGENAVIGATOR_H
#define UI_PAGENAVIGATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PageNavigator
{
public:
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QLabel *previousPageLabel;
    QWidget *previousSeparate;
    QWidget *leftPagesWidget;
    QLabel *leftSeparateLabel;
    QWidget *centerPagesWidget;
    QLabel *rightSeparateLabel;
    QWidget *rightPagesWidget;
    QWidget *nextSeparate;
    QLabel *nextPageLabel;
    QLabel *label;
    QLineEdit *pageLineEdit;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *PageNavigator)
    {
        if (PageNavigator->objectName().isEmpty())
            PageNavigator->setObjectName(QString::fromUtf8("PageNavigator"));
        PageNavigator->resize(605, 46);
        PageNavigator->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout = new QHBoxLayout(PageNavigator);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        previousPageLabel = new QLabel(PageNavigator);
        previousPageLabel->setObjectName(QString::fromUtf8("previousPageLabel"));

        horizontalLayout->addWidget(previousPageLabel);

        previousSeparate = new QWidget(PageNavigator);
        previousSeparate->setObjectName(QString::fromUtf8("previousSeparate"));
        previousSeparate->setMinimumSize(QSize(15, 0));
        previousSeparate->setBaseSize(QSize(15, 0));

        horizontalLayout->addWidget(previousSeparate);

        leftPagesWidget = new QWidget(PageNavigator);
        leftPagesWidget->setObjectName(QString::fromUtf8("leftPagesWidget"));

        horizontalLayout->addWidget(leftPagesWidget);

        leftSeparateLabel = new QLabel(PageNavigator);
        leftSeparateLabel->setObjectName(QString::fromUtf8("leftSeparateLabel"));

        horizontalLayout->addWidget(leftSeparateLabel);

        centerPagesWidget = new QWidget(PageNavigator);
        centerPagesWidget->setObjectName(QString::fromUtf8("centerPagesWidget"));

        horizontalLayout->addWidget(centerPagesWidget);

        rightSeparateLabel = new QLabel(PageNavigator);
        rightSeparateLabel->setObjectName(QString::fromUtf8("rightSeparateLabel"));

        horizontalLayout->addWidget(rightSeparateLabel);

        rightPagesWidget = new QWidget(PageNavigator);
        rightPagesWidget->setObjectName(QString::fromUtf8("rightPagesWidget"));

        horizontalLayout->addWidget(rightPagesWidget);

        nextSeparate = new QWidget(PageNavigator);
        nextSeparate->setObjectName(QString::fromUtf8("nextSeparate"));
        nextSeparate->setMinimumSize(QSize(15, 0));
        nextSeparate->setBaseSize(QSize(15, 0));

        horizontalLayout->addWidget(nextSeparate);

        nextPageLabel = new QLabel(PageNavigator);
        nextPageLabel->setObjectName(QString::fromUtf8("nextPageLabel"));

        horizontalLayout->addWidget(nextPageLabel);

        label = new QLabel(PageNavigator);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        pageLineEdit = new QLineEdit(PageNavigator);
        pageLineEdit->setObjectName(QString::fromUtf8("pageLineEdit"));
        pageLineEdit->setMinimumSize(QSize(50, 0));
        pageLineEdit->setMaximumSize(QSize(50, 16777215));
        pageLineEdit->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(pageLineEdit);

        label_2 = new QLabel(PageNavigator);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        horizontalSpacer = new QSpacerItem(45, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        retranslateUi(PageNavigator);

        QMetaObject::connectSlotsByName(PageNavigator);
    } // setupUi

    void retranslateUi(QWidget *PageNavigator)
    {
        PageNavigator->setWindowTitle(QCoreApplication::translate("PageNavigator", "Form", nullptr));
#if QT_CONFIG(tooltip)
        previousPageLabel->setToolTip(QCoreApplication::translate("PageNavigator", "\344\270\212\344\270\200\351\241\265", nullptr));
#endif // QT_CONFIG(tooltip)
        previousPageLabel->setText(QCoreApplication::translate("PageNavigator", "<<", nullptr));
#if QT_CONFIG(tooltip)
        leftSeparateLabel->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        leftSeparateLabel->setText(QCoreApplication::translate("PageNavigator", "..", nullptr));
#if QT_CONFIG(tooltip)
        rightSeparateLabel->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        rightSeparateLabel->setText(QCoreApplication::translate("PageNavigator", "..", nullptr));
#if QT_CONFIG(tooltip)
        nextPageLabel->setToolTip(QCoreApplication::translate("PageNavigator", "\344\270\213\344\270\200\351\241\265", nullptr));
#endif // QT_CONFIG(tooltip)
        nextPageLabel->setText(QCoreApplication::translate("PageNavigator", ">>", nullptr));
        label->setText(QCoreApplication::translate("PageNavigator", "\347\254\254", nullptr));
        pageLineEdit->setText(QString());
        label_2->setText(QCoreApplication::translate("PageNavigator", "\351\241\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PageNavigator: public Ui_PageNavigator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGENAVIGATOR_H
