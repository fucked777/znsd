/********************************************************************************
** Form generated from reading UI file 'ReceiveNodeNetworkStatus.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECEIVENODENETWORKSTATUS_H
#define UI_RECEIVENODENETWORKSTATUS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ReceiveNodeNetworkStatus
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer_2;
    QTableView *tableView;

    void setupUi(QWidget *ReceiveNodeNetworkStatus)
    {
        if (ReceiveNodeNetworkStatus->objectName().isEmpty())
            ReceiveNodeNetworkStatus->setObjectName(QString::fromUtf8("ReceiveNodeNetworkStatus"));
        ReceiveNodeNetworkStatus->resize(597, 428);
        verticalLayout = new QVBoxLayout(ReceiveNodeNetworkStatus);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(ReceiveNodeNetworkStatus);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        comboBox = new QComboBox(ReceiveNodeNetworkStatus);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout->addWidget(comboBox);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        tableView = new QTableView(ReceiveNodeNetworkStatus);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout->addWidget(tableView);


        retranslateUi(ReceiveNodeNetworkStatus);

        QMetaObject::connectSlotsByName(ReceiveNodeNetworkStatus);
    } // setupUi

    void retranslateUi(QWidget *ReceiveNodeNetworkStatus)
    {
        ReceiveNodeNetworkStatus->setWindowTitle(QCoreApplication::translate("ReceiveNodeNetworkStatus", "Form", nullptr));
        label->setText(QCoreApplication::translate("ReceiveNodeNetworkStatus", "\346\216\245\346\224\266\350\212\202\347\202\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ReceiveNodeNetworkStatus: public Ui_ReceiveNodeNetworkStatus {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECEIVENODENETWORKSTATUS_H
