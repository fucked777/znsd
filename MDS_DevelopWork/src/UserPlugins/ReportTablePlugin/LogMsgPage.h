#ifndef LogMsgPage_H
#define LogMsgPage_H

#include <QCheckBox>
#include <QDialog>
#include <QStandardItemModel>
#include <QTableView>
namespace Ui
{
    class LogMsgPage;
}
class LogQueryDialog;
class LogPageWidget;
class SqlLogMsgManager;
class LogMsgPage : public QDialog
{
    Q_OBJECT

public:
    explicit LogMsgPage(QWidget* parent = nullptr);
    ~LogMsgPage();

    void initView();
    void initMember();
    void setArrayDataInterface();

private:
    void processExport(const QString& fileName);
    void queryBtnClicked();
    void allBtnClicked();
    void exportStatus();
    void searchSlot(const QStringList& taskName, const QStringList& taskNum, const QStringList& fileName, const QStringList& outputType,
                    const QDateTime& start_time, const QDateTime& end_time);

public:
    void slotUpdataTable();

private:
    QString pasraDoubleToStr(double value, int prsc = 1, char f = 'f');

private:
    Ui::LogMsgPage* ui;
    LogQueryDialog* m_queryDialog;
    LogPageWidget* m_pageNavigator;
    SqlLogMsgManager* m_sqlLogMsgManager;
};

#endif  // LogMsgPage_H
