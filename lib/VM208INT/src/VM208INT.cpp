#include "VM208INT.h"
class Socket;
VM208INT::VM208INT(uint8_t address):Interface(address) {
    this->_address = address;    
    this->_sockets = (Socket *)malloc(sizeof(Socket)*4);
    this->_tca = new TCA9544(this->_address);
}

Socket* VM208INT::getSocket(uint8_t index)
{
    return this->_sockets + index;
}