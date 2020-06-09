#pragma once
#include "stdint.h"
#include "TCA6424A.h"
class VM208Channel{
    public:
        VM208Channel(uint8_t id,TCA6424A* tca);
        void turnOn();
        void turnOff();
        void enable(bool state);
        void toggle();
        void turnLedOn();
        void turnLedOff();
        bool isButtonPressed();
        void reflectStatus(bool enable);
    private:
        uint8_t _id;
        TCA6424A* _tca;
        bool _reflectStatus;

};