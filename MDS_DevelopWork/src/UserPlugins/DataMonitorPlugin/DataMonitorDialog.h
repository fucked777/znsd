#ifndef DATAMONITORDIALOG_H
#define DATAMONITORDIALOG_H

#include <QWidget>

namespace Ui {
class DataMonitorDialog;
}

class DataMonitorDialog : public QWidget
{
    Q_OBJECT

public:
    explicit DataMonitorDialog(QWidget *parent = nullptr);
    ~DataMonitorDialog();

private:
    Ui::DataMonitorDialog *ui;
};

#endif // DATAMONITORDIALOG_H
