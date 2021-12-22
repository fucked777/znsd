/********************************************************************************
** Form generated from reading UI file 'SystemLog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYSTEMLOG_H
#define UI_SYSTEMLOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SystemLog
{
public:
    QGridLayout *gridLayout;
    QTableView *tableView;

    void setupUi(QWidget *SystemLog)
    {
        if (SystemLog->objectName().isEmpty())
            SystemLog->setObjectName(QString::fromUtf8("SystemLog"));
        SystemLog->resize(400, 300);
        gridLayout = new QGridLayout(SystemLog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tableView = new QTableView(SystemLog);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        gridLayout->addWidget(tableView, 0, 0, 1, 1);


        retranslateUi(SystemLog);

        QMetaObject::connectSlotsByName(SystemLog);
    } // setupUi

    void retranslateUi(QWidget *SystemLog)
    {
        SystemLog->setWindowTitle(QCoreApplication::translate("SystemLog", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SystemLog: public Ui_SystemLog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSTEMLOG_H
