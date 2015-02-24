#include "Arduino.h"
#include "RainSensor.h"

RainSensor::RainSensor(void)
{
	
 	
}

boolean RainSensor::isRaining()
{
	if(analogRead(A2) >400) {
		Serial.println(analogRead(9));
  		return true;
  	}
  	else return false;
}