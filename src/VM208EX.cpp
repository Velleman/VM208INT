#include "VM208EX.h"

VM208EX::VM208EX(Socket *socket) : RelayModule(socket)
{
    
}

void VM208EX::initialize()
{
    this->_channels = (VM208EXChannel **)malloc(sizeof(VM208EXChannel) * 8);
    for (int i = 0; i < 8; i++)
    {
        this->_channels[i] = new VM208EXChannel(i, &this->tca);
    }
    this->tca.setBankDirection(0, 0x00);
    this->tca.setBankDirection(1, 0xFF);
    this->tca.setBankDirection(2, 0x00);
    turnAllChannelsOff();
}

void VM208EX::setSocket(Socket *socket)
{
    this->_socket = socket;
    this->Activate();
    this->tca.setBankDirection(0, 0x00);
    this->tca.setBankDirection(1, 0xFF);
    this->tca.setBankDirection(2, 0x00);
    this->tca.readBank(1);
    turnAllChannelsOff();
    this->Disactivate();
}

void VM208EX::turnOnChannel(uint8_t index)
{
    this->Activate();
    this->_channels[index]->turnOn();
    this->Disactivate();
}

void VM208EX::turnOffChannel(uint8_t index)
{
    this->Activate();
    this->_channels[index]->turnOff();
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
    this->Activate();
    uint8_t bank = this->tca.readBank(1);
    uint8_t position = 1;
    for (int i = 0; i < 8; i++)
    {   
        if ((bank | 0xFE) == 0xFE)
        {
            return position;
        }
        bank = bank >> 1;
        position++;
    }
    return 0;
}

VM208EXChannel &VM208EX::operator[](int index)
{
    this->Activate();
    if (index > 7)
    {
        // return first element.
        return *(this->_channels[0]);
    }

    return *(this->_channels[index]);
}

VM208EXChannel *VM208EX::getChannel(uint8_t index)
{
    this->Activate();
    if (index <= 7)
        return _channels[index];
    else
        return _channels[0];
}