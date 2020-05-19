#include "module.h"

Module::Module(Socket* socket)
{
    this->_socket = socket;
}

void Module::setInterfaceAddress(uint8_t address)
{
    this->_intAddress = address;
}

uint8_t Module::getInterfaceAddress()
{
    return this->_intAddress;
}