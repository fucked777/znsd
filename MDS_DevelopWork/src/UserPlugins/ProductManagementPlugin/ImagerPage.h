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
class SqlImagerManager;
class ImagerPage : public QDialog
{
    Q_OBJECT

public:
    explicit ImagerPage(QWidget* parent = nullptr);
    ~ImagerPage();

    void initView();
    void initMember();
    void setArrayDataInterface();

private:
    void processExport(const QString& fileName);
private Q_SLOTS:
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
    Ui::ImagerPage* ui;
    QueryDialog_CXY* m_queryDialog_CXY;
    pageWidget* m_pageNavigator;
    SqlImagerManager* m_sqlImagerManager;
};

#endif  // ImagerPage_H
