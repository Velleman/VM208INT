#pragma once
#include "Arduino.h"
class RelayChannel
{
public:
    RelayChannel();
    void setName(String name);
    String getName();
    virtual void turnOn()=0;
    virtual void turnOff()=0;
    void enable(bool enable);
    virtual void turnLedOn()=0;
    virtual void turnLedOff()=0;
    virtual void toggleLed()=0;
    virtual bool isButtonPressed()=0;
    virtual void toggle()=0;
    virtual void reflectStatus(bool status)=0;
    virtual bool isOn()=0;
    virtual bool isOff()=0;
protected:
    String _name;
    bool _state = false;
};