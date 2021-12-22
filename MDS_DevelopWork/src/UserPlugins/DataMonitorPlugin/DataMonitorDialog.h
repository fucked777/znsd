#ifndef DATAMONITORDIALOG_H
#define DATAMONITORDIALOG_H

#include <QWidget>

namespace Ui
{
    class DataMonitorDialog;
}
class SendNodeNetworkStatus;
class ReceiveNodeNetworkStatus;
class DataMonitorDialog : public QWidget
{
    Q_OBJECT

public:
    explicit DataMonitorDialog(QWidget* parent = nullptr);
    ~DataMonitorDialog();

private:
    Ui::DataMonitorDialog* ui;
    SendNodeNetworkStatus* m_sendNodeNetworkStatus;
    ReceiveNodeNetworkStatus* m_receiveNodeNetworkStatus;
};

#endif  // DATAMONITORDIALOG_H
