#include "osc_common.h"

OSC_Common::OSC_Common(QObject *parent)
    : QObject{parent}
{
    this->TickDelay = 10;
}

void OSC_Common::inc_tickDelay(){
    this->TickDelay++;
    if(this->TickDelay > 1000){
        int bp = 0;
        bp++;
    }
}

void OSC_Common::dec_tickDelay(){
    if(this->TickDelay > 10){
        this->TickDelay = this->TickDelay - 1;
    }
}

void OSC_Common::Add_Integer(int value){
    QString val = QString::number(value);
    int index = 0;
    while(index < val.length()){
        if(val[index] == '0'){
            Result.push_back(ZERO);
        }else if(val[index] == '1'){
            Result.push_back(ONE);
        }else if(val[index] == '2'){
            Result.push_back(TWO);
        }else if(val[index] == '3'){
            Result.push_back(THREE);
        }else if(val[index] == '4'){
            Result.push_back(FOUR);
        }else if(val[index] == '5'){
            Result.push_back(FIVE);
        }else if(val[index] == '6'){
            Result.push_back(SIX);
        }else if(val[index] == '7'){
            Result.push_back(SEVEN);
        }else if(val[index] == '8'){
            Result.push_back(EIGHT);
        }else if(val[index] == '9'){
            Result.push_back(NINE);
        }
        index++;
    }
}

void OSC_Common::Begin(){
    this->Result.clear();
}

void OSC_Common::Add_Step(btns Button){
    this->Result.push_back(Button);
}

void OSC_Common::Add_Step(btns Button, int value){
    this->Result.push_back(Button);
    this->Add_Integer(value);
}

void OSC_Common::Add_Step(btns Button, int Dec, int Frac){
    this->Result.push_back(Button);
    this->Add_Integer(Dec);
    this->Result.push_back(DOT);
    this->Add_Integer(Frac);
}

void OSC_Common::Add_Step(btns B1, btns B2, int Val){
    this->Result.push_back(B1);
    this->Result.push_back(B2);
    this->Add_Integer(Val);
}

void OSC_Common::Add_Step(btns B1, btns B2, int Dec, int Frac){
    this->Result.push_back(B1);
    this->Result.push_back(B2);
    this->Add_Integer(Dec);
    this->Result.push_back(DOT);
    this->Add_Integer(Frac);
}

void OSC_Common::Add_Step(QVector<OSC_Common::btns> btns){
    for(int i = 0; i < btns.size(); i++){
        this->Result.push_back(btns[i]);
    }
}

QVector<OSC_Common::btns> OSC_Common::End(){
    return this->Result;
}
