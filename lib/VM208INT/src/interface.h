#pragma once
class Socket;
#include "Socket.h"
#include "Arduino.h"
class Interface
{
public:
    Interface(uint8_t address);
    uint8_t getAddress();

protected:
    unsigned char _address;
    Socket *_sockets;
};
