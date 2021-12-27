/********************************************************************************
** Form generated from reading UI file 'pageWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGEWIDGET_H
#define UI_PAGEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_pageWidget
{
public:
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QComboBox *comboBox;
    QPushButton *firstPageBtn;
    QPushButton *upperPageBtn;
    QPushButton *nextPageBtn;
    QPushButton *lastPageBtn;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_17;
    QLabel *CurPageLabel;
    QLabel *label_18;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_19;
    QLabel *AllPageLabel;
    QLabel *label_20;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_15;
    QLineEdit *inputLineEdit;
    QLabel *label_16;
    QPushButton *okBtn;

    void setupUi(QWidget *pageWidget)
    {
        if (pageWidget->objectName().isEmpty())
            pageWidget->setObjectName(QString::fromUtf8("pageWidget"));
        pageWidget->resize(1020, 41);
        horizontalLayout_7 = new QHBoxLayout(pageWidget);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalSpacer = new QSpacerItem(92, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer);

        label = new QLabel(pageWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_7->addWidget(label);

        comboBox = new QComboBox(pageWidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout_7->addWidget(comboBox);

        firstPageBtn = new QPushButton(pageWidget);
        firstPageBtn->setObjectName(QString::fromUtf8("firstPageBtn"));

        horizontalLayout_7->addWidget(firstPageBtn);

        upperPageBtn = new QPushButton(pageWidget);
        upperPageBtn->setObjectName(QString::fromUtf8("upperPageBtn"));

        horizontalLayout_7->addWidget(upperPageBtn);

        nextPageBtn = new QPushButton(pageWidget);
        nextPageBtn->setObjectName(QString::fromUtf8("nextPageBtn"));

        horizontalLayout_7->addWidget(nextPageBtn);

        lastPageBtn = new QPushButton(pageWidget);
        lastPageBtn->setObjectName(QString::fromUtf8("lastPageBtn"));

        horizontalLayout_7->addWidget(lastPageBtn);

        label_5 = new QLabel(pageWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_7->addWidget(label_5);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_17 = new QLabel(pageWidget);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        horizontalLayout_5->addWidget(label_17);

        CurPageLabel = new QLabel(pageWidget);
        CurPageLabel->setObjectName(QString::fromUtf8("CurPageLabel"));

        horizontalLayout_5->addWidget(CurPageLabel);

        label_18 = new QLabel(pageWidget);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        horizontalLayout_5->addWidget(label_18);


        horizontalLayout_7->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_19 = new QLabel(pageWidget);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        horizontalLayout_6->addWidget(label_19);

        AllPageLabel = new QLabel(pageWidget);
        AllPageLabel->setObjectName(QString::fromUtf8("AllPageLabel"));

        horizontalLayout_6->addWidget(AllPageLabel);

        label_20 = new QLabel(pageWidget);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        horizontalLayout_6->addWidget(label_20);


        horizontalLayout_7->addLayout(horizontalLayout_6);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_15 = new QLabel(pageWidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        horizontalLayout_10->addWidget(label_15);

        inputLineEdit = new QLineEdit(pageWidget);
        inputLineEdit->setObjectName(QString::fromUtf8("inputLineEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(inputLineEdit->sizePolicy().hasHeightForWidth());
        inputLineEdit->setSizePolicy(sizePolicy);

        horizontalLayout_10->addWidget(inputLineEdit);

        label_16 = new QLabel(pageWidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        horizontalLayout_10->addWidget(label_16);


        horizontalLayout_7->addLayout(horizontalLayout_10);

        okBtn = new QPushButton(pageWidget);
        okBtn->setObjectName(QString::fromUtf8("okBtn"));

        horizontalLayout_7->addWidget(okBtn);


        retranslateUi(pageWidget);

        QMetaObject::connectSlotsByName(pageWidget);
    } // setupUi

    void retranslateUi(QWidget *pageWidget)
    {
        pageWidget->setWindowTitle(QCoreApplication::translate("pageWidget", "Form", nullptr));
        label->setText(QCoreApplication::translate("pageWidget", "\345\215\225\351\241\265\346\230\276\347\244\272\346\235\241\346\225\260", nullptr));
        firstPageBtn->setText(QCoreApplication::translate("pageWidget", "\351\246\226\351\241\265", nullptr));
        upperPageBtn->setText(QCoreApplication::translate("pageWidget", "\344\270\212\351\241\265", nullptr));
        nextPageBtn->setText(QCoreApplication::translate("pageWidget", "\344\270\213\351\241\265", nullptr));
        lastPageBtn->setText(QCoreApplication::translate("pageWidget", "\346\234\253\351\241\265", nullptr));
        label_5->setText(QCoreApplication::translate("pageWidget", "\345\275\223\345\211\215", nullptr));
        label_17->setText(QCoreApplication::translate("pageWidget", "\347\254\254", nullptr));
        CurPageLabel->setText(QCoreApplication::translate("pageWidget", "1", nullptr));
        label_18->setText(QCoreApplication::translate("pageWidget", "\351\241\265", nullptr));
        label_19->setText(QCoreApplication::translate("pageWidget", "\345\205\261", nullptr));
        AllPageLabel->setText(QCoreApplication::translate("pageWidget", "57", nullptr));
        label_20->setText(QCoreApplication::translate("pageWidget", "\351\241\265", nullptr));
        label_15->setText(QCoreApplication::translate("pageWidget", "\350\267\263\350\275\254\350\207\263\347\254\254", nullptr));
        inputLineEdit->setText(QCoreApplication::translate("pageWidget", "55", nullptr));
        label_16->setText(QCoreApplication::translate("pageWidget", "\351\241\265", nullptr));
        okBtn->setText(QCoreApplication::translate("pageWidget", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class pageWidget: public Ui_pageWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGEWIDGET_H
