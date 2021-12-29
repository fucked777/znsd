#ifndef ImagerPage_H
#define ImagerPage_H

#include <QCheckBox>
#include <QDialog>
#include <QStandardItemModel>
#include <QTableView>
namespace Ui
{
    class ImagerPage;
}

class pageWidget;
class QueryDialog_CXY;
class ImagerPage : public QDialog
{
    Q_OBJECT

public:
    explicit ImagerPage(QWidget* parent = nullptr);
    ~ImagerPage();

    void initView();
    void initMember();
private Q_SLOTS:
    void queryBtnClicked();
    void reportBtnClicked();
    void allBtnClicked();
    void currentPageChanged(int page);
    void query();
    void pageSizeChange(const QString& arg1);
    void slotGetTotalCount(const int totalCount, const int currentPage);
    void searchSlot(const QStringList& taskName, const QStringList& taskNum, const QStringList& fileName, const QStringList& outputType,
                    const QDateTime& start_time, const QDateTime& end_time);

public:
    void slotUpdataTable(/*const QByteArray& data*/);

private:
    QString pasraDoubleToStr(double value, int prsc = 1, char f = 'f');

private:
    Ui::ImagerPage* ui;
    QStringList headNames;
    QueryDialog_CXY* m_queryDialog_CXY;
    pageWidget* m_pageNavigator;
};

#endif  // ImagerPage_H
