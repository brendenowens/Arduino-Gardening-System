#include "Arduino.h"
#include "SoilSensor.h"

SoilSensor::SoilSensor(int low, int high)
{
  danger = low;
  fine = high;
}

boolean SoilSensor::checkSoil(int pin)
{
  int moist;
  switch (pin)
  {
      case 1:
            moist = analogRead(PIN1);
            Serial.println(moist);
            if(moist <= fine) 
            {
              //soil is fine
              return false;
            }
            else if (moist >= danger)
            {
              //soil is dry and needs water
              return true;
            }
            break;
    
      case 2:
            moist = analogRead(PIN2);
            Serial.println(moist);
            if(moist <= fine) 
            {
              return false;
            }
            else if (moist >= danger)
            {
              return true;
            }
            break;
    
      case 3:
            moist = analogRead(PIN3);
            Serial.println(moist);
            if(moist <= fine) 
            {
              return false;
            }
            else if (moist >= danger)
            {
              return true;
            }
            break;
    
      default:
      break;
  }

}
