#ifndef VIEWDETAILDIALOG_H
#define VIEWDETAILDIALOG_H

#include <QWidget>

namespace Ui {
class ViewDetailDialog;
}

class ViewDetailDialog : public QWidget
{
    Q_OBJECT

public:
    explicit ViewDetailDialog(QWidget *parent = nullptr);
    ~ViewDetailDialog();

private:
    Ui::ViewDetailDialog *ui;
};

#endif // VIEWDETAILDIALOG_H
