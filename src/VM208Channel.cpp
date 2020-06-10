#include "VM208Channel.h"

VM208Channel::VM208Channel(uint8_t id, TCA6424A *tca)
{
    this->_id = id;
    this->_tca = tca;
    this->_reflectStatus = true;
}

void VM208Channel::turnOn()
{
    this->_tca->writePin(this->_id, TCA6424A_HIGH);
    if (this->_reflectStatus)
        this->_tca->writePin(this->_id + TCA6424A_P14, TCA6424A_LOW);
}

void VM208Channel::turnOff()
{
    this->_tca->writePin(this->_id, TCA6424A_LOW);
    if (this->_reflectStatus)
        this->_tca->writePin(this->_id + TCA6424A_P14, TCA6424A_HIGH);
}

void VM208Channel::turnLedOn()
{
    this->_tca->writePin(this->_id + TCA6424A_P14, TCA6424A_LOW);
}

void VM208Channel::turnLedOff()
{
    this->_tca->writePin(this->_id + TCA6424A_P14, TCA6424A_HIGH);
}

void VM208Channel::toggleLed()
{
    if(this->_tca->readPin(this->_id + TCA6424A_P14))
    {
        turnLedOff();
    }else{
        turnLedOn();
    }   
}

bool VM208Channel::isButtonPressed()
{
    return !this->_tca->readPin(this->_id + TCA6424A_P10); //Active low so invert the result;
}

void VM208Channel::toggle()
{
    bool state = this->_tca->readPin(this->_id);
    if(state)
        this->turnOff();
    else
    {
        this->turnOn();
    }
}

void VM208Channel::reflectStatus(bool status)
{
    this->_reflectStatus = status;
}