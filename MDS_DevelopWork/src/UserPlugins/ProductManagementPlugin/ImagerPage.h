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

    void firstPageBtnClicked();
    void upperPageBtnClicked();
    void nextPageBtnClicked();
    void lastPageBtnClicked();
    void okBtnClicked();
public slots:
    void slotSearchAck(const QByteArray& data);
    // public:
    //    void updateRowData(QVector<RowDataImagerMsg>& values);

private:
    QString pasraDoubleToStr(double value, int prsc = 1, char f = 'f');

private:
    Ui::ImagerPage* ui;
    QStandardItemModel* tableModel;
    QStringList headNames;
    PageNavigator* m_pageNavigator;
    DeviceStatusLogTableModel* m_deviceStatusLogTableModel;
};

#endif  // ImagerPage_H
