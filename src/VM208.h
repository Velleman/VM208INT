#pragma once
#include "module.h"
#include "socket.h"
#include "TCA6424A.h"
#include "VM208Channel.h"
class VM208 : public Module
{
public:
    VM208(Socket *socket = NULL);
    void turnOnChannel(uint8_t index);
    void turnOffChannel(uint8_t index);
    void turnAllChannelsOn();
    void turnAllChannelsOff();
    bool isButtonPressed();
    uint8_t getPressedButton();
    void setSocket(Socket* socket);
    VM208Channel &operator[](int i);
    
private:
    TCA6424A tca = TCA6424A(TCA6424A_ADDRESS_ADDR_HIGH);
    VM208Channel* _channels;
};