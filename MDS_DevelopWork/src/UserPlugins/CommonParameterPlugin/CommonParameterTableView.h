#ifndef CommonParameterTableView_H
#define CommonParameterTableView_H

#include <QDateTime>
#include <QStandardItemModel>
#include <QTimer>
#include <QWidget>
class QStandardItemModel;
class HeaderView;
class NotEditableDelegate;
typedef struct CommonParameterTable
{
    QString fileType;
    QString fileName;
    QDateTime getTime;
    QDateTime useTime;
} CommonParameter;

namespace Ui
{
    class CommonParameterTableView;
}

class CommonParameterTableView : public QWidget
{
    Q_OBJECT

public:
    explicit CommonParameterTableView(QWidget* parent = nullptr, int blueColumn = -1, QStringList headNames = QStringList());
    ~CommonParameterTableView();

    //    void appendRowDataLSSM(RowDataKZQ value);

    void updateRowData(QVector<CommonParameter>& values);
    //    void insertRowData(const NSGlobal::RowDataKZQ& values, int rowIndex);
    //    void addRowData(const NSGlobal::RowDataKZQ& values, int rowIndex);
    void delRowDataLSSM();
    //    QVector<NSGlobal::LSSMFreqTableRowData> getDataInfo(NSGlobal::RowDataKZQ);
    //    QVector<RowDataKZQ> getCheckedRowDataLSSMs();

    //    RowDataKZQ getRowDataLSSM(const int rowNum);

    void setParaNames(const QStringList& value);

    QStringList getParaNames(double value, char f, int prsc) const;

    QStringList getParaNames() const;
    int getRowCount();
    int getBlueColumn() const;

signals:
    void sigDelItemClicked(const int rowIndex);

public:
    bool addStatus = false;
    bool editStatus = false;
    bool delStatus = false;

private slots:
    void ViewDetailsBtnClicked();
    void selectAllItems(Qt::CheckState state);
    void checkCurrRowSlot(int rowIndex, bool checked);

protected:
    void mouseDoubleClickEvent(QMouseEvent* event);

private:
    QString parseDoubleToStr(double value, char f = 'f', int prsc = 2);

private:
    Ui::CommonParameterTableView* ui;

    QStandardItemModel* tableModel;
    QStringList headNames;
    //    QVector<QList<QStandardItem*>> rowDatas;
    QList<int> removeRowIndexs;
    QStringList paraNames;
    NotEditableDelegate* notEditableDelegate;
    HeaderView* headerView;
    int blueColumn;
    QStandardItem* itemLastSelected = nullptr;
    QTimer* startMeasureTimer;
    bool firstUpdate = true;
    QVector<double> columnWidths;
    double m_scale = 0.0;
    double totleColumnWidth = 0.0;

private:
    void initMember();
    void destroyMember();
    void initView();
    void resizeEvent(QResizeEvent* event);
private slots:
    bool eventFilter(QObject*, QEvent*) override;
};

#endif  // CommonParameterTableView_H
