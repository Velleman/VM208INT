#pragma once
#include "module.h"
#include "socket.h"
#include "TCA6424A.h"
class VM208EX : public Module
{
public:
    VM208EX(Socket *socket);
    void turnOnChannel(uint8_t index);
    void turnOffChannel(uint8_t index);
    bool isButtonPressed();
    uint8_t getPressedButton();

private:
    TCA6424A tca = TCA6424A(TCA6424A_ADDRESS_ADDR_HIGH);
    bool _relays[8] = {false, false, false, false, false, false, false, false};
    bool _leds[8] = {false, false, false, false, false, false, false, false};
};