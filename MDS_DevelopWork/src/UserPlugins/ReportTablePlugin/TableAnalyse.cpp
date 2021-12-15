#include "TableAnalyse.h"
#include <QFile>
#include <QTextStream>
TableAnalyse::TableAnalyse(const QString& fileName)
    : fileName(fileName)
{
}

void TableAnalyse::add(RowDataFaultMsg data)
{
    QVector<RowDataFaultMsg> ans;
    ans = load();
    unite(ans, data);
    save(ans);
}

void TableAnalyse::adds(QVector<RowDataFaultMsg> datas)
{
    QVector<RowDataFaultMsg> ans;
    ans = load();
    for (auto& data : datas)
    {
        unite(ans, data);
    }
    save(ans);
}

void TableAnalyse::dels(QVector<RowDataFaultMsg> datas)
{
    QVector<RowDataFaultMsg> ans;
    ans = load();

    for (auto& d : datas)
    {
        remove(ans, d);
    }
    save(ans);
}

QVector<RowDataFaultMsg> TableAnalyse::query() { return load(); }

bool TableAnalyse::unite(QVector<RowDataFaultMsg>& dstData, RowDataFaultMsg& srcData)
{
    for (int i = 0; i < dstData.size(); i++)
    {
        RowDataFaultMsg d = dstData[i];
        if (srcData > d)
        {
            continue;
        }
        //        else if (srcData == d)
        //        {
        //            return false;
        //        }
        else
        {
            if (i)
            {
                dstData.insert(i, srcData);
            }
            else
            {
                dstData.push_back(srcData);
            }
            return true;
        }
    }

    dstData.push_back(srcData);
    return true;
}

bool TableAnalyse::remove(QVector<RowDataFaultMsg>& dstData, RowDataFaultMsg& srcData)
{
    for (int i = 0; i < dstData.size(); i++)
    {
        RowDataFaultMsg d = dstData[i];
        if (d == srcData)
        {
            dstData.removeAt(i);
            return true;
        }
    }
    return false;
}

bool TableAnalyse::save(QVector<RowDataFaultMsg>& dstData)
{
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate))
    {
        return false;
    }

    QTextStream out(&file);
    out << QString("//故障等级@日期@任务编号@故障代码@分系统名@处理状态@故障信息@内部故障@备注\n");
    for (auto& d : dstData)
    {
        out << QString(d.faultLevel) << NSGlobal::SEPARATOR << QString(d.dateTime) << NSGlobal::SEPARATOR << QString(d.taskNum) << NSGlobal::SEPARATOR
            << QString(d.faultCode) << NSGlobal::SEPARATOR << QString(d.systemName) << NSGlobal::SEPARATOR << QString(d.dealStatus)
            << NSGlobal::SEPARATOR << QString(d.faultInfor) << NSGlobal::SEPARATOR << QString(d.internalFault) << NSGlobal::SEPARATOR
            << QString(d.remarks) << "\n";
    }
    out.flush();
    file.close();
    return true;
}

QVector<RowDataFaultMsg> TableAnalyse::load()
{
    QVector<RowDataFaultMsg> datas;

    QFile file(fileName);
    if (!file.exists())
    {
        file.open(QIODevice::NewOnly);
        return datas;
    }
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return datas;
    }

    QTextStream in(&file);
    while (!in.atEnd())
    {
        QString text = in.readLine().trimmed();
        if (text.startsWith("//") || text.isEmpty())
            continue;
        if (text.split(NSGlobal::SEPARATOR).size() == 9)
        {
            RowDataFaultMsg data;
            QStringList strList = text.split(NSGlobal::SEPARATOR);
            data.faultLevel = strList.at(0);
            data.dateTime = strList.at(1);
            data.taskNum = strList.at(2);
            data.faultCode = strList.at(3);
            data.systemName = strList.at(4);
            data.dealStatus = strList.at(5);
            data.faultInfor = strList.at(6);
            data.internalFault = strList.at(7);
            data.remarks = strList.at(8);
            datas.push_back(data);
        }
    }

    file.close();
    return datas;
}
