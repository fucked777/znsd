/********************************************************************************
** Form generated from reading UI file 'StellarPredictionPage.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STELLARPREDICTIONPAGE_H
#define UI_STELLARPREDICTIONPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StellarPredictionPage
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *contextWidgets;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *allBtn;
    QPushButton *queryBtn;
    QPushButton *delBtn;
    QPushButton *clearBtn;
    QPushButton *reportBtn;
    QSpacerItem *horizontalSpacer_2;
    QWidget *tableWidget;
    QGridLayout *gridLayout;
    QTableView *tableView;
    QWidget *buttomWidget;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QComboBox *comboBox;
    QPushButton *firstPageBtn;
    QPushButton *upperPageBtn;
    QPushButton *nextPageBtn;
    QPushButton *lastPageBtn;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLabel *allPageNumLabel;
    QLabel *label_4;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_6;
    QLabel *curPageLabel;
    QLabel *label_8;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_9;
    QLineEdit *lineEdit;
    QLabel *label_11;
    QPushButton *okBtn;

    void setupUi(QDialog *StellarPredictionPage)
    {
        if (StellarPredictionPage->objectName().isEmpty())
            StellarPredictionPage->setObjectName(QString::fromUtf8("StellarPredictionPage"));
        StellarPredictionPage->resize(1120, 699);
        StellarPredictionPage->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(StellarPredictionPage);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        contextWidgets = new QWidget(StellarPredictionPage);
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

        delBtn = new QPushButton(contextWidgets);
        delBtn->setObjectName(QString::fromUtf8("delBtn"));
        sizePolicy.setHeightForWidth(delBtn->sizePolicy().hasHeightForWidth());
        delBtn->setSizePolicy(sizePolicy);
        delBtn->setMinimumSize(QSize(80, 0));
        delBtn->setMaximumSize(QSize(16777215, 16777215));
        delBtn->setFont(font);
        delBtn->setStyleSheet(QString::fromUtf8(""));
        delBtn->setCheckable(true);
        delBtn->setChecked(true);
        delBtn->setAutoExclusive(true);
        delBtn->setFlat(false);

        horizontalLayout_2->addWidget(delBtn);

        clearBtn = new QPushButton(contextWidgets);
        clearBtn->setObjectName(QString::fromUtf8("clearBtn"));
        sizePolicy.setHeightForWidth(clearBtn->sizePolicy().hasHeightForWidth());
        clearBtn->setSizePolicy(sizePolicy);
        clearBtn->setMinimumSize(QSize(80, 0));
        clearBtn->setMaximumSize(QSize(16777215, 16777215));
        clearBtn->setFont(font);
        clearBtn->setStyleSheet(QString::fromUtf8(""));
        clearBtn->setCheckable(true);
        clearBtn->setChecked(true);
        clearBtn->setAutoExclusive(true);
        clearBtn->setFlat(false);

        horizontalLayout_2->addWidget(clearBtn);

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

        tableWidget = new QWidget(StellarPredictionPage);
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

        buttomWidget = new QWidget(StellarPredictionPage);
        buttomWidget->setObjectName(QString::fromUtf8("buttomWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(buttomWidget->sizePolicy().hasHeightForWidth());
        buttomWidget->setSizePolicy(sizePolicy1);
        horizontalLayout_9 = new QHBoxLayout(buttomWidget);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalSpacer = new QSpacerItem(234, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer);

        label = new QLabel(buttomWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_9->addWidget(label);

        comboBox = new QComboBox(buttomWidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout_9->addWidget(comboBox);

        firstPageBtn = new QPushButton(buttomWidget);
        firstPageBtn->setObjectName(QString::fromUtf8("firstPageBtn"));

        horizontalLayout_9->addWidget(firstPageBtn);

        upperPageBtn = new QPushButton(buttomWidget);
        upperPageBtn->setObjectName(QString::fromUtf8("upperPageBtn"));

        horizontalLayout_9->addWidget(upperPageBtn);

        nextPageBtn = new QPushButton(buttomWidget);
        nextPageBtn->setObjectName(QString::fromUtf8("nextPageBtn"));

        horizontalLayout_9->addWidget(nextPageBtn);

        lastPageBtn = new QPushButton(buttomWidget);
        lastPageBtn->setObjectName(QString::fromUtf8("lastPageBtn"));

        horizontalLayout_9->addWidget(lastPageBtn);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(buttomWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        allPageNumLabel = new QLabel(buttomWidget);
        allPageNumLabel->setObjectName(QString::fromUtf8("allPageNumLabel"));

        horizontalLayout->addWidget(allPageNumLabel);

        label_4 = new QLabel(buttomWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout->addWidget(label_4);


        horizontalLayout_9->addLayout(horizontalLayout);

        label_5 = new QLabel(buttomWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_9->addWidget(label_5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_6 = new QLabel(buttomWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_3->addWidget(label_6);

        curPageLabel = new QLabel(buttomWidget);
        curPageLabel->setObjectName(QString::fromUtf8("curPageLabel"));

        horizontalLayout_3->addWidget(curPageLabel);

        label_8 = new QLabel(buttomWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_3->addWidget(label_8);


        horizontalLayout_9->addLayout(horizontalLayout_3);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_9 = new QLabel(buttomWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_8->addWidget(label_9);

        lineEdit = new QLineEdit(buttomWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy2);

        horizontalLayout_8->addWidget(lineEdit);

        label_11 = new QLabel(buttomWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_8->addWidget(label_11);


        horizontalLayout_9->addLayout(horizontalLayout_8);

        okBtn = new QPushButton(buttomWidget);
        okBtn->setObjectName(QString::fromUtf8("okBtn"));

        horizontalLayout_9->addWidget(okBtn);


        verticalLayout->addWidget(buttomWidget);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 9);
        verticalLayout->setStretch(2, 1);

        retranslateUi(StellarPredictionPage);

        QMetaObject::connectSlotsByName(StellarPredictionPage);
    } // setupUi

    void retranslateUi(QDialog *StellarPredictionPage)
    {
        StellarPredictionPage->setWindowTitle(QCoreApplication::translate("StellarPredictionPage", "Dialog", nullptr));
        allBtn->setText(QCoreApplication::translate("StellarPredictionPage", "\346\211\200\346\234\211", nullptr));
        queryBtn->setText(QCoreApplication::translate("StellarPredictionPage", "\346\237\245\350\257\242", nullptr));
        delBtn->setText(QCoreApplication::translate("StellarPredictionPage", "\345\210\240\351\231\244", nullptr));
        clearBtn->setText(QCoreApplication::translate("StellarPredictionPage", "\346\270\205\347\220\206", nullptr));
        reportBtn->setText(QCoreApplication::translate("StellarPredictionPage", "\347\224\237\346\210\220\346\212\245\350\241\250", nullptr));
        label->setText(QCoreApplication::translate("StellarPredictionPage", "\345\215\225\351\241\265\346\230\276\347\244\272\346\235\241\346\225\260", nullptr));
        firstPageBtn->setText(QCoreApplication::translate("StellarPredictionPage", "\351\246\226\351\241\265", nullptr));
        upperPageBtn->setText(QCoreApplication::translate("StellarPredictionPage", "\344\270\212\351\241\265", nullptr));
        nextPageBtn->setText(QCoreApplication::translate("StellarPredictionPage", "\344\270\213\351\241\265", nullptr));
        lastPageBtn->setText(QCoreApplication::translate("StellarPredictionPage", "\346\234\253\351\241\265", nullptr));
        label_2->setText(QCoreApplication::translate("StellarPredictionPage", "\345\205\261", nullptr));
        allPageNumLabel->setText(QCoreApplication::translate("StellarPredictionPage", "57", nullptr));
        label_4->setText(QCoreApplication::translate("StellarPredictionPage", "\351\241\265", nullptr));
        label_5->setText(QCoreApplication::translate("StellarPredictionPage", "\345\275\223\345\211\215", nullptr));
        label_6->setText(QCoreApplication::translate("StellarPredictionPage", "\347\254\254", nullptr));
        curPageLabel->setText(QCoreApplication::translate("StellarPredictionPage", "1", nullptr));
        label_8->setText(QCoreApplication::translate("StellarPredictionPage", "\351\241\265", nullptr));
        label_9->setText(QCoreApplication::translate("StellarPredictionPage", "\350\267\263\350\275\254\350\207\263\347\254\254", nullptr));
        lineEdit->setText(QCoreApplication::translate("StellarPredictionPage", "55", nullptr));
        label_11->setText(QCoreApplication::translate("StellarPredictionPage", "\351\241\265", nullptr));
        okBtn->setText(QCoreApplication::translate("StellarPredictionPage", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StellarPredictionPage: public Ui_StellarPredictionPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STELLARPREDICTIONPAGE_H
