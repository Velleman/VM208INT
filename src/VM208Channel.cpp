#include "VM208Channel.h"

VM208Channel::VM208Channel(uint8_t id, TCA6424A *tca)
{
    this->_id = id;
    this->_tca = tca;
    this->_reflectStatus = true;
}

void VM208Channel::turnOn()
{
    _state = true;
    this->_tca->writePin(this->_id, TCA6424A_HIGH);
    if (this->_reflectStatus)
        this->turnLedOn();
}

void VM208Channel::turnOff()
{
    _state = false; 
    this->_tca->writePin(this->_id, TCA6424A_LOW);
    if (this->_reflectStatus)
        this->turnLedOff();
}

void VM208Channel::turnLedOn()
{
    _ledStatus = true;
    this->_tca->writePin(this->_id + TCA6424A_P14, TCA6424A_LOW);
}

void VM208Channel::turnLedOff()
{
    _ledStatus = false;
    this->_tca->writePin(this->_id + TCA6424A_P14, TCA6424A_HIGH);
}

void VM208Channel::toggleLed()
{
    if(_ledStatus)
    {
        this->turnLedOff();
    }else{
        this->turnLedOn();
    }   
}

bool VM208Channel::isButtonPressed()
{
    return !this->_tca->readPin(this->_id + TCA6424A_P10); //Active low so invert the result;
}

void VM208Channel::toggle()
{
    if(_state)
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

bool VM208Channel::isOn()
{
    return _state;
}

bool VM208Channel::isOff()
{
    return !_state;
}