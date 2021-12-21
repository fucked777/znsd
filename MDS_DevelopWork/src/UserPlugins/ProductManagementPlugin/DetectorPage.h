#ifndef DetectorPage_H
#define DetectorPage_H

#include <QCheckBox>
#include <QDialog>
#include <QStandardItemModel>
namespace Ui
{
    class DetectorPage;
}
namespace NSGlobal
{
    struct RowDataDetectorMsg
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
        bool operator>(const RowDataDetectorMsg& toCompare)
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

        bool operator==(const RowDataDetectorMsg& toCompare) { return ((taskNum == toCompare.taskNum) && (faultCode == toCompare.faultCode)); }

        bool operator<(const RowDataDetectorMsg& toCompare)
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
class TableAnalyse;
class DetectorPage : public QDialog
{
    Q_OBJECT

public:
    explicit DetectorPage(QWidget* parent = nullptr);
    ~DetectorPage();

    QVector<RowDataDetectorMsg> getDatas() const;

    void initView();
    void initMember();
    // Q_SIGNALS:
    //    void settingDlgCloseSignal(int funcType, int count);
    //    void updateFreTableNumber(const int& xmlIndex, const int& index, const QString& value, const QString& unit);
    //    void dataSaveSignal(QVector<RowDataDetectorMsg> data);
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
    void appendRowData(RowDataDetectorMsg value);
    RowDataDetectorMsg getRowData(const int rowNum);
    void updateRowData(QVector<RowDataDetectorMsg>& values);
    void insertRowData(RowDataDetectorMsg& values, int rowIndex);
    QVector<RowDataDetectorMsg> getDataInfo(RowDataDetectorMsg);
    QVector<RowDataDetectorMsg> getCheckedRowData();

private slots:
    void delItemClicked();
    void selectAllItems(Qt::CheckState state);
    void checkCurrRowSlot(int rowIndex, bool checked);

private:
    QString pasraDoubleToStr(double value, int prsc = 1, char f = 'f');

private:
    Ui::DetectorPage* ui;
    QVector<RowDataDetectorMsg> m_datas;
    QStandardItemModel* tableModel;
    QStringList headNames;
    double m_scale = 0.0;
    QList<int> removeRowIndexs;
    double totleColumnWidth = 0.0;
    QCheckBox* m_check;
    TableAnalyse* faultMstAnalyse;
};

#endif  // DetectorPage_H
