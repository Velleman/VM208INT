#pragma once
#include <Arduino.h>
class VM208Module{
    public:
        VM208Module(uint8_t socket);
    protected:
        uint8_t _socket;
};