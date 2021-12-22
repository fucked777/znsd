#ifndef FAULTLOG_H
#define FAULTLOG_H

#include <QWidget>

namespace Ui {
class FaultLog;
}

class FaultLog : public QWidget
{
    Q_OBJECT

public:
    explicit FaultLog(QWidget *parent = nullptr);
    ~FaultLog();

private:
    Ui::FaultLog *ui;
};

#endif // FAULTLOG_H
