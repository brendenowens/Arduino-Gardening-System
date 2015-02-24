#ifndef RainSensor_h
#define RainSensor_h

#include "Arduino.h"

class RainSensor
{
	public:
		RainSensor(void);
		boolean isRaining();
	private:
		//int _outputPin;
};

#endif