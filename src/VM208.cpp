#include "VM208.h"

VM208::VM208(Socket *socket) : RelayModule(socket)
{
}

void VM208::initialize()
{
    Serial.println("Initialize VM208");
    for (int i = 0; i < 4; i++)
    {
        _channels[i] = new VM208Channel(i, &tca);
    }
    //tca.setBankDirection(0, 0b00000010);
    tca.setPinDirection(TCA6424A_P00, TCA6424A_OUTPUT);
    tca.setPinDirection(TCA6424A_P01, TCA6424A_OUTPUT);
    tca.setPinDirection(TCA6424A_P02, TCA6424A_OUTPUT);
    tca.setPinDirection(TCA6424A_P03, TCA6424A_OUTPUT);
    tca.setPinDirection(TCA6424A_P04, TCA6424A_OUTPUT);
    tca.setPinDirection(TCA6424A_P05, TCA6424A_OUTPUT);
    tca.setPinDirection(TCA6424A_P06, TCA6424A_INPUT);
    tca.setPinDirection(TCA6424A_P07, TCA6424A_OUTPUT);

    tca.setBankDirection(1, 0x0F);
    tca.setPinDirection(TCA6424A_P10, TCA6424A_INPUT);
    tca.setPinDirection(TCA6424A_P11, TCA6424A_INPUT);
    tca.setPinDirection(TCA6424A_P12, TCA6424A_INPUT);
    tca.setPinDirection(TCA6424A_P13, TCA6424A_INPUT);
    tca.setPinDirection(TCA6424A_P14, TCA6424A_OUTPUT);
    tca.setPinDirection(TCA6424A_P15, TCA6424A_OUTPUT);
    tca.setPinDirection(TCA6424A_P16, TCA6424A_OUTPUT);
    tca.setPinDirection(TCA6424A_P17, TCA6424A_OUTPUT);
    tca.setBankDirection(2, 0x00);
    //turnAllChannelsOff();
}

void VM208::setSocket(Socket *socket)
{
}

void VM208::turnOnChannel(uint8_t index)
{
    _channels[index]->turnOn();
}

void VM208::turnOffChannel(uint8_t index)
{
    _channels[index]->turnOff();
}

void VM208::turnAllChannelsOn()
{
    //uint8_t bank = tca.readBank(0);
    for(int i = 0;i<4;i++)
    {
        _channels[i]->turnOn();
    }
}

void VM208::turnAllChannelsOff()
{
    for(int i = 0;i<4;i++)
    {
        _channels[i]->turnOff();
    }
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

VM208Channel *VM208::getChannel(uint8_t index)
{
    if (index <= 3)
        return _channels[index];
    else
        return _channels[0];
}

VM208Channel &VM208::operator[](int index)
{
    this->Activate();
    if (index > 3)
    {
        // return first element.
        return *_channels[0];
    }

    return *_channels[index];
}

bool VM208::getUserInputState()
{
    this->Activate();
    return this->tca.readPin(TCA6424A_P06);
}

void VM208::turnOnMosfet1()
{
    this->Activate();
    this->tca.writePin(TCA6424A_P04,HIGH);
    _mosfet1State = true;
}

void VM208::turnOffMosfet1()
{
    this->Activate();
    this->tca.writePin(TCA6424A_P04,LOW);
    _mosfet1State = false;
}

void VM208::turnOnMosfet2()
{
    this->Activate();
    this->tca.writePin(TCA6424A_P05,HIGH);
    _mosfet2State = true;
}

void VM208::turnOffMosfet2()
{
    this->Activate();
    this->tca.writePin(TCA6424A_P05,LOW);
    _mosfet2State = false;
}

bool VM208::getMosfet1State()
{
    return _mosfet1State;
}

bool VM208::getMosfet2State()
{
    return _mosfet2State;
}