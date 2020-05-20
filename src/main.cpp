#include <Arduino.h>
#include <Wire.h>
#include <VM208INT.h>
#include <VM208EX.h>
VM208INT *interface;
VM208EX *ex1;
VM208EX *ex2;
/*VM208EX ex3 = VM208EX(interface.getSocket(2));
VM208EX ex4 = VM208EX(interface.getSocket(3));*/
void setup()
{
  // put your setup code here, to run once:
  Wire.begin();
  interface = new VM208INT(0x70);
  ex1 = new VM208EX(interface->getSocket(0));
  ex2 = new VM208EX(interface->getSocket(1));
  Serial.begin(9600);
}

void loop()
{
  //ex1->turnOnChannel(0);
  ex1->turnAllChannelsOn();
  ex2->turnAllChannelsOn();
  delay(1000);
  ex1->turnAllChannelsOff();
  ex2->turnAllChannelsOff();
  //ex1->turnOffChannel(0);
  delay(1000);
}