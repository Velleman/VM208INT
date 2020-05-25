#include "socket.h"
#include "Wire.h"
#include "Interface.h"
Socket::Socket(Interface *interface, unsigned int id)
{
    this->_interface = interface;
    this->_id = id;
}

void Socket::Activate()
{
    if (this->_interface != NULL)
    {
        Wire.beginTransmission(this->_interface->getAddress());
        Wire.write((0b1111100 | this->_id));
        Wire.endTransmission();
    }
}

void Socket::Disactivate()
{
    if (this->_interface != NULL)
    {
        Wire.beginTransmission(this->_interface->getAddress());
        Wire.write(0b11111000);
        Wire.endTransmission();
    }
}