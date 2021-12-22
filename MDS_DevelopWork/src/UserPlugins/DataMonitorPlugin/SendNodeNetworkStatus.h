#ifndef SENDNODENETWORKSTATUS_H
#define SENDNODENETWORKSTATUS_H

#include <QWidget>

namespace Ui {
class SendNodeNetworkStatus;
}

class SendNodeNetworkStatus : public QWidget
{
    Q_OBJECT

public:
    explicit SendNodeNetworkStatus(QWidget *parent = nullptr);
    ~SendNodeNetworkStatus();

private:
    Ui::SendNodeNetworkStatus *ui;
};

#endif // SENDNODENETWORKSTATUS_H
