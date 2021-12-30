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

struct LogMsg
{
    QString faultLevel;
    QString dateTime;
    QString taskNum;
    QString faultCode;
    QString systemName;
    QString dealStatus;
    QString faultInfor;
    QString internalFault;
    QString remarks;
};
class QueryDialog;
class DealFaultDialog;
class ViewDetailDialog;
class pageWidget;
class SqlFaultMsgManager;
class LogMsgPage : public QDialog
{
    Q_OBJECT

public:
    explicit LogMsgPage(QWidget* parent = nullptr);
    ~LogMsgPage();

    void initView();
    void initMember();

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
    DealFaultDialog* m_dealFaultDialog;
    QueryDialog* m_queryDialog;
    pageWidget* m_pageNavigator;
    ViewDetailDialog* m_viewDetailDialog;
    SqlFaultMsgManager* m_sqlFaultMsgManager;
};

#endif  // LogMsgPage_H
