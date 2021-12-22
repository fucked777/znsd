/********************************************************************************
** Form generated from reading UI file 'FaultLog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FAULTLOG_H
#define UI_FAULTLOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FaultLog
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QTreeView *treeView;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_2;
    QTextEdit *textEdit_2;

    void setupUi(QWidget *FaultLog)
    {
        if (FaultLog->objectName().isEmpty())
            FaultLog->setObjectName(QString::fromUtf8("FaultLog"));
        FaultLog->resize(817, 441);
        verticalLayout_3 = new QVBoxLayout(FaultLog);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        checkBox = new QCheckBox(FaultLog);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        verticalLayout->addWidget(checkBox);

        checkBox_2 = new QCheckBox(FaultLog);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));

        verticalLayout->addWidget(checkBox_2);

        checkBox_3 = new QCheckBox(FaultLog);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));

        verticalLayout->addWidget(checkBox_3);


        horizontalLayout->addLayout(verticalLayout);

        treeView = new QTreeView(FaultLog);
        treeView->setObjectName(QString::fromUtf8("treeView"));

        horizontalLayout->addWidget(treeView);


        verticalLayout_3->addLayout(horizontalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(FaultLog);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout_2);

        textEdit = new QTextEdit(FaultLog);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        verticalLayout_2->addWidget(textEdit);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(FaultLog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_3);

        textEdit_2 = new QTextEdit(FaultLog);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));

        verticalLayout_2->addWidget(textEdit_2);


        verticalLayout_3->addLayout(verticalLayout_2);

        verticalLayout_3->setStretch(0, 2);
        verticalLayout_3->setStretch(1, 1);

        retranslateUi(FaultLog);

        QMetaObject::connectSlotsByName(FaultLog);
    } // setupUi

    void retranslateUi(QWidget *FaultLog)
    {
        FaultLog->setWindowTitle(QCoreApplication::translate("FaultLog", "Form", nullptr));
        checkBox->setText(QCoreApplication::translate("FaultLog", "\344\270\200\347\272\247\346\225\205\351\232\234", nullptr));
        checkBox_2->setText(QCoreApplication::translate("FaultLog", "\344\272\214\347\272\247\346\225\205\351\232\234", nullptr));
        checkBox_3->setText(QCoreApplication::translate("FaultLog", "\344\270\211\347\272\247\346\225\205\351\232\234", nullptr));
        label->setText(QCoreApplication::translate("FaultLog", "\346\225\205\351\232\234\344\277\241\346\201\257\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("FaultLog", "\346\225\205\351\232\234\350\247\243\345\206\263\346\226\271\346\241\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FaultLog: public Ui_FaultLog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FAULTLOG_H
