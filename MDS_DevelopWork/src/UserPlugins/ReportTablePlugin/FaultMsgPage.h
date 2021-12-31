#ifndef FaultMsgPage_H
#define FaultMsgPage_H

#include <QCheckBox>
#include <QDialog>
#include <QStandardItemModel>
#include <QTableView>
namespace Ui
{
    class FaultMsgPage;
}
class QueryDialog;
class DealFaultDialog;
class ViewDetailDialog;
class pageWidget;
class SqlFaultMsgManager;
class FaultMsgPage : public QDialog
{
    Q_OBJECT

public:
    explicit FaultMsgPage(QWidget* parent = nullptr);
    ~FaultMsgPage();

    void initView();
    void initMember();

    // signals:
    //    void init();
private slots:
    void slotUpdataTable();
    void viewDetailBtnClicked();
    void dealFaultBtnClicked();

private:
    void processExport(const QString& fileName);
    void queryBtnClicked();
    void allBtnClicked();
    void exportStatus();
    void searchSlot(const QStringList& taskName, const QStringList& taskNum, const QStringList& fileName, const QStringList& outputType,
                    const QDateTime& start_time, const QDateTime& end_time);

private:
    QString pasraDoubleToStr(double value, int prsc = 1, char f = 'f');

private:
    Ui::FaultMsgPage* ui;
    DealFaultDialog* m_dealFaultDialog;
    QueryDialog* m_queryDialog;
    pageWidget* m_pageNavigator;
    ViewDetailDialog* m_viewDetailDialog;
    SqlFaultMsgManager* m_sqlFaultMsgManager;
    //    int xhcs;
};

#endif  // FaultMsgPage_H
