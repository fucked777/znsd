/********************************************************************************
** Form generated from reading UI file 'FaultManagementDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FAULTMANAGEMENTDIALOG_H
#define UI_FAULTMANAGEMENTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FaultManagementDialog
{
public:
    QVBoxLayout *verticalLayout_3;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *imagerBtn;
    QSpacerItem *horizontalSpacer;
    QPushButton *detectorBtn;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *fastImagerBtn;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *imagerStellarBtn;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *detectorStellarBtn;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *fastImagerStellarBtn;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_6;
    QTreeWidget *treeWidget;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_9;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QSpacerItem *horizontalSpacer_10;
    QStackedWidget *DataStackedWidget;

    void setupUi(QWidget *FaultManagementDialog)
    {
        if (FaultManagementDialog->objectName().isEmpty())
            FaultManagementDialog->setObjectName(QString::fromUtf8("FaultManagementDialog"));
        FaultManagementDialog->resize(1134, 687);
        FaultManagementDialog->setStyleSheet(QString::fromUtf8("background-color: #232e4a;"));
        verticalLayout_3 = new QVBoxLayout(FaultManagementDialog);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        widget = new QWidget(FaultManagementDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        imagerBtn = new QPushButton(widget);
        imagerBtn->setObjectName(QString::fromUtf8("imagerBtn"));

        horizontalLayout->addWidget(imagerBtn);

        horizontalSpacer = new QSpacerItem(73, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        detectorBtn = new QPushButton(widget);
        detectorBtn->setObjectName(QString::fromUtf8("detectorBtn"));

        horizontalLayout->addWidget(detectorBtn);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);

        fastImagerBtn = new QPushButton(widget);
        fastImagerBtn->setObjectName(QString::fromUtf8("fastImagerBtn"));

        horizontalLayout->addWidget(fastImagerBtn);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        imagerStellarBtn = new QPushButton(widget);
        imagerStellarBtn->setObjectName(QString::fromUtf8("imagerStellarBtn"));

        horizontalLayout->addWidget(imagerStellarBtn);

        horizontalSpacer_2 = new QSpacerItem(73, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        detectorStellarBtn = new QPushButton(widget);
        detectorStellarBtn->setObjectName(QString::fromUtf8("detectorStellarBtn"));

        horizontalLayout->addWidget(detectorStellarBtn);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        fastImagerStellarBtn = new QPushButton(widget);
        fastImagerStellarBtn->setObjectName(QString::fromUtf8("fastImagerStellarBtn"));

        horizontalLayout->addWidget(fastImagerStellarBtn);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout_3->addWidget(widget);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        treeWidget = new QTreeWidget(FaultManagementDialog);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));

        horizontalLayout_6->addWidget(treeWidget);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        widget_4 = new QWidget(FaultManagementDialog);
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


        verticalLayout_2->addWidget(widget_4);

        widget_5 = new QWidget(FaultManagementDialog);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        horizontalLayout_5 = new QHBoxLayout(widget_5);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        pushButton_5 = new QPushButton(widget_5);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        horizontalLayout_5->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(widget_5);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        horizontalLayout_5->addWidget(pushButton_6);

        pushButton_7 = new QPushButton(widget_5);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));

        horizontalLayout_5->addWidget(pushButton_7);

        pushButton_8 = new QPushButton(widget_5);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));

        horizontalLayout_5->addWidget(pushButton_8);

        horizontalSpacer_10 = new QSpacerItem(510, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_10);


        verticalLayout_2->addWidget(widget_5);

        DataStackedWidget = new QStackedWidget(FaultManagementDialog);
        DataStackedWidget->setObjectName(QString::fromUtf8("DataStackedWidget"));

        verticalLayout_2->addWidget(DataStackedWidget);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 1);
        verticalLayout_2->setStretch(2, 5);

        horizontalLayout_6->addLayout(verticalLayout_2);

        horizontalLayout_6->setStretch(0, 1);
        horizontalLayout_6->setStretch(1, 5);

        verticalLayout_3->addLayout(horizontalLayout_6);


        retranslateUi(FaultManagementDialog);

        QMetaObject::connectSlotsByName(FaultManagementDialog);
    } // setupUi

    void retranslateUi(QWidget *FaultManagementDialog)
    {
        FaultManagementDialog->setWindowTitle(QCoreApplication::translate("FaultManagementDialog", "Form", nullptr));
        imagerBtn->setText(QCoreApplication::translate("FaultManagementDialog", "\346\210\220\345\203\217\344\273\252\345\233\276\345\203\217\345\256\232\344\275\215\344\270\216\351\205\215\345\207\206", nullptr));
        detectorBtn->setText(QCoreApplication::translate("FaultManagementDialog", "\346\216\242\346\265\213\344\273\252\345\233\276\345\203\217\345\256\232\344\275\215", nullptr));
        fastImagerBtn->setText(QCoreApplication::translate("FaultManagementDialog", "\345\277\253\351\200\237\346\210\220\345\203\217\344\273\252\345\233\276\345\203\217\345\256\232\344\275\215\344\270\216\351\205\215\345\207\206", nullptr));
        imagerStellarBtn->setText(QCoreApplication::translate("FaultManagementDialog", "\346\210\220\345\203\217\344\273\252\346\201\222\346\230\237\351\242\204\346\212\245\345\217\212\346\214\207\344\273\244\345\217\202\346\225\260\347\224\237\346\210\220", nullptr));
        detectorStellarBtn->setText(QCoreApplication::translate("FaultManagementDialog", "\346\216\242\346\265\213\344\273\252\346\201\222\346\230\237\351\242\204\346\212\245\345\217\212\346\214\207\344\273\244\345\217\202\346\225\260\347\224\237\346\210\220", nullptr));
        fastImagerStellarBtn->setText(QCoreApplication::translate("FaultManagementDialog", "\345\277\253\351\200\237\346\210\220\345\203\217\344\273\252\346\201\222\346\230\237\351\242\204\346\212\245\345\217\212\346\214\207\344\273\244\345\217\202\346\225\260\347\224\237\346\210\220", nullptr));
        label_3->setText(QCoreApplication::translate("FaultManagementDialog", "\344\273\273\345\212\241\347\274\226\345\217\267\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("FaultManagementDialog", "XXXXXXXXASADSD", nullptr));
        pushButton_5->setText(QCoreApplication::translate("FaultManagementDialog", "\350\276\223\345\205\245\350\276\223\345\207\272\346\225\260\346\215\256", nullptr));
        pushButton_6->setText(QCoreApplication::translate("FaultManagementDialog", "\346\225\205\351\232\234\346\227\245\345\277\227", nullptr));
        pushButton_7->setText(QCoreApplication::translate("FaultManagementDialog", "\347\263\273\347\273\237\346\227\245\345\277\227", nullptr));
        pushButton_8->setText(QCoreApplication::translate("FaultManagementDialog", "\350\260\203\347\224\250\350\277\233\347\250\213\345\217\202\346\225\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FaultManagementDialog: public Ui_FaultManagementDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FAULTMANAGEMENTDIALOG_H
