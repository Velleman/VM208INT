#include "VM208EX.h"

VM208EX::VM208EX(Socket *socket) : Module(socket)
{
    this->_channels = (VM208EXChannel *)malloc(sizeof(VM208EXChannel) * 8);
    for (int i = 0; i < 8; i++)
    {
        this->_channels[i] = VM208EXChannel(i, &this->tca);
    }
}

void VM208EX::setSocket(Socket *socket)
{
    this->_socket = socket;
    this->Activate();
    this->tca.setBankDirection(0, TCA6424A_OUTPUT);
    this->tca.setBankDirection(1, TCA6424A_INPUT);
    this->tca.setBankDirection(2, TCA6424A_OUTPUT);
    turnAllChannelsOff();
    this->Disactivate();
}

void VM208EX::turnOnChannel(uint8_t index)
{
    this->Activate();
    this->_channels[index].turnOn();
    this->Disactivate();
}

void VM208EX::turnOffChannel(uint8_t index)
{
    this->Activate();
    this->_channels[index].turnOff();
    this->Disactivate();
}

void VM208EX::turnAllChannelsOn()
{
    this->Activate();
    this->tca.writeBank(0, 0xFF);
    this->tca.writeBank(2, 0x00);
    this->Disactivate();
}

void VM208EX::turnAllChannelsOff()
{
    this->Activate();
    this->tca.writeBank(0, 0x00);
    this->tca.writeBank(2, 0xFF);
    this->Disactivate();
}

bool VM208EX::isButtonPressed()
{
    return false;
}

uint8_t VM208EX::getPressedButton()
{
    return 0;
}

VM208EXChannel &VM208EX::operator[](int index)
{
    this->Activate();
    if (index > 7)
    {
        // return first element.
        return this->_channels[0];
    }

    return this->_channels[index];
}
