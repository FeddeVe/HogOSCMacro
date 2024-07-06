#include "myosc.h"

MyOSC::MyOSC(QObject *parent)
    : QObject{parent}
{
    this->osc_interface = new OSC_Interface(this);
    connect(this->osc_interface, SIGNAL(MessageRecieved(OSC_Interface::osc_message)), this, SLOT(dispatchMessage(OSC_Interface::osc_message)), Qt::DirectConnection);
   // connect(iface, SIGNAL(messageReceived(const QOscMessage&)),this, SLOT(dispatchMessage(const QOscMessage&)), Qt::DirectConnection);
   // connect(iface, SIGNAL(bundleReceived(const QOscBundle&)),this, SLOT(dispatchBundle(const QOscBundle&)), Qt::DirectConnection);
    this->common = new OSC_Common();
    this->LoadButtons();
    this->Work();
}

void MyOSC::Connect(QString IP, int hostport, int myport){
  //  iface->setRemoteAddr(IP);
  //  iface->setRemotePort(hostport);
  //  iface->setLocalPort(myport);
    this->osc_interface->Connect(IP, hostport, myport);
}

void MyOSC::dispatchMessage(OSC_Interface::osc_message message){
    if(message.address == "/hog/status/commandline"){
        qDebug()<< message.str_Val;
        for(int i = 0; i < this->buttons.size(); i++){
            this->buttons[i]->SetCommandLine(message.str_Val);
        }
    }else{
        for(int i = 0; i < this->buttons.size(); i++){
            this->buttons[i]->SetLed(message.address, message.LEDON);
        }
    }
}

/*
void MyOSC::dispatchMessage(const QOscMessage& msg){
    int bp = 0;
    bp++;
    QString addr = msg.pattern();
    for(auto& arg : msg)
    {
        if(arg.isFloat()){
            float ix = arg.toFloat();
            for(int i = 0; i < this->buttons.size(); i++){
                this->buttons[i]->SetLed(addr, ix);
            }
        }else if(arg.isString()){
            if(addr == "/hog/status/commandline"){
                QString commandline = arg.toString();
               // qDebug()<< commandline;
                for(int i = 0; i < this->buttons.size(); i++){
                    this->buttons[i]->SetCommandLine(commandline);
                }
               // emit this->PublishCommandline(commandline);
                int bp= 0;
                bp++;
            }
        }else{
            int bp =0;
            bp++;
        }
        // do stuff with i

        //Q_UNUSED(i);
    }
    int bp2 =0;
    bp2++;
}

void MyOSC::dispatchBundle(const QOscBundle& msg){
    if(msg.isValid()){
        for(int i = 0; i < msg.size(); i++){
            QOscMessage m = msg[i];
            QString addr = m.pattern();
            for(auto& arg : m)
            {
                if(arg.isFloat()){
                    float ix = arg.toFloat();
                    for(int i = 0; i < this->buttons.size(); i++){
                        this->buttons[i]->SetLed(addr, ix);
                    }
                }else if(arg.isString()){
                    if(addr == "/hog/status/commandline"){
                        QString commandline = arg.toString();
                        qDebug()<< commandline;
                        for(int i = 0; i < this->buttons.size(); i++){
                            this->buttons[i]->SetCommandLine(commandline);
                        }
                        emit this->PublishCommandline(commandline);
                        int bp= 0;
                        bp++;
                    }
                }else{
                    int bp =0;
                    bp++;
                }
                // do stuff with i

                //Q_UNUSED(i);
            }
            if(m.value(0).isFloat()){
                float i;
                m.value(0).toInt(i);
                int bp = 0;
                bp++;

            }
            int bp =0;
            bp++;
        }
    }

    int bp = 0;
    bp++;
}
*/


void MyOSC::Press(OSC_Common::btns button){
    for(int i = 0; i < this->buttons.size(); i++){
        if(this->buttons[i]->button == button){
            emit this->PublishLog( this->buttons[i]->patern);
            if(!this->buttons[i]->Press()){
                this->common->inc_tickDelay();
                int index = this->Fallback.size();
                while(index > 0){
                    index = index - 1;
                    this->Quee.insert(0, this->Fallback[index]);
                }
                this->Quee.insert(0, OSC_Common::CLEAR);
                this->Quee.insert(0, OSC_Common::CLEAR);
                this->Quee.insert(0, OSC_Common::CLEAR);
                this->Fallback.clear();

            }else{
             //   this->common->dec_tickDelay();
            }
            break;
        }
    }
}

void MyOSC::Test(int faderpos){
   // QOscMessage msg("/hog/hardware/fader/1", faderpos);
   // iface->send(msg);
    this->add_Quee(OSC_Common::CHOOSE1);
    this->add_Quee(OSC_Common::CHOOSE2);
    this->add_Quee(OSC_Common::CHOOSE3);
    this->add_Quee(OSC_Common::CHOOSE4);
    this->add_Quee(OSC_Common::CHOOSE5);
    this->add_Quee(OSC_Common::CHOOSE6);
    this->add_Quee(OSC_Common::CHOOSE7);
    this->add_Quee(OSC_Common::CHOOSE8);
    this->add_Quee(OSC_Common::CHOOSE9);
    this->add_Quee(OSC_Common::CHOOSE10);
   // this->Press(OSC_Common::CHOOSE1);
}

void MyOSC::Pauze(bool Pauze){

}

void MyOSC::add_Quee(OSC_Common::btns button){
    m.lock();
    this->Quee.push_back(button);
    m.unlock();
}

void MyOSC::Work(){
    QThread *thread = QThread::create([this]{
        while(1){
            this->last_report = -1;
            m.lock();
            while(this->Quee.size() > 0){
                if(this->Quee[0] == OSC_Common::TOTAL_BUTTONS){
                    int bp = 0;
                    bp++;
                }
                if(this->Quee[0] == OSC_Common::FALL_BACK){
                    this->Fallback.clear();
                    this->Quee.erase(this->Quee.begin());
                    this->ReportProgress(this->Quee.size());
                    QThread::msleep(common->TickDelay);
                }else if(this->Quee[0] == OSC_Common::PAGE_0_COMPLETE){
                    emit this->PageComplete(0);
                    QThread::sleep(1);
                    this->Quee.erase(this->Quee.begin());
                    this->ReportProgress(this->Quee.size());
                }else if(this->Quee[0] == OSC_Common::PAGE_1_COMPLETE){
                    emit this->PageComplete(1);
                    QThread::sleep(1);
                    this->Quee.erase(this->Quee.begin());
                    this->ReportProgress(this->Quee.size());
                }else if(this->Quee[0] == OSC_Common::PAGE_2_COMPLETE){
                    emit this->PageComplete(2);
                    QThread::sleep(1);
                    this->Quee.erase(this->Quee.begin());
                    this->ReportProgress(this->Quee.size());
                }else if(this->Quee[0] == OSC_Common::PAGE_3_COMPLETE){
                    emit this->PageComplete(3);
                    QThread::sleep(1);
                    this->Quee.erase(this->Quee.begin());
                    this->ReportProgress(this->Quee.size());
                }else if(this->Quee[0] == OSC_Common::PAGE_4_COMPLETE){
                    emit this->PageComplete(4);
                    QThread::sleep(1);
                    this->Quee.erase(this->Quee.begin());
                    this->ReportProgress(this->Quee.size());
                }else if(this->Quee[0] == OSC_Common::PAGE_5_COMPLETE){
                    emit this->PageComplete(5);
                    QThread::sleep(1);
                    this->Quee.erase(this->Quee.begin());
                    this->ReportProgress(this->Quee.size());
                }else if(this->Quee[0] == OSC_Common::PAGE_6_COMPLETE){
                    emit this->PageComplete(6);
                    QThread::sleep(1);
                    this->Quee.erase(this->Quee.begin());
                    this->ReportProgress(this->Quee.size());
                }else if(this->Quee[0] == OSC_Common::PAGE_7_COMPLETE){
                    emit this->PageComplete(7);
                    QThread::sleep(1);
                    this->Quee.erase(this->Quee.begin());
                    this->ReportProgress(this->Quee.size());
                }else if(this->Quee[0] == OSC_Common::PAGE_8_COMPLETE){
                    emit this->PageComplete(8);
                    QThread::sleep(1);
                    this->Quee.erase(this->Quee.begin());
                    this->ReportProgress(this->Quee.size());
                }else if(this->Quee[0] == OSC_Common::PAGE_9_COMPLETE){
                    emit this->PageComplete(9);
                    QThread::sleep(1);
                    this->Quee.erase(this->Quee.begin());
                    this->ReportProgress(this->Quee.size());
                }else if(this->Quee[0] == OSC_Common::PAGE_10_COMPLETE){
                    emit this->PageComplete(10);
                    QThread::sleep(1);
                    this->Quee.erase(this->Quee.begin());
                    this->ReportProgress(this->Quee.size());
                }else{
                    this->Fallback.push_back(this->Quee[0]);
                    this->Press(this->Quee[0]);
                    this->Quee.erase(this->Quee.begin());
                            this->ReportProgress(this->Quee.size());
                }
            }
            m.unlock();
            this->ReportProgress(this->Quee.size());
            QThread::sleep(1);
        }
    });
    thread->start();
}

void MyOSC::LoadButtons(){
    for(int i = 0; i < OSC_Common::TOTAL_BUTTONS; i++){
        switch(i){
            case OSC_Common::CHOOSE1:
            {
            OSC_Button *btn = new OSC_Button(OSC_Common::CHOOSE1, "/hog/hardware/choose/"+ QString::number(1), "/hog/status/led/choose/1", false,true,this->common, this->osc_interface);
            this->buttons.push_back(btn);
            }
            break;
            case OSC_Common::CHOOSE2:
            {
            OSC_Button *btn = new OSC_Button(OSC_Common::CHOOSE2, "/hog/hardware/choose/"+ QString::number(2), "/hog/status/led/choose/2", false,true,this->common, this->osc_interface);
            this->buttons.push_back(btn);
            }
            break;
            case OSC_Common::CHOOSE3:
            {
            OSC_Button *btn = new OSC_Button(OSC_Common::CHOOSE3, "/hog/hardware/choose/"+ QString::number(3), "/hog/status/led/choose/3", false,true,this->common, this->osc_interface);
            this->buttons.push_back(btn);
            }
            break;
            case OSC_Common::CHOOSE4:
            {
            OSC_Button *btn = new OSC_Button(OSC_Common::CHOOSE4, "/hog/hardware/choose/"+ QString::number(4), "/hog/status/led/choose/4", false,true,this->common, this->osc_interface);
            this->buttons.push_back(btn);
            }
            break;
            case OSC_Common::CHOOSE5:
            {
            OSC_Button *btn = new OSC_Button(OSC_Common::CHOOSE5, "/hog/hardware/choose/"+ QString::number(5), "/hog/status/led/choose/5", false,true,this->common, this->osc_interface);
            this->buttons.push_back(btn);
            }
            break;
            case OSC_Common::CHOOSE6:
            {
            OSC_Button *btn = new OSC_Button(OSC_Common::CHOOSE6, "/hog/hardware/choose/"+ QString::number(6), "/hog/status/led/choose/6", false,true,this->common, this->osc_interface);
            this->buttons.push_back(btn);
            }
            break;
            case OSC_Common::CHOOSE7:
            {
            OSC_Button *btn = new OSC_Button(OSC_Common::CHOOSE7, "/hog/hardware/choose/"+ QString::number(7), "/hog/status/led/choose/7", false,true,this->common, this->osc_interface);
            this->buttons.push_back(btn);
            }
            break;
            case OSC_Common::CHOOSE8:
            {
            OSC_Button *btn = new OSC_Button(OSC_Common::CHOOSE8, "/hog/hardware/choose/"+ QString::number(8), "/hog/status/led/choose/8", false,true,this->common, this->osc_interface);
            this->buttons.push_back(btn);
            }
            break;
            case OSC_Common::CHOOSE9:
            {
            OSC_Button *btn = new OSC_Button(OSC_Common::CHOOSE9, "/hog/hardware/choose/"+ QString::number(9), "/hog/status/led/choose/9", false,true,this->common, this->osc_interface);
            this->buttons.push_back(btn);
            }
            break;
            case OSC_Common::CHOOSE10:
            {
            OSC_Button *btn = new OSC_Button(OSC_Common::CHOOSE10, "/hog/hardware/choose/"+ QString::number(10), "/hog/status/led/choose/10", false,true,this->common, this->osc_interface);
            this->buttons.push_back(btn);
            }
            break;
            case OSC_Common::CUE:
            {
            OSC_Button *btn = new OSC_Button(OSC_Common::CUE, "/hog/hardware/cue", "Cue", true,false,this->common, this->osc_interface);
            this->buttons.push_back(btn);
            }
            break;
            case OSC_Common::LIST:
            {
            OSC_Button *btn = new OSC_Button(OSC_Common::LIST, "/hog/hardware/list", "List", true,false,this->common, this->osc_interface);
            this->buttons.push_back(btn);
            }
            break;
            case OSC_Common::PAGE:
            {
            OSC_Button *btn = new OSC_Button(OSC_Common::PAGE, "/hog/hardware/page", "Page", true,false,this->common, this->osc_interface);
            this->buttons.push_back(btn);
            }
            break;
            case OSC_Common::RECORD:
            {
            OSC_Button *btn = new OSC_Button(OSC_Common::RECORD, "/hog/hardware/record", "Record", true,false,this->common, this->osc_interface);
            this->buttons.push_back(btn);
            }
            break;
            case OSC_Common::INTENSITY:
            {
            OSC_Button *btn = new OSC_Button(OSC_Common::INTENSITY, "/hog/hardware/intensity", "Intensity", true,false,this->common, this->osc_interface);
            this->buttons.push_back(btn);
            }
            break;
            case OSC_Common::COLOUR:
            {
            OSC_Button *btn = new OSC_Button(OSC_Common::COLOUR, "/hog/hardware/colour", "Colour", true,false,this->common, this->osc_interface);
            this->buttons.push_back(btn);
            }
            break;
            case OSC_Common::POSITION:
            {
            OSC_Button *btn = new OSC_Button(OSC_Common::POSITION, "/hog/hardware/position", "Position", true,false,this->common, this->osc_interface);
            this->buttons.push_back(btn);
            }
            break;
            case OSC_Common::BEAM:
            {
            OSC_Button *btn = new OSC_Button(OSC_Common::BEAM, "/hog/hardware/beam", "Beam", true,false,this->common, this->osc_interface);
            this->buttons.push_back(btn);
            }
            break;
            case OSC_Common::EFFECT:
            {
            OSC_Button *btn = new OSC_Button(OSC_Common::EFFECT, "/hog/hardware/effect", "Effect", true,false,this->common, this->osc_interface);
            this->buttons.push_back(btn);
            }
            break;
            case OSC_Common::TIME:
            {
            OSC_Button *btn = new OSC_Button(OSC_Common::TIME, "/hog/hardware/time", "Time", true,false,this->common, this->osc_interface);
            this->buttons.push_back(btn);
            }
            break;
            case OSC_Common::GROUP:
            {
            OSC_Button *btn = new OSC_Button(OSC_Common::GROUP, "/hog/hardware/group", "Group", true,false,this->common, this->osc_interface);
            this->buttons.push_back(btn);
            }
            break;
            case OSC_Common::FIXTURE:
            {
            OSC_Button *btn = new OSC_Button(OSC_Common::FIXTURE, "/hog/hardware/fixture", "Fixture", true,false,this->common, this->osc_interface);
            this->buttons.push_back(btn);
            }
            break;
            case OSC_Common::ZERO:
            {
            OSC_Button *btn = new OSC_Button(OSC_Common::ZERO, "/hog/hardware/zero", "0", true,false,this->common, this->osc_interface);
            this->buttons.push_back(btn);
            }
            break;
            case OSC_Common::ONE:
            {
            OSC_Button *btn = new OSC_Button(OSC_Common::ONE, "/hog/hardware/one", "1", true,false,this->common, this->osc_interface);
            this->buttons.push_back(btn);
            }
            break;
            case OSC_Common::TWO:
            {
            OSC_Button *btn = new OSC_Button(OSC_Common::TWO, "/hog/hardware/two", "2", true,false,this->common, this->osc_interface);
            this->buttons.push_back(btn);
            }
            break;
            case OSC_Common::THREE:
            {
            OSC_Button *btn = new OSC_Button(OSC_Common::THREE, "/hog/hardware/three", "3", true,false,this->common, this->osc_interface);
            this->buttons.push_back(btn);
            }
            break;
            case OSC_Common::FOUR:
            {
            OSC_Button *btn = new OSC_Button(OSC_Common::FOUR, "/hog/hardware/four", "4", true,false,this->common, this->osc_interface);
            this->buttons.push_back(btn);
            }
            break;
            case OSC_Common::FIVE:
            {
            OSC_Button *btn = new OSC_Button(OSC_Common::FIVE, "/hog/hardware/five", "5", true,false,this->common, this->osc_interface);
            this->buttons.push_back(btn);
            }
            break;
            case OSC_Common::SIX:
            {
            OSC_Button *btn = new OSC_Button(OSC_Common::SIX, "/hog/hardware/six", "6", true,false,this->common, this->osc_interface);
            this->buttons.push_back(btn);
            }
            break;
            case OSC_Common::SEVEN:
            {
            OSC_Button *btn = new OSC_Button(OSC_Common::SEVEN, "/hog/hardware/seven", "7", true,false,this->common, this->osc_interface);
            this->buttons.push_back(btn);
            }
            break;
            case OSC_Common::EIGHT:
            {
            OSC_Button *btn = new OSC_Button(OSC_Common::EIGHT, "/hog/hardware/eight", "8", true,false,this->common, this->osc_interface);
            this->buttons.push_back(btn);
            }
            break;
            case OSC_Common::NINE:
            {
            OSC_Button *btn = new OSC_Button(OSC_Common::NINE, "/hog/hardware/nine", "9", true,false,this->common, this->osc_interface);
            this->buttons.push_back(btn);
            }
            break;
            case OSC_Common::DOT:
            {
            OSC_Button *btn = new OSC_Button(OSC_Common::DOT, "/hog/hardware/period", ".", true,false,this->common, this->osc_interface);
            this->buttons.push_back(btn);
            }
            break;
            case OSC_Common::ENTER:
            {
            OSC_Button *btn = new OSC_Button(OSC_Common::ENTER, "/hog/hardware/enter", "ENTER", true,false,this->common, this->osc_interface);
            this->buttons.push_back(btn);
            }
            break;
            case OSC_Common::CLEAR:
            {
            OSC_Button *btn = new OSC_Button(OSC_Common::CLEAR, "/hog/hardware/clear", "/hog/status/led/clear", false,true,this->common, this->osc_interface);
            this->buttons.push_back(btn);
            }
            break;
            case OSC_Common::A:
            {
                OSC_Button *btn = new OSC_Button(OSC_Common::CLEAR, "/hog/hardware/a", "/hog/status/led/clear", false,true,this->common, this->osc_interface);
                this->buttons.push_back(btn);
            }
            break;
            case OSC_Common::B:
            {
                OSC_Button *btn = new OSC_Button(OSC_Common::CLEAR, "/hog/hardware/b", "/hog/status/led/clear", false,true,this->common, this->osc_interface);
                this->buttons.push_back(btn);
            }
            break;
        }
    }
}
