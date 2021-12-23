#ifndef ImagerPage_H
#define ImagerPage_H

#include <QCheckBox>
#include <QDialog>
#include <QStandardItemModel>
namespace Ui
{
    class ImagerPage;
}
class PageNavigator;
class DeviceStatusLogTableModel;
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
    void okBtnClicked();
    void currentPageChanged(int page);
    void query();
    void pageSizeChange(const QString& arg1);
    void slotGetTotalCount(const int totalCount, const int currentPage);
    void searchSlot(const QStringList& taskName, const QStringList& taskNum, const QStringList& fileName, const QStringList& outputType,
                    const QDateTime& start_time, const QDateTime& end_time);

public:
    void slotSearchAck(/*const QByteArray& data*/);
    // public:
    //    void updateRowData(QVector<RowDataImagerMsg>& values);

private:
    QString pasraDoubleToStr(double value, int prsc = 1, char f = 'f');

private:
    Ui::ImagerPage* ui;
    QStandardItemModel* tableModel;
    QStringList headNames;
    QueryDialog_CXY* m_queryDialog_CXY;
    PageNavigator* m_pageNavigator;
    DeviceStatusLogTableModel* m_deviceStatusLogTableModel;
};

#endif  // ImagerPage_H
