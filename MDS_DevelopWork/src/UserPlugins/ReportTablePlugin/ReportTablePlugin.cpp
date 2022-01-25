#include "ReportTablePlugin.h"
#include <QDebug>
#include <QJsonDocument>

ReportTablePlugin::ReportTablePlugin() { load(); }

ReportTablePlugin::~ReportTablePlugin() { unload(); }

AbsDataDecoder* ReportTablePlugin::decoder() { return _decoder; }

AbsDataSender* ReportTablePlugin::sender() { return _sender; }

QString ReportTablePlugin::name() const { return TESTPLUGIN; }

unsigned int ReportTablePlugin::version() const { return Version(0, 0, 1); }

bool ReportTablePlugin::load()
{
    if (!_sender)
        _sender = new reportTableSender;
    if (!_decoder)
        _decoder = new reportTableDecoder;
    return true;
}

bool ReportTablePlugin::unload()
{
    if (_decoder)
    {
        delete _decoder;
    }

    if (_sender)
    {
        _sender->stop();
    }
    return true;
}

QString reportTableDecoder::createName() { return QString(TESTDEOCDER); }

HeaderStruct reportTableDecoder::decode(QByteArray& byte)
{
    HeaderStruct header;
    if (byte.startsWith(QByteArray("Json")))
    {
        QJsonObject obj = QJsonDocument::fromJson(byte.mid(4)).object();
        header[TESTSENDER] = (obj.toVariantMap());
    }
    else if (byte.startsWith("pix"))
    {
        QByteArray pix = byte.mid(3);

        QVariantMap m;
        m["pix"] = pix;
        header[TESTSENDER] = m;
    }
    return std::move(header);
}

AbsDataDecoder::CreateFunc reportTableDecoder::getCreateFunc() { return std::bind(&reportTableDecoder::create); }

AbsDataDecoder* reportTableDecoder::create() { return new reportTableDecoder; }

reportTableSender::reportTableSender()
    : QObject(0)
{
}

reportTableSender::~reportTableSender() {}

QString reportTableSender::senderName() const { return TESTSENDER; }

bool reportTableSender::sendData(const QVariantMap& obj)
{
    qDebug() << obj;
    auto iter = obj.constBegin();
    while (iter != obj.constEnd())
    {
        //        QString key = iter.key();
        //        if (key == "testText")
        //        {
        //            QString value = iter.value().toString();
        //            //            emit push_label(value);
        //        }
        //        if (key == "pix")
        //        {
        QByteArray bytes = iter.value().toByteArray();
        //            QPixmap pix;
        //            pix.loadFromData(bytes);
        emit sendByteArray(bytes);
        //        }
        ++iter;
    }
    return true;
}

void reportTableSender::stop() { this->deleteLater(); }
