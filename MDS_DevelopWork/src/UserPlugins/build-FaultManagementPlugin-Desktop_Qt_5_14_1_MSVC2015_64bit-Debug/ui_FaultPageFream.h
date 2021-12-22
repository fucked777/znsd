/********************************************************************************
** Form generated from reading UI file 'FaultPageFream.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FAULTPAGEFREAM_H
#define UI_FAULTPAGEFREAM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FaultPageFream
{
public:
    QHBoxLayout *horizontalLayout;
    QTreeWidget *treeWidget;
    QVBoxLayout *verticalLayout;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_9;
    QTabWidget *tabWidget;

    void setupUi(QWidget *FaultPageFream)
    {
        if (FaultPageFream->objectName().isEmpty())
            FaultPageFream->setObjectName(QString::fromUtf8("FaultPageFream"));
        FaultPageFream->resize(871, 583);
        horizontalLayout = new QHBoxLayout(FaultPageFream);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        treeWidget = new QTreeWidget(FaultPageFream);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));

        horizontalLayout->addWidget(treeWidget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget_4 = new QWidget(FaultPageFream);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        horizontalLayout_4 = new QHBoxLayout(widget_4);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_3 = new QLabel(widget_4);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_4->addWidget(label_3);

        label_4 = new QLabel(widget_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        horizontalSpacer_9 = new QSpacerItem(688, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_9);


        verticalLayout->addWidget(widget_4);

        tabWidget = new QTabWidget(FaultPageFream);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));

        verticalLayout->addWidget(tabWidget);


        horizontalLayout->addLayout(verticalLayout);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 5);

        retranslateUi(FaultPageFream);

        QMetaObject::connectSlotsByName(FaultPageFream);
    } // setupUi

    void retranslateUi(QWidget *FaultPageFream)
    {
        FaultPageFream->setWindowTitle(QCoreApplication::translate("FaultPageFream", "Form", nullptr));
        label_3->setText(QCoreApplication::translate("FaultPageFream", "\344\273\273\345\212\241\347\274\226\345\217\267\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("FaultPageFream", "XXXXXXXXASADSD", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FaultPageFream: public Ui_FaultPageFream {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FAULTPAGEFREAM_H
