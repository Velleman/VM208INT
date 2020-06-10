#include "RelayChannel.h"

RelayChannel::RelayChannel()
{
    
}

String RelayChannel::getName()
{
    return _name;
}

void RelayChannel::setName(String name)
{
    _name = name;
}

void RelayChannel::enable(bool state)
{
    if (state)
        this->turnOn();
    else
        this->turnOff();
}