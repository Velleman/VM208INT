#pragma once
#include <Arduino.h>
#include "VM208Module.h"
class VM208INT{
    public:
        VM208INT(uint8_t address = 0x70);
        void setModule(VM208Module module,uint8_t index);
        void setModule1(VM208Module*  module);
        void setModule2(VM208Module*  module);
        void setModule3(VM208Module*  module);
        void setModule4(VM208Module*  module);
        VM208Module* getModule2();
        VM208Module* getModule3();
        VM208Module* getModule1();
        VM208Module* getModule4();
        VM208Module* getModule(int index);
    private:
        VM208Module* _modules[4];
        uint8_t _usedModules = 0;

};