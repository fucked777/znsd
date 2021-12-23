#ifndef QUERYDIALOG_CXY_H
#define QUERYDIALOG_CXY_H

#include <QWidget>

namespace Ui
{
    class QueryDialog_CXY;
}

class QueryDialog_CXY : public QWidget
{
    Q_OBJECT

public:
    explicit QueryDialog_CXY(QWidget* parent = nullptr);
    ~QueryDialog_CXY();
signals:
    void search(const QStringList& taskName, const QStringList& taskNum, const QStringList& fileName, const QStringList& outputType,
                const QDateTime& start_time, const QDateTime& end_time);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::QueryDialog_CXY* ui;
};

#endif  // QUERYDIALOG_CXY_H
