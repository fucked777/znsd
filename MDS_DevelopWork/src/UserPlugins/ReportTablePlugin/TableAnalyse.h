#ifndef TableAnalyse_H
#define TableAnalyse_H
#include "FaultMsgPage.h"
#include <QString>

using namespace NSGlobal;

class TableAnalyse
{
public:
    TableAnalyse(const QString& fileName);

    void add(RowDataFaultMsg data);
    void adds(QVector<RowDataFaultMsg> datas);
    void dels(QVector<RowDataFaultMsg> datas);
    QVector<RowDataFaultMsg> query();

private:
    bool unite(QVector<RowDataFaultMsg>& dstData, RowDataFaultMsg& srcData);
    bool remove(QVector<RowDataFaultMsg>& dstData, RowDataFaultMsg& srcData);
    bool save(QVector<RowDataFaultMsg>& dstData);

    QVector<RowDataFaultMsg> load();

private:
    QString fileName;
};

#endif  // TableAnalyse_H
