#ifndef CARRAYMODEL_H
#define CARRAYMODEL_H
#include <QAbstractItemModel>
#include <QItemDelegate>
#include <QObject>
#include <QStyledItemDelegate>
#include <QThread>
#include <QtWidgets/QWidget>
#include <vector>
struct ImagerData
{
    QString taskNum;         //任务编号
    QString outputTime;      //输出时间
    QString fileName;        //文件名称
    QString LocalFilePath;   //本地文件路径
    QString outputFilePath;  //输出文件路径
    QString sendDirection;   //传输方向
    QString sendType;        //传输方式
    QString accuracy;        //精度
    QString outputType;      //输出类型
    QString fileSize;        //文件大小
};

using ImagerDataList = QList<ImagerData>;
class CArrayModel : public QAbstractTableModel
{
    enum Cloumn
    {
        taskNum,         // 任务编号
        outputTime,      // 输出时间
        fileName,        // 文件名称
        LocalFilePath,   // 本地文件路径
        outputFilePath,  // 输出文件路径
        sendDirection,   // 传输方向
        sendType,        // 传输方式
        accuracy,        // 精度
        outputType,      // 输出类型
        fileSize         // 文件大小
    };
    //    Q_OBJECT
public:
    CArrayModel(QObject* parent = 0);
    //设置总数据
    void SetArrayData(const QList<ImagerData>& Datas);

    //获得总数据
    QList<ImagerData> GetArrayData() const;
    void setImagerData(const QList<ImagerData>& Datas);
    //设置页数据
    void SetCurPage(int iPage);
    //获得当前页
    int GetCurPage();
    //获得总页数
    int GetPageCount();
    //设置每页数据条数
    void SetPageSize(int iPageSize);
    //获得每页数据条数
    int GetPageSize();

    //总行数
    int RowCount() const;

public:
    int rowCount(const QModelIndex& parent) const;
    int columnCount(const QModelIndex& parent) const;
    QVariant data(const QModelIndex& index, int role) const;
    Qt::ItemFlags flags(const QModelIndex& index) const;
    //    bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole);
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    void refrushModel();

private:
    QString currencyAt(int offset) const;
    QList<ImagerData> m_mpData;      //总数据
                                     //    std::map<int, QString> m_mpData;
    QList<ImagerData> m_mpPageData;  //每页数据
    int m_iPageSize;                 //每页数据条数
    int m_iCurPage;                  //当前页
                                     //    ImagerDataList status_list_;
    QStringList mHeaders;
    QThread status_thread_;
};
//值列
class ValueDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    ValueDelegate(QObject* parent = 0)
        : QItemDelegate(parent)
    {
    }
    QWidget* createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const;
    void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const;
    void setEditorData(QWidget* editor, const QModelIndex& index) const;
    void setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const;
    void updateEditorGeometry(QWidget* editor, const QStyleOptionViewItem& option, const QModelIndex& index) const;
};
//只读委托(给索引列使用)
class ReadOnlyDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    ReadOnlyDelegate(QObject* parent = 0)
        : QItemDelegate(parent)
    {
    }
    QWidget* createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const { return NULL; }
};
#endif  // CARRAYMODEL_H
