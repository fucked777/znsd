/********************************************************************************
** Form generated from reading UI file 'LoadFilePage.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOADFILEPAGE_H
#define UI_LOADFILEPAGE_H

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

class Ui_LoadFilePage
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBox;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_3;
    QLabel *label_5;
    QPushButton *queryBtn;
    QPushButton *reportBtn;
    QSpacerItem *horizontalSpacer_2;
    QWidget *tableWidget;
    QGridLayout *gridLayout;
    QTableView *tableView;

    void setupUi(QDialog *LoadFilePage)
    {
        if (LoadFilePage->objectName().isEmpty())
            LoadFilePage->setObjectName(QString::fromUtf8("LoadFilePage"));
        LoadFilePage->resize(1120, 606);
        LoadFilePage->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(LoadFilePage);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(LoadFilePage);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        comboBox = new QComboBox(LoadFilePage);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout->addWidget(comboBox);

        label_2 = new QLabel(LoadFilePage);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        label_4 = new QLabel(LoadFilePage);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout->addWidget(label_4);

        label_3 = new QLabel(LoadFilePage);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        label_5 = new QLabel(LoadFilePage);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout->addWidget(label_5);

        queryBtn = new QPushButton(LoadFilePage);
        queryBtn->setObjectName(QString::fromUtf8("queryBtn"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(queryBtn->sizePolicy().hasHeightForWidth());
        queryBtn->setSizePolicy(sizePolicy);
        queryBtn->setMinimumSize(QSize(80, 0));
        queryBtn->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        queryBtn->setFont(font);
        queryBtn->setStyleSheet(QString::fromUtf8(""));
        queryBtn->setCheckable(true);
        queryBtn->setChecked(false);
        queryBtn->setAutoExclusive(true);

        horizontalLayout->addWidget(queryBtn);

        reportBtn = new QPushButton(LoadFilePage);
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

        horizontalLayout->addWidget(reportBtn);

        horizontalSpacer_2 = new QSpacerItem(651, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        tableWidget = new QWidget(LoadFilePage);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy1);
        gridLayout = new QGridLayout(tableWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tableView = new QTableView(tableWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        gridLayout->addWidget(tableView, 0, 0, 1, 1);


        verticalLayout->addWidget(tableWidget);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 9);

        retranslateUi(LoadFilePage);

        QMetaObject::connectSlotsByName(LoadFilePage);
    } // setupUi

    void retranslateUi(QDialog *LoadFilePage)
    {
        LoadFilePage->setWindowTitle(QCoreApplication::translate("LoadFilePage", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("LoadFilePage", "\350\275\275\350\215\267\347\261\273\345\236\213\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("LoadFilePage", "\345\274\200\345\247\213\346\227\266\351\227\264", nullptr));
        label_4->setText(QCoreApplication::translate("LoadFilePage", "\346\227\245\346\234\237\347\273\204\344\273\266", nullptr));
        label_3->setText(QCoreApplication::translate("LoadFilePage", "\347\273\223\346\235\237\346\227\266\351\227\264", nullptr));
        label_5->setText(QCoreApplication::translate("LoadFilePage", "\346\227\245\346\234\237\347\273\204\344\273\266", nullptr));
        queryBtn->setText(QCoreApplication::translate("LoadFilePage", "\346\237\245\350\257\242", nullptr));
        reportBtn->setText(QCoreApplication::translate("LoadFilePage", "\347\224\237\346\210\220\346\212\245\350\241\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoadFilePage: public Ui_LoadFilePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOADFILEPAGE_H
