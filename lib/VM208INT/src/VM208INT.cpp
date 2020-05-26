#include "VM208INT.h"
class Socket;
VM208INT::VM208INT(uint8_t address):Interface(address) {
    this->_sockets = new Socket[4];
    this->_sockets[0] = Socket(this,0);
    this->_sockets[1] = Socket(this,1);
    this->_sockets[2] = Socket(this,2);
    this->_sockets[3] = Socket(this,3);
    this->_tca = new TCA9544(this->_address);
}

void VM208INT::setAddress(uint8_t address)
{
    this->_address = address;
    delete this->_tca;
    this->_tca = new TCA9544(this->_address);
}

Socket* VM208INT:: getSocket(uint8_t socketNr)
{
    return &this->_sockets[socketNr-1];
}

uint8_t VM208INT::handleInterrupt()
{
    return this->_tca->readInterrupts();    
}