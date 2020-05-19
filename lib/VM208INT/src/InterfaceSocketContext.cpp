#include "InterfaceSocketContext.h"

InterfaceSocketContext::InterfaceSocketContext(Interface* interface)
{
    this->_interface = interface;
}

uint8_t InterfaceSocketContext::getAddress()
{
    return this->_interface->getAddress();
}