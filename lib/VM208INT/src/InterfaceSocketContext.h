#pragma once
#include "Interface.h"

class InterfaceSocketContext
{
    public:
        InterfaceSocketContext(Interface* interface);
        unsigned char getAddress();
    private:
        Interface* _interface;
};