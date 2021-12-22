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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FaultManagementDialog
{
public:
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;

    void setupUi(QWidget *FaultManagementDialog)
    {
        if (FaultManagementDialog->objectName().isEmpty())
            FaultManagementDialog->setObjectName(QString::fromUtf8("FaultManagementDialog"));
        FaultManagementDialog->resize(1134, 687);
        FaultManagementDialog->setStyleSheet(QString::fromUtf8("background-color: #232e4a;"));
        gridLayout = new QGridLayout(FaultManagementDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabWidget = new QTabWidget(FaultManagementDialog);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);


        retranslateUi(FaultManagementDialog);

        QMetaObject::connectSlotsByName(FaultManagementDialog);
    } // setupUi

    void retranslateUi(QWidget *FaultManagementDialog)
    {
        FaultManagementDialog->setWindowTitle(QCoreApplication::translate("FaultManagementDialog", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FaultManagementDialog: public Ui_FaultManagementDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FAULTMANAGEMENTDIALOG_H
