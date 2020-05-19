#include "VM208EX.h"

VM208EX::VM208EX(Socket* socket) : Module(socket) {
    socket
    tca.setBankDirection(0,TCA6424A_OUTPUT);
    tca.setBankDirection(1,TCA6424A_INPUT);
    tca.setBankDirection(2,TCA6424A_OUTPUT);
}

void VM208EX::turnOnChannel(uint8_t index) {
    tca.setPinPolarity(index-1,TCA6424A_HIGH);
    tca.setPinPolarity(TCA6424A_P20+index-1,TCA6424A_LOW);
}

void VM208EX::turnOffChannel(uint8_t index) {
    tca.setPinPolarity(index-1,TCA6424A_LOW);
    tca.setPinPolarity(TCA6424A_P20+index-1,TCA6424A_HIGH);
}

bool VM208EX::isButtonPressed() {

    return false;
}

uint8_t VM208EX::getPressedButton() {
    return 0;
}
