#ifndef StellarPredictionPage_H
#define StellarPredictionPage_H

#include <QCheckBox>
#include <QDialog>
#include <QStandardItemModel>
namespace Ui
{
    class StellarPredictionPage;
}
namespace NSGlobal
{
    struct RowDataStellarMsg
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
        bool operator>(const RowDataStellarMsg& toCompare)
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

        bool operator==(const RowDataStellarMsg& toCompare) { return ((taskNum == toCompare.taskNum) && (faultCode == toCompare.faultCode)); }

        bool operator<(const RowDataStellarMsg& toCompare)
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
class StellarPredictionPage : public QDialog
{
    Q_OBJECT

public:
    explicit StellarPredictionPage(QWidget* parent = nullptr);
    ~StellarPredictionPage();

    QVector<RowDataStellarMsg> getDatas() const;

    void initView();
    void initMember();
    // Q_SIGNALS:
    //    void settingDlgCloseSignal(int funcType, int count);
    //    void updateFreTableNumber(const int& xmlIndex, const int& index, const QString& value, const QString& unit);
    //    void dataSaveSignal(QVector<RowDataStellarMsg> data);
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
    void appendRowData(RowDataStellarMsg value);
    RowDataStellarMsg getRowData(const int rowNum);
    void updateRowData(QVector<RowDataStellarMsg>& values);
    void insertRowData(RowDataStellarMsg& values, int rowIndex);
    QVector<RowDataStellarMsg> getDataInfo(RowDataStellarMsg);
    QVector<RowDataStellarMsg> getCheckedRowData();

private slots:
    void delItemClicked();
    void selectAllItems(Qt::CheckState state);
    void checkCurrRowSlot(int rowIndex, bool checked);

private:
    QString pasraDoubleToStr(double value, int prsc = 1, char f = 'f');

private:
    Ui::StellarPredictionPage* ui;
    QVector<RowDataStellarMsg> m_datas;
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

#endif  // StellarPredictionPage_H
