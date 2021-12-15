/********************************************************************************
** Form generated from reading UI file 'ReportTablePage.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPORTTABLEPAGE_H
#define UI_REPORTTABLEPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ReportTablePage
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *faultMsgBtn;
    QSpacerItem *horizontalSpacer;
    QPushButton *logMsgBtn;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *fileBtn;
    QSpacerItem *horizontalSpacer_3;
    QStackedWidget *stackedWidget;

    void setupUi(QWidget *ReportTablePage)
    {
        if (ReportTablePage->objectName().isEmpty())
            ReportTablePage->setObjectName(QString::fromUtf8("ReportTablePage"));
        ReportTablePage->resize(1134, 687);
        ReportTablePage->setStyleSheet(QString::fromUtf8("background-color: #232e4a;"));
        verticalLayout = new QVBoxLayout(ReportTablePage);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        widget = new QWidget(ReportTablePage);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        faultMsgBtn = new QPushButton(widget);
        faultMsgBtn->setObjectName(QString::fromUtf8("faultMsgBtn"));

        horizontalLayout->addWidget(faultMsgBtn);

        horizontalSpacer = new QSpacerItem(73, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        logMsgBtn = new QPushButton(widget);
        logMsgBtn->setObjectName(QString::fromUtf8("logMsgBtn"));

        horizontalLayout->addWidget(logMsgBtn);

        horizontalSpacer_2 = new QSpacerItem(73, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        fileBtn = new QPushButton(widget);
        fileBtn->setObjectName(QString::fromUtf8("fileBtn"));

        horizontalLayout->addWidget(fileBtn);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        horizontalLayout_2->addWidget(widget);


        verticalLayout->addLayout(horizontalLayout_2);

        stackedWidget = new QStackedWidget(ReportTablePage);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));

        verticalLayout->addWidget(stackedWidget);


        retranslateUi(ReportTablePage);

        QMetaObject::connectSlotsByName(ReportTablePage);
    } // setupUi

    void retranslateUi(QWidget *ReportTablePage)
    {
        ReportTablePage->setWindowTitle(QCoreApplication::translate("ReportTablePage", "Form", nullptr));
        faultMsgBtn->setText(QCoreApplication::translate("ReportTablePage", "\346\225\205\351\232\234\344\277\241\346\201\257", nullptr));
        logMsgBtn->setText(QCoreApplication::translate("ReportTablePage", "\346\227\245\345\277\227\344\277\241\346\201\257", nullptr));
        fileBtn->setText(QCoreApplication::translate("ReportTablePage", "\350\275\275\350\215\267\346\226\207\344\273\266\350\276\223\345\205\245\350\276\223\345\207\272\347\273\237\350\256\241", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ReportTablePage: public Ui_ReportTablePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPORTTABLEPAGE_H
