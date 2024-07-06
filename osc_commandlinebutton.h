#ifndef OSC_COMMANDLINEBUTTON_H
#define OSC_COMMANDLINEBUTTON_H

#include <QObject>
#include "QOscmaster/inc/qosc.h"

class OSC_CommandLineButton : public QObject
{
    Q_OBJECT
public:
    explicit OSC_CommandLineButton(QString Patern, QString CommandLineExpect, QOscInterface *iface, QObject *parent = nullptr);




private:
    QOscInterface *iface;
    QString ButtonCommand;
    QString CommandLineVerwacht;
    bool CommandLineRecieved;
signals:

};

#endif // OSC_COMMANDLINEBUTTON_H
