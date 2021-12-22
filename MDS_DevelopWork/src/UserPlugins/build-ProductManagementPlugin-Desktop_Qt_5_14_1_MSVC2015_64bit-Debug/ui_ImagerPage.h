/********************************************************************************
** Form generated from reading UI file 'ImagerPage.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGERPAGE_H
#define UI_IMAGERPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImagerPage
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *contextWidgets;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *allBtn;
    QPushButton *queryBtn;
    QPushButton *reportBtn;
    QSpacerItem *horizontalSpacer_2;
    QWidget *tableWidget;
    QGridLayout *gridLayout;
    QTableView *tableView;
    QWidget *buttomWidget;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QComboBox *comboBox;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *okBtn;

    void setupUi(QDialog *ImagerPage)
    {
        if (ImagerPage->objectName().isEmpty())
            ImagerPage->setObjectName(QString::fromUtf8("ImagerPage"));
        ImagerPage->resize(1120, 699);
        ImagerPage->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(ImagerPage);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        contextWidgets = new QWidget(ImagerPage);
        contextWidgets->setObjectName(QString::fromUtf8("contextWidgets"));
        contextWidgets->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: #00aaff;\n"
"border:2px solid white;\n"
"font: normal normal 16px \"\345\256\213\344\275\223\"\n"
"}\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
""));
        horizontalLayout_2 = new QHBoxLayout(contextWidgets);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        allBtn = new QPushButton(contextWidgets);
        allBtn->setObjectName(QString::fromUtf8("allBtn"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(allBtn->sizePolicy().hasHeightForWidth());
        allBtn->setSizePolicy(sizePolicy);
        allBtn->setMinimumSize(QSize(80, 0));
        allBtn->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        allBtn->setFont(font);
        allBtn->setStyleSheet(QString::fromUtf8(""));
        allBtn->setCheckable(true);
        allBtn->setChecked(true);
        allBtn->setAutoExclusive(true);
        allBtn->setFlat(false);

        horizontalLayout_2->addWidget(allBtn);

        queryBtn = new QPushButton(contextWidgets);
        queryBtn->setObjectName(QString::fromUtf8("queryBtn"));
        sizePolicy.setHeightForWidth(queryBtn->sizePolicy().hasHeightForWidth());
        queryBtn->setSizePolicy(sizePolicy);
        queryBtn->setMinimumSize(QSize(80, 0));
        queryBtn->setMaximumSize(QSize(16777215, 16777215));
        queryBtn->setFont(font);
        queryBtn->setStyleSheet(QString::fromUtf8(""));
        queryBtn->setCheckable(true);
        queryBtn->setChecked(false);
        queryBtn->setAutoExclusive(true);

        horizontalLayout_2->addWidget(queryBtn);

        reportBtn = new QPushButton(contextWidgets);
        reportBtn->setObjectName(QString::fromUtf8("reportBtn"));
        sizePolicy.setHeightForWidth(reportBtn->sizePolicy().hasHeightForWidth());
        reportBtn->setSizePolicy(sizePolicy);
        reportBtn->setMinimumSize(QSize(80, 0));
        reportBtn->setMaximumSize(QSize(16777215, 16777215));
        reportBtn->setFont(font);
        reportBtn->setStyleSheet(QString::fromUtf8(""));
        reportBtn->setCheckable(true);
        reportBtn->setChecked(true);
        reportBtn->setAutoExclusive(true);
        reportBtn->setFlat(false);

        horizontalLayout_2->addWidget(reportBtn);

        horizontalSpacer_2 = new QSpacerItem(651, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(contextWidgets);

        tableWidget = new QWidget(ImagerPage);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        sizePolicy.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(tableWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tableView = new QTableView(tableWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setStyleSheet(QString::fromUtf8("QTableView {\n"
"border-style:none;\n"
"color:white;\n"
"font: bold 12pt;\n"
"}\n"
""));

        gridLayout->addWidget(tableView, 0, 0, 1, 1);


        verticalLayout->addWidget(tableWidget);

        buttomWidget = new QWidget(ImagerPage);
        buttomWidget->setObjectName(QString::fromUtf8("buttomWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(buttomWidget->sizePolicy().hasHeightForWidth());
        buttomWidget->setSizePolicy(sizePolicy1);
        horizontalLayout_3 = new QHBoxLayout(buttomWidget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(234, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        label = new QLabel(buttomWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_3->addWidget(label);

        comboBox = new QComboBox(buttomWidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout_3->addWidget(comboBox);

        widget = new QWidget(buttomWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));

        horizontalLayout_3->addWidget(widget);

        okBtn = new QPushButton(buttomWidget);
        okBtn->setObjectName(QString::fromUtf8("okBtn"));

        horizontalLayout_3->addWidget(okBtn);


        verticalLayout->addWidget(buttomWidget);


        retranslateUi(ImagerPage);

        QMetaObject::connectSlotsByName(ImagerPage);
    } // setupUi

    void retranslateUi(QDialog *ImagerPage)
    {
        ImagerPage->setWindowTitle(QCoreApplication::translate("ImagerPage", "Dialog", nullptr));
        allBtn->setText(QCoreApplication::translate("ImagerPage", "\346\211\200\346\234\211", nullptr));
        queryBtn->setText(QCoreApplication::translate("ImagerPage", "\346\237\245\350\257\242", nullptr));
        reportBtn->setText(QCoreApplication::translate("ImagerPage", "\347\224\237\346\210\220\346\212\245\350\241\250", nullptr));
        label->setText(QCoreApplication::translate("ImagerPage", "\345\215\225\351\241\265\346\230\276\347\244\272\346\235\241\346\225\260", nullptr));
        okBtn->setText(QCoreApplication::translate("ImagerPage", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ImagerPage: public Ui_ImagerPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGERPAGE_H
