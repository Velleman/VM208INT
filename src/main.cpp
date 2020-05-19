#include <Arduino.h>
#include <VM208INT.h>
#include <VM208EX.h>
VM208INT interface = VM208INT(0x70);
VM208EX ex1 = VM208EX(interface.getSocket(0));
VM208EX ex2 = VM208EX(interface.getSocket(1));
VM208EX ex3 = VM208EX(interface.getSocket(2));
VM208EX ex4 = VM208EX(interface.getSocket(3));
void setup() {
  // put your setup code here, to run once:
 
}

void loop() {
  // put your main code here, to run repeatedly:
}