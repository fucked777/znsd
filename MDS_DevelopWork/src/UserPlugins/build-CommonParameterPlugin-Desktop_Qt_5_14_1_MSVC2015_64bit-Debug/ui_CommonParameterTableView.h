/********************************************************************************
** Form generated from reading UI file 'CommonParameterTableView.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMMONPARAMETERTABLEVIEW_H
#define UI_COMMONPARAMETERTABLEVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CommonParameterTableView
{
public:
    QGridLayout *gridLayout;
    QTableView *TableView;

    void setupUi(QWidget *CommonParameterTableView)
    {
        if (CommonParameterTableView->objectName().isEmpty())
            CommonParameterTableView->setObjectName(QString::fromUtf8("CommonParameterTableView"));
        CommonParameterTableView->resize(669, 245);
        CommonParameterTableView->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(CommonParameterTableView);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        TableView = new QTableView(CommonParameterTableView);
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


        retranslateUi(CommonParameterTableView);

        QMetaObject::connectSlotsByName(CommonParameterTableView);
    } // setupUi

    void retranslateUi(QWidget *CommonParameterTableView)
    {
        CommonParameterTableView->setWindowTitle(QCoreApplication::translate("CommonParameterTableView", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CommonParameterTableView: public Ui_CommonParameterTableView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMMONPARAMETERTABLEVIEW_H
