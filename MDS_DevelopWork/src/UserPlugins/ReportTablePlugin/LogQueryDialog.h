#ifndef LOGQUERYDIALOG_H
#define LOGQUERYDIALOG_H

#include <QWidget>

namespace Ui {
class LogQueryDialog;
}

class LogQueryDialog : public QWidget
{
    Q_OBJECT

public:
    explicit LogQueryDialog(QWidget *parent = nullptr);
    ~LogQueryDialog();

private:
    Ui::LogQueryDialog *ui;
};

#endif // LOGQUERYDIALOG_H
