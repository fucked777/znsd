#ifndef FAULTPAGEFREAM_H
#define FAULTPAGEFREAM_H

#include <QWidget>

namespace Ui
{
    class FaultPageFream;
}
class InputOutputData;
class FaultLog;
class SystemLog;
class CallProcessParameter;
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
    InputOutputData* m_inputOutputData;
    FaultLog* m_faultLog;
    SystemLog* m_systemLog;
    CallProcessParameter* m_callProcessParameter;
};

#endif  // FAULTPAGEFREAM_H
