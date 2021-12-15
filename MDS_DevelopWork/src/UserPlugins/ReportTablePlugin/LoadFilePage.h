#ifndef LoadFilePage_H
#define LoadFilePage_H

#include <QDialog>
#include <QStandardItemModel>
namespace Ui
{
    class LoadFilePage;
}
class QStandardItemModel;
namespace NSGlobal
{
    struct RowDataLoadFileMsg
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
        bool operator>(const RowDataLoadFileMsg& toCompare)
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

        bool operator==(const RowDataLoadFileMsg& toCompare) { return ((taskNum == toCompare.taskNum) && (faultCode == toCompare.faultCode)); }

        bool operator<(const RowDataLoadFileMsg& toCompare)
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
class LoadFilePage : public QDialog
{
    Q_OBJECT
public:
    explicit LoadFilePage(QWidget* parent = nullptr);
    ~LoadFilePage();

    QVector<RowDataLoadFileMsg> getDatas() const;

    void setListIndex(int listIndex);

    // Q_SIGNALS:
    //    void settingDlgCloseSignal(int funcType, int count);
    //    void updateFreTableNumber(const int& xmlIndex, const int& index, const QString& value, const QString& unit);
    //    void dataSaveSignal(QVector<RowDataLoadFileMsg> data);
private Q_SLOTS:
    void queryBtnClicked();
    void reportBtnClicked();
    void delItemClicked(const int rowIndex);
    void pointAddParameterValueSlot(const int& type, const QStringList& value1);

private:
    void initView();
    void initMember();

private:
    QString pasraDoubleToStr(double value, int prsc = 1, char f = 'f');

private:
    Ui::LoadFilePage* ui;
    QVector<RowDataLoadFileMsg> m_datas;
    QStandardItemModel* tableModel;
    QVector<double> columnWidths;
    double m_scale = 0.0;
    QStringList headNames;
    QList<int> removeRowIndexs;
    double totleColumnWidth = 0.0;
};

#endif  // LoadFilePage_H
