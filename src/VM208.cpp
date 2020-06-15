#include "VM208.h"

VM208::VM208(Socket *socket) : RelayModule(socket)
{
    
}

void VM208::initialize()
{
    Serial.println("Initialize VM208");
    _channels = (VM208Channel *)malloc(sizeof(VM208Channel) * 4);
    for (int i = 0; i < 4; i++)
    {
        _channels[i] = VM208Channel(i, &tca);
    }
    tca.setBankDirection(0, 0b00000010);
    
    tca.setBankDirection(1, 0x0F);
    tca.setBankDirection(2, 0x00);
    //turnAllChannelsOff();
}

void VM208::setSocket(Socket *socket)
{
}

void VM208::turnOnChannel(uint8_t index)
{
    _channels[index].turnOn();
}

void VM208::turnOffChannel(uint8_t index)
{
    _channels[index].turnOff();
}

void VM208::turnAllChannelsOn()
{
    Serial.println("Turn On these bitches");
    uint8_t bank = tca.readBank(0);
    tca.writeBank(0, bank | 0x0F);
    tca.writeBank(1, 0x00);
}

void VM208::turnAllChannelsOff()
{
    uint8_t bank = tca.readBank(0);
    tca.writeBank(0, 0xF0 & bank);
    tca.writeBank(1, 0xFF);
}

bool VM208::isButtonPressed()
{
    return false;
}

uint8_t VM208::getPressedButton()
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

VM208Channel* VM208::getChannel(uint8_t index)
{
    if()
    return &_channels[index];
}

VM208Channel &VM208::operator[](int index)
{
    this->Activate();
    if (index > 3)
    {
        // return first element.
        return _channels[0];
    }

    return _channels[index];
}
