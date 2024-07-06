#ifndef OSC_BUTTON_H
#define OSC_BUTTON_H

#include <QObject>
#include <QMutex>
#include <QThread>
#include "osc_common.h"
#include "osc_interface.h"
#include <QMessageBox>

class OSC_Button : public QObject
{
    Q_OBJECT
public:
    explicit OSC_Button(OSC_Common::btns btn, QString patern, QString CheckPatern, bool isCommandLine, bool isLed,OSC_Common *common, OSC_Interface *iface, QObject *parent = nullptr);
    bool Press(); // returns new tickdelay
    void SetLed(QString patern, int value);
    void SetCommandLine(QString commandline);

     OSC_Common::btns button;
        QString patern;
private:
     QMutex m;
    OSC_Common *common;
    OSC_Interface *iface;

    QString CheckPatern;
    bool isCommandline;
    bool isLed;
    int LEDState;
    QString commandline;

    bool wait_commandline();
    bool wait_LedState();
    bool commandline_changed;


signals:

};

#endif // OSC_BUTTON_H
