#include "VM208EXChannel.h"

VM208EXChannel::VM208EXChannel(uint8_t id, TCA6424A *tca)
{
    this->_id = id;
    this->_tca = tca;
    this->_reflectStatus = true;
}

void VM208EXChannel::turnOn()
{
    this->_tca->writePin(this->_id, TCA6424A_HIGH);
    if (this->_reflectStatus)
        this->_tca->writePin(this->_id + TCA6424A_P20, TCA6424A_LOW);
}

void VM208EXChannel::turnOff()
{
    this->_tca->writePin(this->_id, TCA6424A_LOW);
    if (this->_reflectStatus)
        this->_tca->writePin(this->_id + TCA6424A_P20, TCA6424A_HIGH);
}

void VM208EXChannel::turnLedOn()
{
    this->_tca->writePin(this->_id + TCA6424A_P20, TCA6424A_LOW);
}

void VM208EXChannel::turnLedOff()
{
    this->_tca->writePin(this->_id + TCA6424A_P20, TCA6424A_HIGH);
}

void VM208EXChannel::toggleLed()
{
    if(this->_tca->readPin(this->_id + TCA6424A_P20))
    {
        turnLedOff();
    }else{
        turnLedOn();
    }   
}

bool VM208EXChannel::isButtonPressed()
{
    return !this->_tca->readPin(this->_id + TCA6424A_P10); //Active low so invert the result;
}

void VM208EXChannel::toggle()
{
    bool state = this->_tca->readPin(this->_id);
    if(state)
        this->turnOff();
    else
    {
        this->turnOn();
    }
}

void VM208EXChannel::reflectStatus(bool status)
{
    this->_reflectStatus = status;
}