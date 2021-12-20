#ifndef FaultMsgPage_H
#define FaultMsgPage_H

#include <QCheckBox>
#include <QDialog>
#include <QStandardItemModel>
namespace Ui
{
    class FaultMsgPage;
}
namespace NSGlobal
{
    struct RowDataFaultMsg
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
        bool operator>(const RowDataFaultMsg& toCompare)
        {
            if (taskNum > toCompare.taskNum)
                return true;
            if (taskNum == toCompare.taskNum)
            {
                if (faultCode > toCompare.faultCode)
                    return true;
            }
            return false;
        }

        bool operator==(const RowDataFaultMsg& toCompare) { return ((taskNum == toCompare.taskNum) && (faultCode == toCompare.faultCode)); }

        bool operator<(const RowDataFaultMsg& toCompare)
        {
            if (taskNum < toCompare.taskNum)
                return true;
            if (taskNum == toCompare.taskNum)
            {
                if (faultCode < toCompare.faultCode)
                    return true;
            }
            return false;
        }
    };
    const QString SEPARATOR = "@";
}  // namespace NSGlobal
using namespace NSGlobal;
class HeaderView;
class NotEditableDelegate;
class TableAnalyse;
class FaultMsgPage : public QDialog
{
    Q_OBJECT

public:
    explicit FaultMsgPage(QWidget* parent = nullptr);
    ~FaultMsgPage();

    QVector<RowDataFaultMsg> getDatas() const;

    void initView();
    void initMember();
    // Q_SIGNALS:
    //    void settingDlgCloseSignal(int funcType, int count);
    //    void updateFreTableNumber(const int& xmlIndex, const int& index, const QString& value, const QString& unit);
    //    void dataSaveSignal(QVector<RowDataFaultMsg> data);
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
    void appendRowData(RowDataFaultMsg value);
    RowDataFaultMsg getRowData(const int rowNum);
    void updateRowData(QVector<RowDataFaultMsg>& values);
    void insertRowData(RowDataFaultMsg& values, int rowIndex);
    QVector<RowDataFaultMsg> getDataInfo(RowDataFaultMsg);
    QVector<RowDataFaultMsg> getCheckedRowData();
    int initPage();
private slots:
    void delItemClicked();
    void selectAllItems(Qt::CheckState state);
    void checkCurrRowSlot(int rowIndex, bool checked);

private:
    QString pasraDoubleToStr(double value, int prsc = 1, char f = 'f');

private:
    Ui::FaultMsgPage* ui;
    QVector<RowDataFaultMsg> m_datas;
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
    int rowCount;
    int comboxCurIndex;
    int pageCount;
};

#endif  // FaultMsgPage_H
