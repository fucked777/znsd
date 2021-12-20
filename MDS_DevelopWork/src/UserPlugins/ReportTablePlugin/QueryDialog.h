#ifndef QUERYDIALOG_H
#define QUERYDIALOG_H

#include <QWidget>

namespace Ui {
class QueryDialog;
}

class QueryDialog : public QWidget
{
    Q_OBJECT

public:
    explicit QueryDialog(QWidget *parent = nullptr);
    ~QueryDialog();

private:
    Ui::QueryDialog *ui;
};

#endif // QUERYDIALOG_H
