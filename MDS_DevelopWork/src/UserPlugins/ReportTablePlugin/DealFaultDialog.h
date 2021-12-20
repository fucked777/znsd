#ifndef DEALFAULTDIALOG_H
#define DEALFAULTDIALOG_H

#include <QWidget>

namespace Ui
{
    class DealFaultDialog;
}

class DealFaultDialog : public QWidget
{
    Q_OBJECT

public:
    explicit DealFaultDialog(QWidget* parent = nullptr);
    ~DealFaultDialog();
    void initMember();

private:
    Ui::DealFaultDialog* ui;
};

#endif  // DEALFAULTDIALOG_H
