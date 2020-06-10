#pragma once
#include "Arduino.h"
class RelayChannel
{
public:
    RelayChannel();
    void setName(String name);
    String getName();
    virtual void turnOn();
    virtual void turnOff();
    virtual void enable(bool enable);
    virtual void turnLedOn();
    virtual void turnLedOff();
    virtual void toggleLed();
    virtual bool isButtonPressed();
    virtual void toggle();
    virtual void reflectStatus(bool status);
protected:
    String _name;
};