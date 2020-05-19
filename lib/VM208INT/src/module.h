#pragma once
#include <Arduino.h>
#include "socket.h"
class Module{
    public:
        Module(Socket* socket);
        void setInterfaceAddress(uint8_t);
        uint8_t getInterfaceAddress();
        /*void write(uint8_t value);
        void write(uint8_t* data,uint8_t length);*/
    protected:
        Socket* _socket;
        uint8_t _intAddress;
    
};