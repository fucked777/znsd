#ifndef CommonParameterTableView_H
#define CommonParameterTableView_H

#include <QDateTime>
#include <QStandardItemModel>
#include <QWidget>
class QStandardItemModel;
typedef struct CommonParameterTable
{
    QString fileType;
    QString fileName;
    QString getTime;
    QString useTime;
} CommonParameter;
using CommonParameterDataList = QList<CommonParameter>;
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

    void initMember();
    void destroyMember();
    void initView();

private:
    void appendRowData(CommonParameter value);
    void updateRowData(QList<CommonParameter>& values);
    void insertRowData(const CommonParameter& values, int rowIndex);
    QString parseDoubleToStr(double value, char f = 'f', int prsc = 2);

public slots:
    void ViewDetailsBtnClicked();
signals:
    void dataSendSignal(const QStringList& data);

protected:
    void mouseDoubleClickEvent(QMouseEvent* event);

private:
    Ui::CommonParameterTableView* ui;
    QStandardItemModel* tableModel;
    QStringList headNames;
    QStringList paraNames;
    int blueColumn;
};

#endif  // CommonParameterTableView_H
