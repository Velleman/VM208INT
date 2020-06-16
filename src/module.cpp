#include "module.h"

Module::Module(Socket *socket)
{
    this->_socket = socket;
}

void Module::setSocket(Socket *socket)
{
    this->_socket = socket;
}

bool Module::Activate()
{
    if (this->_socket != NULL)
    {
        this->_socket->Activate();
        return true;
    }else{
        return false;
    }
}

void Module::Disactivate()
{
    if(this->_socket != NULL)
        this->_socket->Disactivate();
}

void Module::setInterfaceAddress(uint8_t address)
{
    this->_intAddress = address;
}

uint8_t Module::getInterfaceAddress()
{
    return this->_intAddress;
}

bool Module::hasSocket()
{
    return (this->_socket != NULL);
}