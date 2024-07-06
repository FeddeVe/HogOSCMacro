#include "osc_interface.h"

OSC_Interface::OSC_Interface(QObject *parent)
    : QObject{parent}
{
    this->Sendsocket = new QUdpSocket(this);
    this->RecieveSocket = new QUdpSocket(this);
    connect(this->Sendsocket, SIGNAL(readyRead()), this, SLOT(ReadyReadSend()), Qt::DirectConnection);
    connect(this->RecieveSocket, SIGNAL(readyRead()), this, SLOT(ReadyReadRecieve()), Qt::DirectConnection);
}

void OSC_Interface::Connect(QString IP, int hostport, int myport){
    this->RecieveSocket->bind(QHostAddress::Any, myport);
    QHostAddress address(IP);
    this->Sendsocket->bind(address, hostport);
    this->hostport = hostport;
    this->host = QHostAddress(IP);
}

void OSC_Interface::ReadyReadRecieve(){
    // when data comes in
    QByteArray buffer;
    buffer.resize(RecieveSocket->pendingDatagramSize());

    QHostAddress sender;
    quint16 senderPort;

    // qint64 QUdpSocket::readDatagram(char * data, qint64 maxSize,
    //                 QHostAddress * address = 0, quint16 * port = 0)
    // Receives a datagram no larger than maxSize bytes and stores it in data.
    // The sender's host address and port is stored in *address and *port
    // (unless the pointers are 0).

    RecieveSocket->readDatagram(buffer.data(), buffer.size(), &sender, &senderPort);
    osc_message osc_message;

    QString adress = "";
    int i = 0;
    while(i < buffer.size()){
        char buff[4];
        for(int y = 0; y < 4; y++){
            buff[y] = buffer[i+y];
        }
        if(buff[0] == ','){
            int bp = 0;
            bp++;
            osc_message.type = buff[1];

            if(osc_message.type == "s"){
                i = i + 4;
                while(buffer[i] != NULL){
                    osc_message.str_Val.push_back(buffer[i]);
                    i++;
                }
                break;

            }else if(osc_message.type == "f"){
                i = i + 4;
                for(int y = 0; y < 4; y++){
                    buff[y] = buffer[i+y];
                }
                memcpy(&osc_message.FloatVal, buff, 4);
                if(osc_message.FloatVal == 0){
                    osc_message.LEDON = false;
                }else{
                    osc_message.LEDON = true;
                }
                i = i + 4;
            }else{
                int bp = 0;
                bp++;
            }
            break;


        }else{
            osc_message.address.push_back(buff);
        }

        i = i + 4;
    }




    emit this->MessageRecieved(osc_message);
   // qDebug() << "Message from: " << sender.toString();
   // qDebug() << "Message port: " << senderPort;
   // qDebug() << "Message: " << buffer;
}

void OSC_Interface::ReadyReadSend(){
    // when data comes in
    QByteArray buffer;
    buffer.resize(Sendsocket->pendingDatagramSize());

    QHostAddress sender;
    quint16 senderPort;

    // qint64 QUdpSocket::readDatagram(char * data, qint64 maxSize,
    //                 QHostAddress * address = 0, quint16 * port = 0)
    // Receives a datagram no larger than maxSize bytes and stores it in data.
    // The sender's host address and port is stored in *address and *port
    // (unless the pointers are 0).

    Sendsocket->readDatagram(buffer.data(), buffer.size(), &sender, &senderPort);

    qDebug() << "Message from: " << sender.toString();
    qDebug() << "Message port: " << senderPort;
    qDebug() << "Message: " << buffer;
}

float OSC_Interface::toFloat( quint16 ab, quint16 cd, byteOrder order)
{
    short A(0),B(0),C(0),D(0);
    switch (order) {
    case ABCD:A = 0; B = 1; C = 2; D = 3;break;
    case BADC:A = 1; B = 0; C = 3; D = 2;break;
    case CDAB:A = 2; B = 3; C = 0; D = 1;break;
    case DCBA:A = 3; B = 2; C = 1; D = 0;break;
    }

    float f(0);
    auto *cArray = reinterpret_cast<unsigned char *>(&f);
    cArray[A] =  ab &0xFF;
    cArray[B] = (ab >> 8) & 0xFF;
    cArray[C] =  cd &0xFF;
    cArray[D] = (cd >> 8) & 0xFF;

    return f;
}

void OSC_Interface::Send(QString address, int value){

    std::string tmp = address.toStdString();
    QVector<char> send_buf;
    int index = 0;
    while(index < address.size()){
        for(int i = index; i < index + 4; i++){
            if(i >= address.size()){
                send_buf.push_back(0);
            }else{
                send_buf.push_back(tmp[i]);
            }
        }
        index = index + 4;
        if(index == address.size()){
            send_buf.push_back(0);
            send_buf.push_back(0);
            send_buf.push_back(0);
            send_buf.push_back(0);
        }

    }
    send_buf.push_back(',');
    send_buf.push_back('i');
    send_buf.push_back(0);
    send_buf.push_back(0);

    send_buf.push_back(0);
    send_buf.push_back(0);
    send_buf.push_back(0);
    send_buf.push_back(value);



    this->Sendsocket->writeDatagram(send_buf.data(),send_buf.size(), this->host, this->hostport);
    this->Sendsocket->waitForBytesWritten();
}
