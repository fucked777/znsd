#ifndef ImagerPage_H
#define ImagerPage_H

#include <QCheckBox>
#include <QDialog>
#include <QStandardItemModel>
namespace Ui
{
    class ImagerPage;
}
namespace NSGlobal
{
    struct RowDataImagerMsg
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
        bool operator>(const RowDataImagerMsg& toCompare)
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

        bool operator==(const RowDataImagerMsg& toCompare) { return ((taskNum == toCompare.taskNum) && (faultCode == toCompare.faultCode)); }

        bool operator<(const RowDataImagerMsg& toCompare)
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
class TableAnalyse;
class ImagerPage : public QDialog
{
    Q_OBJECT

public:
    explicit ImagerPage(QWidget* parent = nullptr);
    ~ImagerPage();

    QVector<RowDataImagerMsg> getDatas() const;

    void initView();
    void initMember();
    // Q_SIGNALS:
    //    void settingDlgCloseSignal(int funcType, int count);
    //    void updateFreTableNumber(const int& xmlIndex, const int& index, const QString& value, const QString& unit);
    //    void dataSaveSignal(QVector<RowDataImagerMsg> data);
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
    void appendRowData(RowDataImagerMsg value);
    RowDataImagerMsg getRowData(const int rowNum);
    void updateRowData(QVector<RowDataImagerMsg>& values);
    void insertRowData(RowDataImagerMsg& values, int rowIndex);
    QVector<RowDataImagerMsg> getDataInfo(RowDataImagerMsg);
    QVector<RowDataImagerMsg> getCheckedRowData();

private slots:
    void delItemClicked();
    void selectAllItems(Qt::CheckState state);
    void checkCurrRowSlot(int rowIndex, bool checked);

private:
    QString pasraDoubleToStr(double value, int prsc = 1, char f = 'f');

private:
    Ui::ImagerPage* ui;
    QVector<RowDataImagerMsg> m_datas;
    QStandardItemModel* tableModel;
    QStringList headNames;
    double m_scale = 0.0;
    QList<int> removeRowIndexs;
    TableAnalyse* faultMstAnalyse;
};

#endif  // ImagerPage_H
