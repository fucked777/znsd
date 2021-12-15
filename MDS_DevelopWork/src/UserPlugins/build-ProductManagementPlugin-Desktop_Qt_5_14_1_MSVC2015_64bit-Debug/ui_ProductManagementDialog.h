/********************************************************************************
** Form generated from reading UI file 'ProductManagementDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRODUCTMANAGEMENTDIALOG_H
#define UI_PRODUCTMANAGEMENTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProductManagementDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *imagerBtn;
    QSpacerItem *horizontalSpacer;
    QPushButton *fastImagerBtn;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *detectorBtn;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *stellarBtn;
    QSpacerItem *horizontalSpacer_3;
    QStackedWidget *stackedWidget;

    void setupUi(QWidget *ProductManagementDialog)
    {
        if (ProductManagementDialog->objectName().isEmpty())
            ProductManagementDialog->setObjectName(QString::fromUtf8("ProductManagementDialog"));
        ProductManagementDialog->resize(1134, 687);
        ProductManagementDialog->setStyleSheet(QString::fromUtf8("background-color: #232e4a;"));
        verticalLayout = new QVBoxLayout(ProductManagementDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        widget = new QWidget(ProductManagementDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        imagerBtn = new QPushButton(widget);
        imagerBtn->setObjectName(QString::fromUtf8("imagerBtn"));

        horizontalLayout->addWidget(imagerBtn);

        horizontalSpacer = new QSpacerItem(73, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        fastImagerBtn = new QPushButton(widget);
        fastImagerBtn->setObjectName(QString::fromUtf8("fastImagerBtn"));

        horizontalLayout->addWidget(fastImagerBtn);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        detectorBtn = new QPushButton(widget);
        detectorBtn->setObjectName(QString::fromUtf8("detectorBtn"));

        horizontalLayout->addWidget(detectorBtn);

        horizontalSpacer_2 = new QSpacerItem(73, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        stellarBtn = new QPushButton(widget);
        stellarBtn->setObjectName(QString::fromUtf8("stellarBtn"));

        horizontalLayout->addWidget(stellarBtn);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        horizontalLayout_2->addWidget(widget);


        verticalLayout->addLayout(horizontalLayout_2);

        stackedWidget = new QStackedWidget(ProductManagementDialog);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));

        verticalLayout->addWidget(stackedWidget);


        retranslateUi(ProductManagementDialog);

        QMetaObject::connectSlotsByName(ProductManagementDialog);
    } // setupUi

    void retranslateUi(QWidget *ProductManagementDialog)
    {
        ProductManagementDialog->setWindowTitle(QCoreApplication::translate("ProductManagementDialog", "Form", nullptr));
        imagerBtn->setText(QCoreApplication::translate("ProductManagementDialog", "\346\210\220\345\203\217\344\273\252\344\272\247\345\223\201", nullptr));
        fastImagerBtn->setText(QCoreApplication::translate("ProductManagementDialog", "\345\277\253\351\200\237\346\210\220\345\203\217\344\273\252\344\272\247\345\223\201", nullptr));
        detectorBtn->setText(QCoreApplication::translate("ProductManagementDialog", "\346\216\242\346\265\213\344\273\252\344\272\247\345\223\201", nullptr));
        stellarBtn->setText(QCoreApplication::translate("ProductManagementDialog", "\346\201\222\346\230\237\351\242\204\346\212\245\344\272\247\345\223\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProductManagementDialog: public Ui_ProductManagementDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRODUCTMANAGEMENTDIALOG_H
