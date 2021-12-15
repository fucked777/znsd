#ifndef LogMsgPage_H
#define LogMsgPage_H

#include <QCheckBox>
#include <QDialog>
#include <QStandardItemModel>
namespace Ui
{
    class LogMsgPage;
}
namespace NSGlobal
{
    struct RowDataLogMsg
    {
        QString dateTime;
        QString systemName;
        QString taskNum;
        QString logMsg;
        QString logAttribute;
        bool operator>(const RowDataLogMsg& toCompare)
        {
            if (taskNum > toCompare.taskNum)
                return true;
            if (taskNum == toCompare.taskNum)
            {
                if (dateTime > toCompare.dateTime)
                    return true;
            }
            return false;
        }

        bool operator==(const RowDataLogMsg& toCompare) { return ((taskNum == toCompare.taskNum) && (dateTime == toCompare.dateTime)); }

        bool operator<(const RowDataLogMsg& toCompare)
        {
            if (taskNum < toCompare.taskNum)
                return true;
            if (taskNum == toCompare.taskNum)
            {
                if (dateTime < toCompare.dateTime)
                    return true;
            }
            return false;
        }
    };
    //    const QString SEPARATOR = "@";
}  // namespace NSGlobal
using namespace NSGlobal;

class HeaderView;
class NotEditableDelegate;
class TableAnalyse;
class LogMsgPage : public QDialog
{
    Q_OBJECT

public:
    explicit LogMsgPage(QWidget* parent = nullptr);
    ~LogMsgPage();

    QVector<RowDataLogMsg> getDatas() const;

    void initView();
    void initMember();
    // Q_SIGNALS:
    //    void settingDlgCloseSignal(int funcType, int count);
    //    void updateFreTableNumber(const int& xmlIndex, const int& index, const QString& value, const QString& unit);
    //    void dataSaveSignal(QVector<RowDataLogMsg> data);
private Q_SLOTS:
    void delBtnClicked();
    void queryBtnClicked();
    void reportBtnClicked();
    void allBtnClicked();

    void firstPageBtnClicked();
    void upperPageBtnClicked();
    void nextPageBtnClicked();
    void lastPageBtnClicked();
    void okBtnClicked();
    void clearBtnClicked();
    void delItemClicked(const int rowIndex);
    void curTestChangedCombox(const QString test);

public:
    void appendRowData(RowDataLogMsg value);
    RowDataLogMsg getRowData(const int rowNum);
    void updateRowData(QVector<RowDataLogMsg>& values);
    void insertRowData(RowDataLogMsg& values, int rowIndex);
    QVector<RowDataLogMsg> getDataInfo(RowDataLogMsg);
    QVector<RowDataLogMsg> getCheckedRowData();

private slots:
    void delItemClicked();
    void selectAllItems(Qt::CheckState state);
    void checkCurrRowSlot(int rowIndex, bool checked);

private:
    QString pasraDoubleToStr(double value, int prsc = 1, char f = 'f');

private:
    Ui::LogMsgPage* ui;
    QVector<RowDataLogMsg> m_datas;
    QStandardItemModel* tableModel;
    QStringList headNames;
    QVector<double> columnWidths;
    double m_scale = 0.0;
    QList<int> removeRowIndexs;
    double totleColumnWidth = 0.0;
    QCheckBox* m_check;
    HeaderView* headerView;
    NotEditableDelegate* notEditableDelegate;
    TableAnalyse* faultMstAnalyse;
};

#endif  // LogMsgPage_H
