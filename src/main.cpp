#include <Arduino.h>
#include <VM208INT.h>
#include <VM208EX.h>
VM208INT interface = VM208INT(0x70);
VM208EX ex1 = VM208EX(1);
void setup() {
  // put your setup code here, to run once:
  interface.setModule1(ex1);
}

void loop() {
  // put your main code here, to run repeatedly:
}