#include "interface.h"

Interface::Interface(uint8_t address)
{
    this->_address = address;
}

uint8_t Interface::getAddress()
{
    return this->_address;
}

void Interface::setAddress(uint8_t address)
{
    this->_address = address;
}