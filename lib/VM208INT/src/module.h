#pragma once
#include <Arduino.h>
#include "socket.h"
class Module{
    public:
        Module(Socket* socket);
        void setInterfaceAddress(uint8_t);
        uint8_t getInterfaceAddress();
        void setSocket(Socket* socket);
        bool Activate();
        void Disactivate();
    protected:
        Socket* _socket;
        uint8_t _intAddress;    
};