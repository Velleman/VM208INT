#include <Arduino.h>
#include <Wire.h>
#include <VM208INT.h>
#include <VM208EX.h>
VM208INT interface;
VM208INT interface2;
VM208EX ex1; 
VM208EX ex2; 
VM208EX ex3;
VM208EX ex4; 
VM208EX ex5;
void InterruptServiceRoutine();
void handleInterrupt();
void toggleChannel(VM208EX &ex, uint8_t channel);
bool interruptTriggerd = false;
unsigned long previousTime = 0;
void setup()
{
  Serial.begin(115200);
  Serial.println("test");

#ifndef ESP32
  Wire.begin();
#else
  Wire.begin(33, 32, 100000);
#endif
  // put your setup code here, to run once:
  interface.setAddress(0x70);
  interface2.setAddress(0x71);
  ex1.setSocket(interface.getSocket(1));
  ex2.setSocket(interface.getSocket(2));
  ex3.setSocket(interface.getSocket(3));
  ex4.setSocket(interface.getSocket(4));
  ex5.setSocket(interface2.getSocket(1));
  attachInterrupt(GPIO_NUM_35, InterruptServiceRoutine, FALLING);
}

void loop()
{
  /*if((millis() - previousTime) > 5000)
  {
    ex1[0].toggle();
    ex1[7].toggle();
    previousTime = millis();
  }*/
  handleInterrupt();
  //ex1[0].enable(true);
  
  /*ex1.turnAllChannelsOn();
  //ex2.turnAllChannelsOff();
  delay(400);
  ex1.turnAllChannelsOff();
  //ex2.turnAllChannelsOn();
  delay(400);
  /*
  ex1.turnOffChannel(0);
  ex1.turnOnChannel(0);*/

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

void InterruptServiceRoutine()
{
  interruptTriggerd = true;
}

void handleInterrupt()
{
  if (interruptTriggerd || digitalRead(35) == LOW)
  {
    uint8_t socket = interface.handleInterrupt();
    if (socket) //if zero no interrupt happend on this interface
    {
      switch (socket)
      {
      case 1:
        toggleChannel(ex1, ex1.getPressedButton());
        break;
      case 2:
        toggleChannel(ex2, ex2.getPressedButton());
        break;
      case 3:
        toggleChannel(ex3, ex3.getPressedButton());
        break;
      case 4:
        toggleChannel(ex4, ex4.getPressedButton());
        break;
      default:
        break;
      }
    }
    socket = interface2.handleInterrupt();
    if (socket)
    {
      switch (socket)
      {
      case 1:
        toggleChannel(ex5, ex5.getPressedButton());
        break;
      default:
        break;
      }
    }
    interruptTriggerd = false;
  }
}

void toggleChannel(VM208EX &ex, uint8_t channel)
{
  if (channel)
  {
    ex[channel - 1].toggle();
  }
}
