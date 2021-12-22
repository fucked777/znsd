/********************************************************************************
** Form generated from reading UI file 'CallProcessParameter.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALLPROCESSPARAMETER_H
#define UI_CALLPROCESSPARAMETER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CallProcessParameter
{
public:
    QGridLayout *gridLayout;
    QTableView *tableView;

    void setupUi(QWidget *CallProcessParameter)
    {
        if (CallProcessParameter->objectName().isEmpty())
            CallProcessParameter->setObjectName(QString::fromUtf8("CallProcessParameter"));
        CallProcessParameter->resize(400, 300);
        gridLayout = new QGridLayout(CallProcessParameter);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tableView = new QTableView(CallProcessParameter);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        gridLayout->addWidget(tableView, 0, 0, 1, 1);


        retranslateUi(CallProcessParameter);

        QMetaObject::connectSlotsByName(CallProcessParameter);
    } // setupUi

    void retranslateUi(QWidget *CallProcessParameter)
    {
        CallProcessParameter->setWindowTitle(QCoreApplication::translate("CallProcessParameter", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CallProcessParameter: public Ui_CallProcessParameter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALLPROCESSPARAMETER_H
