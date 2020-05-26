/*
TCA9544 Library
.cpp file

This library is used to simplify the controll scheme of the TCA9544 chip for use with a bioreactor controller.


Lukas Jaworski

University of Miami
2016
*/

#include <TCA9544.h>

TCA9544::TCA9544(uint8_t addressBits){//feed in the A0-A2 bits to automatically adjust the TCA's address
	this->deviceAddress = addressBits;
	this->controlRegisterState = 0; //The control register is zero on intialization
}

void TCA9544::changeChannel(uint8_t channelSelect){
	this->controlRegisterState = ((this->controlRegisterState & 0b11110000) | (0b100 | channelSelect));
	Wire.beginTransmission(deviceAddress);
	Wire.write(this->controlRegisterState);
	Wire.endTransmission();
}

uint8_t TCA9544::readInterrupts(){
	uint8_t inters;
	Wire.requestFrom(this->deviceAddress, uint8_t(1));
	if (Wire.available()){
		this->controlRegisterState = Wire.read();
	}
	inters = this->controlRegisterState >> 4;
	return inters;
}

uint8_t TCA9544::currentChannel(){
	uint8_t channel;
	Wire.requestFrom(this->deviceAddress, uint8_t(1));
	if (Wire.available()){
		this->controlRegisterState = Wire.read();
	}
	channel = this->controlRegisterState & 0b11;
	return channel;
}