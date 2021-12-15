#ifndef FastImagerPage_H
#define FastImagerPage_H

#include <QCheckBox>
#include <QDialog>
#include <QStandardItemModel>
namespace Ui
{
    class FastImagerPage;
}
namespace NSGlobal
{
    struct RowDataFastImagerMsg
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
        bool operator>(const RowDataFastImagerMsg& toCompare)
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

        bool operator==(const RowDataFastImagerMsg& toCompare) { return ((taskNum == toCompare.taskNum) && (faultCode == toCompare.faultCode)); }

        bool operator<(const RowDataFastImagerMsg& toCompare)
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
    //    const QString SEPARATOR = "@";
}  // namespace NSGlobal
using namespace NSGlobal;
class HeaderView;
class NotEditableDelegate;
class TableAnalyse;
class FastImagerPage : public QDialog
{
    Q_OBJECT

public:
    explicit FastImagerPage(QWidget* parent = nullptr);
    ~FastImagerPage();

    QVector<RowDataFastImagerMsg> getDatas() const;

    void initView();
    void initMember();
    // Q_SIGNALS:
    //    void settingDlgCloseSignal(int funcType, int count);
    //    void updateFreTableNumber(const int& xmlIndex, const int& index, const QString& value, const QString& unit);
    //    void dataSaveSignal(QVector<RowDataFastImagerMsg> data);
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
    void appendRowData(RowDataFastImagerMsg value);
    RowDataFastImagerMsg getRowData(const int rowNum);
    void updateRowData(QVector<RowDataFastImagerMsg>& values);
    void insertRowData(RowDataFastImagerMsg& values, int rowIndex);
    QVector<RowDataFastImagerMsg> getDataInfo(RowDataFastImagerMsg);
    QVector<RowDataFastImagerMsg> getCheckedRowData();

private slots:
    void delItemClicked();
    void selectAllItems(Qt::CheckState state);
    void checkCurrRowSlot(int rowIndex, bool checked);

private:
    QString pasraDoubleToStr(double value, int prsc = 1, char f = 'f');

private:
    Ui::FastImagerPage* ui;
    QVector<RowDataFastImagerMsg> m_datas;
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

#endif  // FastImagerPage_H
