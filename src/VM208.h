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
    bool getUserInputState();
    void turnOnMosfet1();
    void turnOffMosfet1();
    void turnOnMosfet2();
    void turnOffMosfet2();
    bool getMosfet1State();
    bool getMosfet2State();
    uint8_t getPressedButton();
    void setSocket(Socket* socket);
    VM208Channel &operator[](int i);
    void setChannel(RelayChannel* channel,int index);
    VM208Channel* getChannel(uint8_t index);
    
private:
    TCA6424A tca = TCA6424A(TCA6424A_ADDRESS_ADDR_LOW);
    VM208Channel* _channels[4];
    bool _mosfet1State=false;
    bool _mosfet2State=false;

};