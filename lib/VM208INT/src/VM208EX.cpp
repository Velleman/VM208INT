#include "VM208EX.h"

VM208EX::VM208EX(Socket* socket) : Module(socket) {
    this->_socket->Activate();
    this->tca.setBankDirection(0,TCA6424A_OUTPUT);
    this->tca.setBankDirection(1,TCA6424A_INPUT);
    this->tca.setBankDirection(2,TCA6424A_OUTPUT);
    this->tca.writeBank(0,TCA6424A_LOW);
    this->tca.writeBank(2,TCA6424A_HIGH);
    this->_socket->Disactivate();
}

void VM208EX::turnOnChannel(uint8_t index) {
    this->_socket->Activate();
    this->tca.writePin(index,TCA6424A_HIGH);//turn relay on
    this->tca.writePin(TCA6424A_P20+index,TCA6424A_LOW);//turn LED on
    this->_socket->Disactivate();
}

void VM208EX::turnOffChannel(uint8_t index) {
   this->_socket->Activate();
   this->tca.writePin(index,TCA6424A_LOW);
   this->tca.writePin(TCA6424A_P20+index,TCA6424A_HIGH);
   this->_socket->Disactivate();
}

void VM208EX::turnAllChannelsOn()
{
    this->_socket->Activate();
    this->tca.writeBank(0,0xFF);
    this->tca.writeBank(2,0x00);
    this->_socket->Disactivate();
}

void VM208EX::turnAllChannelsOff()
{
    this->_socket->Activate();
    this->tca.writeBank(0,0x00);
    this->tca.writeBank(2,0xFF);
    this->_socket->Disactivate();
}

bool VM208EX::isButtonPressed() {
    
    return false;
}

uint8_t VM208EX::getPressedButton() {
    return 0;
}
