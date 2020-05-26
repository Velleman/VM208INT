#pragma once
#include "interface.h"
#include "TCA9544.h"
class VM208INT : public Interface
{
public:
    VM208INT(uint8_t address = 0x70);
    void setAddress(uint8_t address);
    Socket* getSocket(uint8_t index);
    uint8_t handleInterrupt();
private:
    TCA9544* _tca;
    Socket* _sockets;
};