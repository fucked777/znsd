#ifndef FAULTPAGEFREAM_H
#define FAULTPAGEFREAM_H

#include <QWidget>

namespace Ui
{
    class FaultPageFream;
}

class FaultPageFream : public QWidget
{
    Q_OBJECT

public:
    explicit FaultPageFream(QWidget* parent = nullptr);
    ~FaultPageFream();

public Q_SLOTS:
    void showSwitchPage(const int& index);

private:
    Ui::FaultPageFream* ui;
};

#endif  // FAULTPAGEFREAM_H
