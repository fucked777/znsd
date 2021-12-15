/********************************************************************************
** Form generated from reading UI file 'CommonParameterDetailTable.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMMONPARAMETERDETAILTABLE_H
#define UI_COMMONPARAMETERDETAILTABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CommonParameterDetailTable
{
public:
    QGridLayout *gridLayout;
    QTableView *TableView;

    void setupUi(QWidget *CommonParameterDetailTable)
    {
        if (CommonParameterDetailTable->objectName().isEmpty())
            CommonParameterDetailTable->setObjectName(QString::fromUtf8("CommonParameterDetailTable"));
        CommonParameterDetailTable->resize(669, 245);
        CommonParameterDetailTable->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(CommonParameterDetailTable);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        TableView = new QTableView(CommonParameterDetailTable);
        TableView->setObjectName(QString::fromUtf8("TableView"));
        TableView->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TableView->sizePolicy().hasHeightForWidth());
        TableView->setSizePolicy(sizePolicy);
        TableView->setStyleSheet(QString::fromUtf8("QTableView {\n"
"background-color: #232e4a;\n"
"border-style:none;\n"
"color:white;\n"
"alternate-background-color:#1b2130;\n"
"font-family:\"\345\256\213\344\275\223\";\n"
"font-size:18px;\n"
"font-style:bold;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"border-style: none;\n"
"background-color: #232e4a;\n"
"height:51px;\n"
"color:white;\n"
"font-family:\"\345\256\213\344\275\223\";\n"
"font-size:18px;\n"
"font-style:bold;\n"
"}\n"
""));
        TableView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        TableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        TableView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        TableView->setAutoScroll(false);
        TableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        TableView->setAlternatingRowColors(false);
        TableView->setSelectionMode(QAbstractItemView::SingleSelection);
        TableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        TableView->setTextElideMode(Qt::ElideNone);
        TableView->setShowGrid(false);
        TableView->setWordWrap(false);
        TableView->setCornerButtonEnabled(false);
        TableView->horizontalHeader()->setCascadingSectionResizes(true);
        TableView->horizontalHeader()->setMinimumSectionSize(5);
        TableView->horizontalHeader()->setDefaultSectionSize(50);
        TableView->verticalHeader()->setVisible(false);

        gridLayout->addWidget(TableView, 0, 0, 1, 1);


        retranslateUi(CommonParameterDetailTable);

        QMetaObject::connectSlotsByName(CommonParameterDetailTable);
    } // setupUi

    void retranslateUi(QWidget *CommonParameterDetailTable)
    {
        CommonParameterDetailTable->setWindowTitle(QCoreApplication::translate("CommonParameterDetailTable", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CommonParameterDetailTable: public Ui_CommonParameterDetailTable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMMONPARAMETERDETAILTABLE_H
