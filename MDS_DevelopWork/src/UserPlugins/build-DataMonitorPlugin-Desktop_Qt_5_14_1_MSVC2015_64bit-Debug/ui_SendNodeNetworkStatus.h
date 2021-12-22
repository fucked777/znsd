/********************************************************************************
** Form generated from reading UI file 'SendNodeNetworkStatus.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SENDNODENETWORKSTATUS_H
#define UI_SENDNODENETWORKSTATUS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SendNodeNetworkStatus
{
public:

    void setupUi(QWidget *SendNodeNetworkStatus)
    {
        if (SendNodeNetworkStatus->objectName().isEmpty())
            SendNodeNetworkStatus->setObjectName(QString::fromUtf8("SendNodeNetworkStatus"));
        SendNodeNetworkStatus->resize(400, 300);

        retranslateUi(SendNodeNetworkStatus);

        QMetaObject::connectSlotsByName(SendNodeNetworkStatus);
    } // setupUi

    void retranslateUi(QWidget *SendNodeNetworkStatus)
    {
        SendNodeNetworkStatus->setWindowTitle(QCoreApplication::translate("SendNodeNetworkStatus", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SendNodeNetworkStatus: public Ui_SendNodeNetworkStatus {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SENDNODENETWORKSTATUS_H
