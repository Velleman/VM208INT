#pragma once
#include "socket.h"
#include "module.h"
class RelayModule : public Module{
    public:
        RelayModule(Socket* socket=nullptr);
        virtual void initialize() = 0;
        virtual void turnOnChannel(uint8_t index) = 0;
        virtual void turnOffChannel(uint8_t index) = 0;
        virtual void turnAllChannelsOn() = 0;
        virtual void turnAllChannelsOff() = 0;
        virtual bool isButtonPressed() = 0;
        virtual uint8_t getPressedButton() = 0;
        virtual void setSocket(Socket* socket) = 0;
};