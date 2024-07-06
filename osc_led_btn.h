#ifndef OSC_LED_BTN_H
#define OSC_LED_BTN_H

#include <QObject>
#include <QMutex>
#include "QOscmaster/inc/qosc.h"

class OSC_LED_Btn : public QObject
{
    Q_OBJECT
public:
    explicit OSC_LED_Btn(QString patern, QString LEDPatern, QOscInterface *iface, QObject *parent = nullptr);

    void set_state(QString patern, int state);

public slots:
    //void onRecieve(QOscMessage);

private:
    QMutex m;
    QString Patern;
    QString LEDPatern;
    int LEDState;
    QOscInterface *iface;
signals:

};

#endif // OSC_LED_BTN_H
