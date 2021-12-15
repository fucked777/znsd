/********************************************************************************
** Form generated from reading UI file 'SecondMotionControlDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECONDMOTIONCONTROLDIALOG_H
#define UI_SECONDMOTIONCONTROLDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SecondMotionControlDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QTreeWidget *treeWidget;
    QStackedWidget *contentStackWidget;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *okBtn;
    QPushButton *cancelBtn;

    void setupUi(QWidget *SecondMotionControlDialog)
    {
        if (SecondMotionControlDialog->objectName().isEmpty())
            SecondMotionControlDialog->setObjectName(QString::fromUtf8("SecondMotionControlDialog"));
        SecondMotionControlDialog->resize(1344, 756);
        SecondMotionControlDialog->setStyleSheet(QString::fromUtf8("background-color: #232e4a;"));
        verticalLayout = new QVBoxLayout(SecondMotionControlDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(9, 9, 9, 9);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        treeWidget = new QTreeWidget(SecondMotionControlDialog);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(treeWidget->sizePolicy().hasHeightForWidth());
        treeWidget->setSizePolicy(sizePolicy);
        treeWidget->setStyleSheet(QString::fromUtf8("QTreeWidget{\n"
"    background-color: #5B677A;\n"
" \n"
"    /* set the font properties*/\n"
"    font-size:17px;\n"
"    color: white;\n"
"}"));

        horizontalLayout->addWidget(treeWidget);

        contentStackWidget = new QStackedWidget(SecondMotionControlDialog);
        contentStackWidget->setObjectName(QString::fromUtf8("contentStackWidget"));
        sizePolicy.setHeightForWidth(contentStackWidget->sizePolicy().hasHeightForWidth());
        contentStackWidget->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft YaHei UI"));
        contentStackWidget->setFont(font);
        contentStackWidget->setFocusPolicy(Qt::StrongFocus);

        horizontalLayout->addWidget(contentStackWidget);

        horizontalLayout->setStretch(1, 1);

        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        okBtn = new QPushButton(SecondMotionControlDialog);
        okBtn->setObjectName(QString::fromUtf8("okBtn"));

        horizontalLayout_3->addWidget(okBtn);

        cancelBtn = new QPushButton(SecondMotionControlDialog);
        cancelBtn->setObjectName(QString::fromUtf8("cancelBtn"));

        horizontalLayout_3->addWidget(cancelBtn);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(SecondMotionControlDialog);

        QMetaObject::connectSlotsByName(SecondMotionControlDialog);
    } // setupUi

    void retranslateUi(QWidget *SecondMotionControlDialog)
    {
        SecondMotionControlDialog->setWindowTitle(QCoreApplication::translate("SecondMotionControlDialog", "Form", nullptr));
        okBtn->setText(QCoreApplication::translate("SecondMotionControlDialog", "\344\277\235\345\255\230", nullptr));
        cancelBtn->setText(QCoreApplication::translate("SecondMotionControlDialog", "\345\205\263\351\227\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SecondMotionControlDialog: public Ui_SecondMotionControlDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECONDMOTIONCONTROLDIALOG_H
