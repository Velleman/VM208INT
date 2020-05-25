#include "VM208EXChannel.h"

VM208EXChannel::VM208EXChannel(uint8_t id, TCA6424A* tca) {
    this->_id = id;
    this->_tca = tca;
}

void VM208EXChannel::turnOn() {
    this->_tca->writePin(this->_id,TCA6424A_HIGH);
    this->_tca->writePin(this->_id+TCA6424A_P20,TCA6424A_LOW);
}

void VM208EXChannel::turnOff() {
    this->_tca->writePin(this->_id,TCA6424A_LOW);
    this->_tca->writePin(this->_id+TCA6424A_P20,TCA6424A_HIGH);
}

void VM208EXChannel::changeState(bool state)
{
    if(state)
        this->turnOn();
    else
        this->turnOff();
    
}

void VM208EXChannel::turnLedOn() {
    this->_tca->writePin(this->_id+TCA6424A_P20,TCA6424A_LOW);
}

void VM208EXChannel::turnLedOff() {
    this->_tca->writePin(this->_id+TCA6424A_P20,TCA6424A_HIGH);
}

bool VM208EXChannel::isButtonPressed() {
    return !this->_tca->readPin(this->_id); //Active low so invert the result;   
}
