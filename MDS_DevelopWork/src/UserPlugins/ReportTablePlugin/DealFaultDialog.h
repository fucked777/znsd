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
    void parameterSet(const QStringList& data, int row);
public slots:
    void comboxCurtextChange(const QString& text);
    void textCurtextChange();
signals:
    void dealRemarksSignal(const QStringList& text, int row);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::DealFaultDialog* ui;
    QString dealRemarks{ "" };
    QString comboxText{ "暂未处理" };
    int rowIndex = 0;
};

#endif  // DEALFAULTDIALOG_H
