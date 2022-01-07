#ifndef CommonParameterDetailTable_H
#define CommonParameterDetailTable_H

#include <QDateTime>
#include <QStandardItemModel>
#include <QTimer>
#include <QWidget>
class QStandardItemModel;
typedef struct CommonParameterDetail
{
    QString parameterName;
    QString chineseName;
    QVariant value;
} CommonParameterDetail;

namespace Ui
{
    class CommonParameterDetailTable;
}

class CommonParameterDetailTable : public QWidget
{
    Q_OBJECT

public:
    explicit CommonParameterDetailTable(QWidget* parent = nullptr, int blueColumn = -1, QStringList headNames = QStringList());
    ~CommonParameterDetailTable();

    void appendRowData(CommonParameterDetail value);
    void updateRowData(QList<CommonParameterDetail>& values);
    void insertRowData(const CommonParameterDetail& values, int rowIndex);

private:
    void initMember();
    void destroyMember();
    void initView();

protected:
    void mouseDoubleClickEvent(QMouseEvent* event);

private:
    QString parseDoubleToStr(double value, char f = 'f', int prsc = 2);

private:
    Ui::CommonParameterDetailTable* ui;

    QStandardItemModel* tableModel;
    QStringList headNames;
    int blueColumn;
};

#endif  // CommonParameterDetailTable_H
