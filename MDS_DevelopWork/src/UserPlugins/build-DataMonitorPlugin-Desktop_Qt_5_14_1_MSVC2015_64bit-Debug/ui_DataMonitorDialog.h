/********************************************************************************
** Form generated from reading UI file 'DataMonitorDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATAMONITORDIALOG_H
#define UI_DATAMONITORDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DataMonitorDialog
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_4;
    QWidget *widget_2;
    QGridLayout *gridLayout_2;
    QTabWidget *tabWidget;
    QWidget *widget_3;

    void setupUi(QWidget *DataMonitorDialog)
    {
        if (DataMonitorDialog->objectName().isEmpty())
            DataMonitorDialog->setObjectName(QString::fromUtf8("DataMonitorDialog"));
        DataMonitorDialog->resize(1084, 750);
        DataMonitorDialog->setStyleSheet(QString::fromUtf8("background-color: #232e4a;\n"
""));
        verticalLayout_3 = new QVBoxLayout(DataMonitorDialog);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(DataMonitorDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("QLabel{\n"
"color:white;\n"
"}"));

        horizontalLayout->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        widget = new QWidget(DataMonitorDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));

        verticalLayout->addWidget(widget);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 5);

        horizontalLayout_3->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        label_2 = new QLabel(DataMonitorDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("QLabel{\n"
"color:white;\n"
"}"));

        horizontalLayout_2->addWidget(label_2);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout_2->addLayout(horizontalLayout_2);

        widget_2 = new QWidget(DataMonitorDialog);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        gridLayout_2 = new QGridLayout(widget_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));

        verticalLayout_2->addWidget(widget_2);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 5);

        horizontalLayout_3->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout_3);

        tabWidget = new QTabWidget(DataMonitorDialog);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));

        verticalLayout_3->addWidget(tabWidget);

        widget_3 = new QWidget(DataMonitorDialog);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));

        verticalLayout_3->addWidget(widget_3);

        verticalLayout_3->setStretch(0, 1);
        verticalLayout_3->setStretch(1, 1);
        verticalLayout_3->setStretch(2, 1);

        retranslateUi(DataMonitorDialog);

        QMetaObject::connectSlotsByName(DataMonitorDialog);
    } // setupUi

    void retranslateUi(QWidget *DataMonitorDialog)
    {
        DataMonitorDialog->setWindowTitle(QCoreApplication::translate("DataMonitorDialog", "Form", nullptr));
        label->setText(QCoreApplication::translate("DataMonitorDialog", "\351\200\232\344\277\241\347\212\266\346\200\201\347\233\221\350\247\206", nullptr));
        label_2->setText(QCoreApplication::translate("DataMonitorDialog", "\346\226\207\344\273\266\347\233\221\350\247\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DataMonitorDialog: public Ui_DataMonitorDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATAMONITORDIALOG_H
