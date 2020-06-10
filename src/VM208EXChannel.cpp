#include "VM208EXChannel.h"

VM208EXChannel::VM208EXChannel(uint8_t id, TCA6424A *tca)
{
    _id = id;
    _tca = tca;
    _reflectStatus = true;
}

void VM208EXChannel::turnOn()
{
    _tca->writePin(_id, TCA6424A_HIGH);
    if (_reflectStatus)
        _tca->writePin(_id + TCA6424A_P20, TCA6424A_LOW);
}

void VM208EXChannel::turnOff()
{
    _tca->writePin(_id, TCA6424A_LOW);
    if (_reflectStatus)
        _tca->writePin(_id + TCA6424A_P20, TCA6424A_HIGH);
}

void VM208EXChannel::turnLedOn()
{
    _tca->writePin(_id + TCA6424A_P20, TCA6424A_LOW);
}

void VM208EXChannel::turnLedOff()
{
    _tca->writePin(_id + TCA6424A_P20, TCA6424A_HIGH);
}

void VM208EXChannel::toggleLed()
{
    if(_tca->readPin(_id + TCA6424A_P20))
    {
        turnLedOff();
    }else{
        turnLedOn();
    }   
}

bool VM208EXChannel::isButtonPressed()
{
    return !_tca->readPin(_id + TCA6424A_P10); //Active low so invert the result;
}

void VM208EXChannel::toggle()
{
    bool state = _tca->readPin(_id);
    if(state)
        turnOff();
    else
    {
        turnOn();
    }
}

void VM208EXChannel::reflectStatus(bool status)
{
    _reflectStatus = status;
}