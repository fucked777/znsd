#ifndef RECEIVENODENETWORKSTATUS_H
#define RECEIVENODENETWORKSTATUS_H

#include <QWidget>

namespace Ui {
class ReceiveNodeNetworkStatus;
}

class ReceiveNodeNetworkStatus : public QWidget
{
    Q_OBJECT

public:
    explicit ReceiveNodeNetworkStatus(QWidget *parent = nullptr);
    ~ReceiveNodeNetworkStatus();

private:
    Ui::ReceiveNodeNetworkStatus *ui;
};

#endif // RECEIVENODENETWORKSTATUS_H
