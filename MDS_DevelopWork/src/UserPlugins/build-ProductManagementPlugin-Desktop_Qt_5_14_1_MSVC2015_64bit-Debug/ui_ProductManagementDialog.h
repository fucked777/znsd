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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProductManagementDialog
{
public:
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;

    void setupUi(QWidget *ProductManagementDialog)
    {
        if (ProductManagementDialog->objectName().isEmpty())
            ProductManagementDialog->setObjectName(QString::fromUtf8("ProductManagementDialog"));
        ProductManagementDialog->resize(1134, 687);
        ProductManagementDialog->setStyleSheet(QString::fromUtf8("background-color: #232e4a;"));
        gridLayout = new QGridLayout(ProductManagementDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabWidget = new QTabWidget(ProductManagementDialog);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);


        retranslateUi(ProductManagementDialog);

        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(ProductManagementDialog);
    } // setupUi

    void retranslateUi(QWidget *ProductManagementDialog)
    {
        ProductManagementDialog->setWindowTitle(QCoreApplication::translate("ProductManagementDialog", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProductManagementDialog: public Ui_ProductManagementDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRODUCTMANAGEMENTDIALOG_H
