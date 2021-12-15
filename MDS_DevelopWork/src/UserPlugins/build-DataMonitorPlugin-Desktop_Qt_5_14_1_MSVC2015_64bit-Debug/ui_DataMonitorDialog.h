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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DataMonitorDialog
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_3;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_3;
    QStackedWidget *stackedWidget;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_5;
    QWidget *widget_4;
    QGridLayout *gridLayout_2;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_5;

    void setupUi(QWidget *DataMonitorDialog)
    {
        if (DataMonitorDialog->objectName().isEmpty())
            DataMonitorDialog->setObjectName(QString::fromUtf8("DataMonitorDialog"));
        DataMonitorDialog->resize(1084, 750);
        DataMonitorDialog->setStyleSheet(QString::fromUtf8("background-color: #232e4a;\n"
""));
        verticalLayout_3 = new QVBoxLayout(DataMonitorDialog);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        widget = new QWidget(DataMonitorDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setStyleSheet(QString::fromUtf8("QLabel{\n"
"color:white;\n"
"}"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        widget_3 = new QWidget(widget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        gridLayout = new QGridLayout(widget_3);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));

        verticalLayout->addWidget(widget_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_2->addWidget(pushButton);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_2->addWidget(pushButton_2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_2);

        stackedWidget = new QStackedWidget(widget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));

        verticalLayout->addWidget(stackedWidget);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 4);
        verticalLayout->setStretch(2, 1);
        verticalLayout->setStretch(3, 4);

        horizontalLayout_4->addWidget(widget);

        widget_2 = new QWidget(DataMonitorDialog);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setStyleSheet(QString::fromUtf8("QLabel{\n"
"color:white;\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(widget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);


        verticalLayout_2->addLayout(horizontalLayout_3);

        widget_4 = new QWidget(widget_2);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        gridLayout_2 = new QGridLayout(widget_4);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));

        verticalLayout_2->addWidget(widget_4);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 9);

        horizontalLayout_4->addWidget(widget_2);


        verticalLayout_3->addLayout(horizontalLayout_4);

        widget_5 = new QWidget(DataMonitorDialog);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        horizontalLayout_5 = new QHBoxLayout(widget_5);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));

        verticalLayout_3->addWidget(widget_5);

        verticalLayout_3->setStretch(0, 9);
        verticalLayout_3->setStretch(1, 1);

        retranslateUi(DataMonitorDialog);

        QMetaObject::connectSlotsByName(DataMonitorDialog);
    } // setupUi

    void retranslateUi(QWidget *DataMonitorDialog)
    {
        DataMonitorDialog->setWindowTitle(QCoreApplication::translate("DataMonitorDialog", "Form", nullptr));
        label->setText(QCoreApplication::translate("DataMonitorDialog", "\351\200\232\344\277\241\347\212\266\346\200\201\347\233\221\350\247\206", nullptr));
        pushButton->setText(QCoreApplication::translate("DataMonitorDialog", "\345\217\221\351\200\201\350\212\202\347\202\271\347\275\221\347\273\234\350\277\236\346\216\245\347\212\266\346\200\201", nullptr));
        pushButton_2->setText(QCoreApplication::translate("DataMonitorDialog", "\346\216\245\346\224\266\350\212\202\347\202\271\347\275\221\347\273\234\350\277\236\346\216\245\347\212\266\346\200\201", nullptr));
        label_2->setText(QCoreApplication::translate("DataMonitorDialog", "\346\226\207\344\273\266\347\233\221\346\216\247", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DataMonitorDialog: public Ui_DataMonitorDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATAMONITORDIALOG_H
