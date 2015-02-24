#ifndef SoilSensor_h
#define SoilSensor_h

#include "Arduino.h"

  // the sensor value description
  // 0  ~300     dry soil
  // 300~700     humid soil
  // 700~950     in water
  
#define PIN1 A0
#define PIN2 A1
#define PIN3 A2

class SoilSensor
{
	public:
		SoilSensor(int low, int high);
		boolean checkSoil(int pin);
	private:
		int danger;
		int fine;
};

#endif