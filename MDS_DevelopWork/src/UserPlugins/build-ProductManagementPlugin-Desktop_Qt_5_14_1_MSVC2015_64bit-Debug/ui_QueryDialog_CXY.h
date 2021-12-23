/********************************************************************************
** Form generated from reading UI file 'QueryDialog_CXY.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUERYDIALOG_CXY_H
#define UI_QUERYDIALOG_CXY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QueryDialog_CXY
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_2;
    QDateTimeEdit *startDateTimeEdit;
    QLabel *label_6;
    QDateTimeEdit *endDateTimeEdit;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QLineEdit *taskNumLineEdit;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *fileNameLineEdit;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QLineEdit *outputTypeLineEdit;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QWidget *QueryDialog_CXY)
    {
        if (QueryDialog_CXY->objectName().isEmpty())
            QueryDialog_CXY->setObjectName(QString::fromUtf8("QueryDialog_CXY"));
        QueryDialog_CXY->resize(658, 452);
        verticalLayout = new QVBoxLayout(QueryDialog_CXY);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label = new QLabel(QueryDialog_CXY);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_6->addWidget(label);

        comboBox = new QComboBox(QueryDialog_CXY);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout_6->addWidget(comboBox);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_7);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_2 = new QLabel(QueryDialog_CXY);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_5->addWidget(label_2);

        startDateTimeEdit = new QDateTimeEdit(QueryDialog_CXY);
        startDateTimeEdit->setObjectName(QString::fromUtf8("startDateTimeEdit"));

        horizontalLayout_5->addWidget(startDateTimeEdit);

        label_6 = new QLabel(QueryDialog_CXY);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_5->addWidget(label_6);

        endDateTimeEdit = new QDateTimeEdit(QueryDialog_CXY);
        endDateTimeEdit->setObjectName(QString::fromUtf8("endDateTimeEdit"));

        horizontalLayout_5->addWidget(endDateTimeEdit);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_8);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_3 = new QLabel(QueryDialog_CXY);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_4->addWidget(label_3);

        taskNumLineEdit = new QLineEdit(QueryDialog_CXY);
        taskNumLineEdit->setObjectName(QString::fromUtf8("taskNumLineEdit"));

        horizontalLayout_4->addWidget(taskNumLineEdit);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(QueryDialog_CXY);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        fileNameLineEdit = new QLineEdit(QueryDialog_CXY);
        fileNameLineEdit->setObjectName(QString::fromUtf8("fileNameLineEdit"));

        horizontalLayout_3->addWidget(fileNameLineEdit);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_5 = new QLabel(QueryDialog_CXY);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_2->addWidget(label_5);

        outputTypeLineEdit = new QLineEdit(QueryDialog_CXY);
        outputTypeLineEdit->setObjectName(QString::fromUtf8("outputTypeLineEdit"));

        horizontalLayout_2->addWidget(outputTypeLineEdit);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(QueryDialog_CXY);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pushButton_2 = new QPushButton(QueryDialog_CXY);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(QueryDialog_CXY);

        QMetaObject::connectSlotsByName(QueryDialog_CXY);
    } // setupUi

    void retranslateUi(QWidget *QueryDialog_CXY)
    {
        QueryDialog_CXY->setWindowTitle(QCoreApplication::translate("QueryDialog_CXY", "Form", nullptr));
        label->setText(QCoreApplication::translate("QueryDialog_CXY", "\344\273\273\345\212\241\345\220\215\347\247\260\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("QueryDialog_CXY", "\346\227\266\346\256\265\357\274\232", nullptr));
        label_6->setText(QCoreApplication::translate("QueryDialog_CXY", "\350\207\263", nullptr));
        label_3->setText(QCoreApplication::translate("QueryDialog_CXY", "\344\273\273\345\212\241\347\274\226\345\217\267\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("QueryDialog_CXY", "\346\226\207\344\273\266\345\220\215\347\247\260\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("QueryDialog_CXY", "\350\276\223\345\207\272\347\261\273\345\236\213\357\274\232", nullptr));
        pushButton->setText(QCoreApplication::translate("QueryDialog_CXY", "\346\237\245\350\257\242", nullptr));
        pushButton_2->setText(QCoreApplication::translate("QueryDialog_CXY", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QueryDialog_CXY: public Ui_QueryDialog_CXY {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUERYDIALOG_CXY_H
