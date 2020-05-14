#pragma once
#include "VM208Module.h"

class VM208EX : public VM208Module{
    public:
     VM208EX(uint8_t socket);
     void turnOnChannel(uint8_t index);
     void turnOffChannel(uint8_t index);
     bool isButtonPressed();
     uint8_t getPressedButton();
     private:
        uint8_t _address = 0x23;
        bool _relays[8] = {false,false,false,false,false,false,false,false};
        bool _leds[8] = {false,false,false,false,false,false,false,false};
};