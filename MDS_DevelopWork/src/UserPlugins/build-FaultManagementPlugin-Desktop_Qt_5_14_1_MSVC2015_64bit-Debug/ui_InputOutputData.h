/********************************************************************************
** Form generated from reading UI file 'InputOutputData.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INPUTOUTPUTDATA_H
#define UI_INPUTOUTPUTDATA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InputOutputData
{
public:
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QTableView *tableView;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QTableView *tableView_2;

    void setupUi(QWidget *InputOutputData)
    {
        if (InputOutputData->objectName().isEmpty())
            InputOutputData->setObjectName(QString::fromUtf8("InputOutputData"));
        InputOutputData->resize(911, 369);
        horizontalLayout = new QHBoxLayout(InputOutputData);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        groupBox = new QGroupBox(InputOutputData);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tableView = new QTableView(groupBox);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        gridLayout->addWidget(tableView, 0, 0, 1, 1);


        horizontalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(InputOutputData);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        tableView_2 = new QTableView(groupBox_2);
        tableView_2->setObjectName(QString::fromUtf8("tableView_2"));

        gridLayout_2->addWidget(tableView_2, 0, 0, 1, 1);


        horizontalLayout->addWidget(groupBox_2);


        retranslateUi(InputOutputData);

        QMetaObject::connectSlotsByName(InputOutputData);
    } // setupUi

    void retranslateUi(QWidget *InputOutputData)
    {
        InputOutputData->setWindowTitle(QCoreApplication::translate("InputOutputData", "Form", nullptr));
        groupBox->setTitle(QCoreApplication::translate("InputOutputData", "\350\276\223\345\205\245\346\225\260\346\215\256", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("InputOutputData", "\350\276\223\345\207\272\346\225\260\346\215\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InputOutputData: public Ui_InputOutputData {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INPUTOUTPUTDATA_H
