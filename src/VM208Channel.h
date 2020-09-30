#pragma once
#include "stdint.h"
#include "TCA6424A.h"
#include "RelayChannel.h"
class VM208Channel: public RelayChannel{
    public:
        VM208Channel(uint8_t id,TCA6424A* tca);
        void turnOn();
        void turnOff();
        void toggle();
        void turnLedOn();
        void turnLedOff();
        void toggleLed();
        bool isButtonPressed();
        void reflectStatus(bool enable);
        bool isOn();
        bool isOff();
    protected:
        uint8_t _id;
        TCA6424A* _tca;
        bool _reflectStatus;
        bool _ledStatus;

};