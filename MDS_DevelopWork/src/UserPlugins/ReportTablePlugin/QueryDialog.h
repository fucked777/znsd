#ifndef QUERYDIALOG_H
#define QUERYDIALOG_H

#include <QWidget>

namespace Ui
{
    class QueryDialog;
}

class QueryDialog : public QWidget
{
    Q_OBJECT

public:
    explicit QueryDialog(QWidget* parent = nullptr);
    ~QueryDialog();
signals:
    void search(const QStringList& taskName, const QStringList& taskNum, const QStringList& fileName, const QStringList& outputType,
                const QDateTime& start_time, const QDateTime& end_time);

private:
    Ui::QueryDialog* ui;
};

#endif  // QUERYDIALOG_H
