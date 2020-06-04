#pragma once
class Socket;
#include "Socket.h"
#include "Arduino.h"
class Interface
{
public:
    Interface(uint8_t address);
    uint8_t getAddress();
    void setAddress(uint8_t address);

protected:
    unsigned char _address;
};
