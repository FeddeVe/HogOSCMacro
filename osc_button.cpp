#include "osc_button.h"

OSC_Button::OSC_Button(OSC_Common::btns btn, QString patern, QString CheckPatern, bool isCommandLine, bool isLed, OSC_Common *common, OSC_Interface *iface, QObject *parent)
    : QObject{parent}
{
    this->common = common;
    this->button = btn;
    this->patern = patern;
    this->CheckPatern = CheckPatern;
    this->isCommandline = isCommandLine;
    this->isLed = isLed;
    this->iface = iface;
    this->LEDState = 0;
}

bool OSC_Button::Press(){
    bool ok = false;
    int timeout = 0;
   // while(ok == false){
        if(this->button == OSC_Common::ENTER){
            this->commandline_changed = false;
        }
        //QOscMessage msgon(this->patern, 1);
        //iface->send(msgon);
        this->iface->Send(this->patern, 1);
        QThread::msleep(this->common->TickDelay);
        if(this->button == OSC_Common::ENTER){
             QThread::msleep(this->common->TickDelay*2);
        }
        //QOscMessage msgoff(this->patern, 0);
        //iface->send(msgoff);
        this->iface->Send(this->patern, 0);
        QThread::msleep(this->common->TickDelay);
        if(this->button == OSC_Common::ENTER){
            QThread::msleep(this->common->TickDelay*4);
        }
        if(this->isCommandline){
            if(this->wait_commandline()){
                return true;
            }
        }else if(this->isLed){
            if(this->wait_LedState()){
            return true;
            }
        }else{
            ok = true;
            return true;
        }
   // }
        return false;
}

bool OSC_Button::wait_commandline(){
    int timeout = 0;
    bool ret = false;
    while(ret == false){
         QThread::msleep(1);
        m.lock();
        if(this->CheckPatern == ""){
            if(this->commandline == ""){
                m.unlock();
                qDebug() << "Commandline TimeOut: " << timeout;
                return true;
            }
        }else if(this->CheckPatern == "ENTER"){
            if(this->commandline_changed){
                m.unlock();
                qDebug() << "Commandline TimeOut: " << timeout;
                return true;
            }

        }else{
            //remove last space;

            int r = this->CheckPatern.size();
            if(this->commandline.size() >= r){
                if(this->commandline[this->commandline.size()-1] == ' '){
                    this->commandline.removeLast();
                }
            QString check = this->commandline.last(r);
           // QString check = "";
            if(check == this->CheckPatern){
                m.unlock();
                    qDebug() << "Commandline TimeOut: " << timeout;
                return true;
            }
            }
        }
        timeout++;
        if(timeout > 1000){
            m.unlock();
            return false;
        }
        m.unlock();

    }
}

bool OSC_Button::wait_LedState(){
    int timeout = 0;
    bool ret = false;
    while(ret == false){
        QThread::msleep(1);
        m.lock();
        if(this->LEDState == 1){
            m.unlock();
            return true;
        }
        if((this->LEDState == 0) && (this->button == OSC_Common::CLEAR)){
            m.unlock();
            return true;
        }
        timeout++;
        if(timeout > 1000){
            m.unlock();
            return false;
        }
        m.unlock();
        //QThread::msleep(1);
    }
}

void OSC_Button::SetLed(QString patern, int value){
 //   m.lock();
    if(this->CheckPatern == patern){
        this->LEDState = value;
    }
 //      m.unlock();
}
void OSC_Button::SetCommandLine(QString commandline){
    m.lock();
    if(this->commandline != commandline){
        this->commandline_changed = true;
    }
    this->commandline = commandline;
    m.unlock();
}
