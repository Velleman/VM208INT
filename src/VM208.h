#pragma once
#include "RelayModule.h"
#include "socket.h"
#include "TCA6424A.h"
#include "VM208Channel.h"
class VM208 : public RelayModule
{
public:
    VM208(Socket *socket = NULL);
    void initialize();
    void turnOnChannel(uint8_t index);
    void turnOffChannel(uint8_t index);
    void turnAllChannelsOn();
    void turnAllChannelsOff();
    bool isButtonPressed();
    uint8_t getPressedButton();
    void setSocket(Socket* socket);
    VM208Channel &operator[](int i);
    void setChannel(RelayChannel* channel,int index);
    VM208Channel* getChannel(uint8_t index);
    
private:
    TCA6424A tca = TCA6424A(TCA6424A_ADDRESS_ADDR_LOW);
    VM208Channel* _channels[4];
};