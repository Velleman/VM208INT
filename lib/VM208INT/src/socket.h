#pragma once
class Interface;
class Socket{
    public:
        Socket(Interface* interface);
        void Activate();
        void Disactivate();
    protected:
        Interface* _interface;
};