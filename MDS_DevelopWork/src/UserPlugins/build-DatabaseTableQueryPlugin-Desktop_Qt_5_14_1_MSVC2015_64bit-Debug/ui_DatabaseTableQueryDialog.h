/********************************************************************************
** Form generated from reading UI file 'DatabaseTableQueryDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATABASETABLEQUERYDIALOG_H
#define UI_DATABASETABLEQUERYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DatabaseTableQueryDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QTreeWidget *treeWidget;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QWidget *widget;
    QGridLayout *gridLayout;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *okBtn;
    QPushButton *cancelBtn;

    void setupUi(QWidget *DatabaseTableQueryDialog)
    {
        if (DatabaseTableQueryDialog->objectName().isEmpty())
            DatabaseTableQueryDialog->setObjectName(QString::fromUtf8("DatabaseTableQueryDialog"));
        DatabaseTableQueryDialog->resize(1025, 755);
        DatabaseTableQueryDialog->setStyleSheet(QString::fromUtf8("background-color: #232e4a;"));
        verticalLayout_2 = new QVBoxLayout(DatabaseTableQueryDialog);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        treeWidget = new QTreeWidget(DatabaseTableQueryDialog);
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
        treeWidget->setColumnCount(1);

        horizontalLayout_2->addWidget(treeWidget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(DatabaseTableQueryDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy1);
        lineEdit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout_2->addWidget(lineEdit, 0, 0, 1, 1);


        verticalLayout->addWidget(groupBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(DatabaseTableQueryDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);

        widget = new QWidget(DatabaseTableQueryDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tableView = new QTableView(widget);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        gridLayout->addWidget(tableView, 0, 0, 1, 1);


        verticalLayout->addWidget(widget);

        verticalLayout->setStretch(0, 5);
        verticalLayout->setStretch(2, 7);

        horizontalLayout_2->addLayout(verticalLayout);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 5);

        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        okBtn = new QPushButton(DatabaseTableQueryDialog);
        okBtn->setObjectName(QString::fromUtf8("okBtn"));

        horizontalLayout_3->addWidget(okBtn);

        cancelBtn = new QPushButton(DatabaseTableQueryDialog);
        cancelBtn->setObjectName(QString::fromUtf8("cancelBtn"));

        horizontalLayout_3->addWidget(cancelBtn);


        verticalLayout_2->addLayout(horizontalLayout_3);


        retranslateUi(DatabaseTableQueryDialog);

        QMetaObject::connectSlotsByName(DatabaseTableQueryDialog);
    } // setupUi

    void retranslateUi(QWidget *DatabaseTableQueryDialog)
    {
        DatabaseTableQueryDialog->setWindowTitle(QCoreApplication::translate("DatabaseTableQueryDialog", "Form", nullptr));
        groupBox->setTitle(QCoreApplication::translate("DatabaseTableQueryDialog", "sql\350\257\255\345\217\245", nullptr));
        pushButton->setText(QCoreApplication::translate("DatabaseTableQueryDialog", "\346\211\247\350\241\214sql", nullptr));
        okBtn->setText(QCoreApplication::translate("DatabaseTableQueryDialog", "\344\277\235\345\255\230", nullptr));
        cancelBtn->setText(QCoreApplication::translate("DatabaseTableQueryDialog", "\345\205\263\351\227\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DatabaseTableQueryDialog: public Ui_DatabaseTableQueryDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATABASETABLEQUERYDIALOG_H
