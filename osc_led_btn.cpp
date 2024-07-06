#include "osc_led_btn.h"

OSC_LED_Btn::OSC_LED_Btn(QString patern, QString LEDPatern, QOscInterface *ifaces, QObject *parent)
    : QObject{parent}
{
    this->Patern = patern;
    this->iface = ifaces;
    this->LEDPatern = LEDPatern;
}

void OSC_LED_Btn::set_state(QString patern, int state){
    m.lock();
   // qDebug() << patern;
    if(this->LEDPatern == patern){
        this->LEDState = state;
    }
    m.unlock();
}
