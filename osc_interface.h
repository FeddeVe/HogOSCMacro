#ifndef OSC_INTERFACE_H
#define OSC_INTERFACE_H

#include <QObject>
#include <QUdpSocket>



enum byteOrder{
    ABCD,
    BADC,
    CDAB,
    DCBA
};






struct osc_bundle{
    QString bundle;
};

class OSC_Interface : public QObject
{
    Q_OBJECT
public:
    explicit OSC_Interface(QObject *parent = nullptr);

    void Connect(QString IP, int hostport, int myport);
    QHostAddress host;
    int hostport;

    struct osc_message{
        QString address;
        QString type;
        float FloatVal = 0;
        bool isFloat = false;
        bool LEDON = false;
        QString str_Val;
    };

    void Send(QString address, int value);

private:

    QUdpSocket *Sendsocket;
    QUdpSocket *RecieveSocket;
    float toFloat( quint16 ab, quint16 cd, byteOrder order);


public slots:
    void ReadyReadSend();
    void ReadyReadRecieve();

signals:
    void MessageRecieved(osc_message message);


};

#endif // OSC_INTERFACE_H
