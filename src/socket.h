#pragma once
class Interface;
#include "Arduino.h"
class Socket{
    public:
        Socket(Interface* interface=NULL,unsigned int id=0);
        void Activate();
        void Disactivate();
    protected:
        Interface* _interface;
        unsigned int _id;
};