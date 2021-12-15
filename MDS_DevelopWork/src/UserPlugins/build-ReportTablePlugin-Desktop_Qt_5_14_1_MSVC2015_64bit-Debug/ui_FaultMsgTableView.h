/********************************************************************************
** Form generated from reading UI file 'FaultMsgTableView.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FAULTMSGTABLEVIEW_H
#define UI_FAULTMSGTABLEVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LSSMFreqTableView
{
public:
    QGridLayout *gridLayout;
    QTableView *lssmFreqTable;

    void setupUi(QWidget *LSSMFreqTableView)
    {
        if (LSSMFreqTableView->objectName().isEmpty())
            LSSMFreqTableView->setObjectName(QString::fromUtf8("LSSMFreqTableView"));
        LSSMFreqTableView->resize(675, 600);
        LSSMFreqTableView->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(LSSMFreqTableView);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lssmFreqTable = new QTableView(LSSMFreqTableView);
        lssmFreqTable->setObjectName(QString::fromUtf8("lssmFreqTable"));
        lssmFreqTable->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lssmFreqTable->sizePolicy().hasHeightForWidth());
        lssmFreqTable->setSizePolicy(sizePolicy);
        lssmFreqTable->setStyleSheet(QString::fromUtf8("QTableView {\n"
"background-color: #232e4a;\n"
"border-style:none;\n"
"font-size:12pt;\n"
"alternate-background-color:#1b2130;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"border-style: none;\n"
"background-color: #232e4a;\n"
"height:34px;\n"
"font-family:\"\345\256\213\344\275\223\";\n"
"font-size:12pt;\n"
"font-style:bold;\n"
"}"));
        lssmFreqTable->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        lssmFreqTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        lssmFreqTable->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        lssmFreqTable->setAutoScroll(false);
        lssmFreqTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        lssmFreqTable->setAlternatingRowColors(true);
        lssmFreqTable->setSelectionMode(QAbstractItemView::SingleSelection);
        lssmFreqTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        lssmFreqTable->setTextElideMode(Qt::ElideNone);
        lssmFreqTable->setShowGrid(false);
        lssmFreqTable->setWordWrap(false);
        lssmFreqTable->setCornerButtonEnabled(false);
        lssmFreqTable->horizontalHeader()->setCascadingSectionResizes(true);
        lssmFreqTable->horizontalHeader()->setMinimumSectionSize(5);
        lssmFreqTable->horizontalHeader()->setDefaultSectionSize(50);
        lssmFreqTable->verticalHeader()->setVisible(false);

        gridLayout->addWidget(lssmFreqTable, 0, 0, 1, 1);


        retranslateUi(LSSMFreqTableView);

        QMetaObject::connectSlotsByName(LSSMFreqTableView);
    } // setupUi

    void retranslateUi(QWidget *LSSMFreqTableView)
    {
        LSSMFreqTableView->setWindowTitle(QCoreApplication::translate("LSSMFreqTableView", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LSSMFreqTableView: public Ui_LSSMFreqTableView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FAULTMSGTABLEVIEW_H
