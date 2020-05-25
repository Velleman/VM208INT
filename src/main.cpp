#include <Arduino.h>
#include <Wire.h>
#include <VM208INT.h>
#include <VM208EX.h>
VM208INT interface;
VM208INT interface2;
VM208EX ex1; // = VM208EX(interface.getSocket(0));
VM208EX ex2; // = VM208EX(interface2.getSocket(0));;*/
//VM208EX *ex3;
/*VM208EX ex4 = VM208EX(interface.getSocket(3));*/
void setup()
{
  Serial.begin(9600);
  Serial.println("test");
  Wire.begin();
  // put your setup code here, to run once:
  interface.setAddress(0x70);
  interface2.setAddress(0x71);
  ex1.setSocket(interface.getSocket(0));
  ex2.setSocket(interface2.getSocket(0));
  
}

void loop()
{
  ex1[0].turnOn();
  ex2[0].turnOn();
  delay(200);
  ex1[0].turnOff();
  ex2[0].turnOff();
  delay(200);
  /*
  ex1->turnAllChannelsOn();
  ex2->turnAllChannelsOff();
  delay(400);
  ex1->turnAllChannelsOff();
  ex2->turnAllChannelsOn();
  delay(400);
  */

  /*
  for(int i = 0 ;i<8;i++)
  {
    ex1->turnOnChannel(i);
    delay(200);
  }
  for(int i = 0 ;i<8;i++)
  {
    ex2->turnOnChannel(i);
    delay(200);
  }
  for(int i = 0 ;i<8;i++)
  {
    ex3->turnOnChannel(i);
    delay(200);
  }
  for(int i = 0 ;i<8;i++)
  {
    ex1->turnOffChannel(i);
    delay(200);
  }
  for(int i = 0 ;i<8;i++)
  {
    ex2->turnOffChannel(i);
    delay(200);
  }
  for(int i = 0 ;i<8;i++)
  {
    ex3->turnOffChannel(i);
    delay(200);
  }*/
}