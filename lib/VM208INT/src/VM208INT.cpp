#include "VM208INT.h"

VM208INT::VM208INT(uint8_t address)
{
    
}
VM208INT::VM208INT(uint8_t address) {
    
}

void VM208INT::setModule(VM208Module module, uint8_t index) {
    
}

void VM208INT::setModule1(VM208Module  module) {
    
}

void VM208INT::setModule2(VM208Module  module) {
    
}

void VM208INT::setModule3(VM208Module  module) {
    
}

void VM208INT::setModule4(VM208Module  module) {
    
}

VM208Module* VM208INT::getModule1() {
    return this->_modules[0];
}

VM208Module* VM208INT::getModule2() {
    return this->_modules[1];
}

VM208Module* VM208INT::getModule3() {
    return this->_modules[2];
}

VM208Module* VM208INT::getModule4() {
    return this->_modules[3];
}

VM208Module* VM208INT::getModule(int index) {
    return this->_modules[index];
}
