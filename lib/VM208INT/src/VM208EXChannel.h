#pragma once
#include "stdint.h"
#include "TCA6424A.h"
class VM208EXChannel{
    public:
        VM208EXChannel(uint8_t id,TCA6424A* tca);
        void turnOn();
        void turnOff();
        void changeState(bool state);
        void turnLedOn();
        void turnLedOff();
        bool isButtonPressed();
    private:
        uint8_t _id;
        TCA6424A* _tca;

};