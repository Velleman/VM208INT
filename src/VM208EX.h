#pragma once
#include "RelayModule.h"
#include "socket.h"
#include "TCA6424A.h"
#include "VM208EXChannel.h"
class VM208EX : public RelayModule
{
public:
    VM208EX(Socket *socket = NULL);
    void initialize();
    void turnOnChannel(uint8_t index);
    void turnOffChannel(uint8_t index);
    void turnAllChannelsOn();
    void turnAllChannelsOff();
    bool isButtonPressed();
    uint8_t getPressedButton();
    void setSocket(Socket* socket);
    VM208EXChannel &operator[](int i);
    VM208EXChannel *getChannel(uint8_t index,bool activate = true);
    
private:
    TCA6424A tca = TCA6424A(TCA6424A_ADDRESS_ADDR_HIGH);
    VM208EXChannel** _channels;
};