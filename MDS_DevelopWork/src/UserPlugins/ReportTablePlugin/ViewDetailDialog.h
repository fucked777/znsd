#ifndef VIEWDETAILDIALOG_H
#define VIEWDETAILDIALOG_H

#include <QWidget>

namespace Ui
{
    class ViewDetailDialog;
}

class ViewDetailDialog : public QWidget
{
    Q_OBJECT

public:
    explicit ViewDetailDialog(QWidget* parent = nullptr);
    ~ViewDetailDialog();
    void parameterSet(const QStringList& data, int row);
    static QDateTime dateTimeFromStr(const QString&);
    static QString dateTimeToStr(const QDateTime&);
signals:
    void saveRemarksSignal(const QString& text, int row);
private slots:
    void on_pushButton_clicked();
    void textCurtextChange();

private:
    Ui::ViewDetailDialog* ui;
    QString dealRemarks;  //处理备注
    int rowIndex;         //哪一行按钮被点击
};

#endif  // VIEWDETAILDIALOG_H
