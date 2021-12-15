/********************************************************************************
** Form generated from reading UI file 'CommonParameterPage.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMMONPARAMETERPAGE_H
#define UI_COMMONPARAMETERPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CommonParameterPage
{
public:
    QVBoxLayout *verticalLayout_2;
    QWidget *tableWidget;
    QGridLayout *gridLayout;
    QFrame *line;
    QWidget *TableWidget;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_2;
    QWidget *detailTableWidget;
    QGridLayout *gridLayout_2;

    void setupUi(QWidget *CommonParameterPage)
    {
        if (CommonParameterPage->objectName().isEmpty())
            CommonParameterPage->setObjectName(QString::fromUtf8("CommonParameterPage"));
        CommonParameterPage->resize(965, 583);
        CommonParameterPage->setStyleSheet(QString::fromUtf8("background-color: #232e4a;"));
        verticalLayout_2 = new QVBoxLayout(CommonParameterPage);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(9, 9, 9, 9);
        tableWidget = new QWidget(CommonParameterPage);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        gridLayout = new QGridLayout(tableWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(9, 9, 9, 9);

        verticalLayout_2->addWidget(tableWidget);

        line = new QFrame(CommonParameterPage);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line);

        TableWidget = new QWidget(CommonParameterPage);
        TableWidget->setObjectName(QString::fromUtf8("TableWidget"));
        TableWidget->setStyleSheet(QString::fromUtf8("QPushButton:open{\n"
"background-color: #00aaff;\n"
"border-style: none;\n"
"}\n"
"\n"
"QLabel{\n"
"border:0px solid white;\n"
"font: normal normal 14px \"\345\256\213\344\275\223\";\n"
"color:white;\n"
"}"));
        verticalLayout = new QVBoxLayout(TableWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(9, 9, 9, 0);
        widget = new QWidget(TableWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(label_2);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(label_3);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(label_4);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(label_5);

        horizontalSpacer_2 = new QSpacerItem(722, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(widget);

        detailTableWidget = new QWidget(TableWidget);
        detailTableWidget->setObjectName(QString::fromUtf8("detailTableWidget"));
        gridLayout_2 = new QGridLayout(detailTableWidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(9, 9, 9, 9);

        verticalLayout->addWidget(detailTableWidget);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 4);

        verticalLayout_2->addWidget(TableWidget);

        verticalLayout_2->setStretch(0, 4);
        verticalLayout_2->setStretch(1, 1);
        verticalLayout_2->setStretch(2, 4);

        retranslateUi(CommonParameterPage);

        QMetaObject::connectSlotsByName(CommonParameterPage);
    } // setupUi

    void retranslateUi(QWidget *CommonParameterPage)
    {
        CommonParameterPage->setWindowTitle(QCoreApplication::translate("CommonParameterPage", "Form", nullptr));
        label_2->setText(QCoreApplication::translate("CommonParameterPage", "\345\275\223\345\211\215\346\226\207\344\273\266\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("CommonParameterPage", "xxx.xml", nullptr));
        label_4->setText(QCoreApplication::translate("CommonParameterPage", "\345\220\257\345\212\250\346\227\266\351\227\264\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("CommonParameterPage", "2021-12-06 18:16:14", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CommonParameterPage: public Ui_CommonParameterPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMMONPARAMETERPAGE_H
