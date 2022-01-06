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

    void expand(const QModelIndex& index);
    void collapse(const QModelIndex& index);
    void deal_expand_collapse();
public slots:
    void slotinitData(const QByteArray&);

public:
    void slotUpdataTable();

private:
    QString pasraDoubleToStr(double value, int prsc = 1, char f = 'f');

private:
    Ui::ImagerPage* ui;
    QueryDialog_CXY* m_queryDialog_CXY;
    pageWidget* m_pageNavigator;
    SqlImagerManager* m_sqlImagerManager;
    int taskNum = 0;  //任务编号个数，以此来创建Qlist个数
    bool status = true;
};

#endif  // ImagerPage_H
