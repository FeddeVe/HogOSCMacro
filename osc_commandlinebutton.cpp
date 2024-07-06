#include "osc_commandlinebutton.h"

OSC_CommandLineButton::OSC_CommandLineButton(QString Patern, QString CommandLineExpect, QOscInterface *iface, QObject *parent)
    : QObject{parent}
{
    this->ButtonCommand = Patern;


}
