#pragma once
#include "DataTransformPlugin/Plugin.h"
#include <QPixmap>
#include <QThread>
#include <QVariant>
#include <QWidget>
#define TESTDEOCDER "TestDecoder"
#define TESTSENDER  "TestSender"
#define TESTPLUGIN  "TestPlugin"

class ReportTablePlugin : public AbsPlugin
{
public:
    ReportTablePlugin();
    virtual ~ReportTablePlugin();

    virtual AbsDataDecoder* decoder();

    virtual AbsDataSender* sender();

    virtual QString name() const;

    virtual unsigned int version() const;

protected:
    virtual bool load();

    virtual bool unload();

private:
};

class reportTableDecoder : public AbsDataDecoder
{
public:
    virtual QString createName();

    virtual HeaderStruct decode(QByteArray& byte) override;

    virtual CreateFunc getCreateFunc();

    static AbsDataDecoder* create();
};

class reportTableSender : public QObject, public AbsDataSender
{
    Q_OBJECT
public:
    reportTableSender();

    virtual ~reportTableSender();

    virtual QString senderName() const;

    virtual bool sendData(const QVariantMap& obj);

    virtual void stop();
    // signals:
    //    void push_label(QString);
    //    void push_label(QPixmap);
};
