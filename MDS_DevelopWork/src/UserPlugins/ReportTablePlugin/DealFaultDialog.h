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
    void parameterSet(const QStringList& data);
public slots:
    void comboxCurtextChange(const QString& text);
    void textCurtextChange();

private:
    Ui::DealFaultDialog* ui;
    QString dealRemarks;
    QString comboxText;
};

#endif  // DEALFAULTDIALOG_H
