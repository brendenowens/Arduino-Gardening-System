/*******************************************************************************
 * Created by Brenden Owens                                                    *
 * Created on Feb 19 2015                                                      *
 * For use with analog mode soil moisture sensors, digital mode rain sensor,   *
 * and also three servo motor that are strong enough to turn a valve on a      *
 * water spiggot and hose dividers.                                            *
 *                                                                             *
 * Potential add ons:                                                          *
 *   Ethernet Sheild:                                                          *              
 *       For communication through Twitter, email, or text to notify when the  *
 *       system is turned on and off or when the system malfunctions.          *
 *                                                                             *
 *   Security system:                                                          *
 *       Have motion sensors to detect if an animal is coming close to the     *
 *       garden and have it activate a buzzer or some sort of sound to scare   *
 *       off the animal. Lights would also be a good idea to add so that the   *
 *       system can have more of an effect.                                    *
 *                                                                             *
 *   Video Monitoring:                                                         *
 *       Be able to record you garden's activity through a webcam to see what  *
 *       or who is disturbing your garden when you aren't there.               *
 *******************************************************************************/

//Custome coded classes for the system. Very basic but nicely organized
#include <RainSensor.h>
#include <SoilSensor.h>
#include <Servo.h>


//Objects for the sensors
SoilSensor sense(700,400);
RainSensor rain;

//Servo objects to control the hoses and water siggot 
Servo spiggot, area1, area2, area3;

int spiggot_pos = 0, area1_pos = 0, area_pos = 0, area3_pos = 0;

//Different times in milliseconds for easier calculating
#define MILLIDAY 86400000
#define MILLIHOUR 3600000
#define MILLIMIN 60000

#define LED1 22
#define LED2 23
#define LED3 24

//The variable total is the total times that the system has recorded it raining during its running time. 
//The variable dry is to tell the system that the garden needs to be watered and what servos to turn on.
int total, dry;

void setup()
{
  //This will begin the serial display communications on 15200
  Serial.begin(115200);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  
  spiggot.attach(2);
  area1.attach(3);
  area2.attach(4);
  area3.attach(5);
  spiggot.write(0);
  area1.write(0);
  area2.write(0);
  area3.write(0);
  
  /* The variable total will keep track of how many times it has been raining over the course of an hour.
   * If it has been raining for an hour then the system will be delayed for a whole day. */
  total=0;
  dry=0;
}

void loop()
{
    //We will check to see if it has been raining
    if(rain.isRaining())
    {
	 //Increase total by one
         total++; 
         //Serial.println(total);
    }
    //If total is equal to 4 then it has bee raining for an hour and we can take the day off 
    if(total == 4)
    {
         delay(MILLIHOUR);
	 //Make total back to 0 for the new day
         total=0; 
    }
    //If it hasn't been raining for an hour we need to check the soil moisture
    else
    {
         //Check soil sensor 1
         if(sense.checkSoil(1))
         {
           dry=1;
           spiggot_pos=100;
           area2_pos=100;
         }
         //check soil sensor 2
         if(sense.checkSoil(2))
         { 
           dry=2;
           area2_pos=100;
         }
         //check soil sensor 3
         if(sense.checkSoil(3)) {
           dry=3; 
           area3_pos=100;
         }
         
         if(dry == 1) {
	      //if it is dry then we need to water the area for half an hour
              //turn on servo for the system
              spiggot.write(spiggot_pos);
	      //Delay takes the time in milliseconds
              delay(MILLIHOUR/2);
              spiggot_pos=0;
              area1_pos=0;
              dry=0;
	      //turn off the hose
              spiggot.write(spiggot_pos);
              area1.write(area1_pos);
         }
         
         else if (dry == 2) {
              //if it is dry then we need to water the area for half an hour
              //turn on servo for the system 
              spiggot.write(spiggot_pos);
              area1.write(area1_pos);
              area2.write(area2_pos);
	      //Delay takes the time in milliseconds
              delay(MILLIHOUR/2);
              spiggot_pos=0;
              area1_pos=0;
              area2_pos=0;
              dry=0;
	      //turn off the hose
              spiggot.write(spiggot_pos);
              area1.write(area1_pos);
              area2.write(area2_pos);
         }
        else if (dry == 3) 
         {
              //if it is dry then we need to water the area for half an hour
              //turn on servo for the system
              spiggot.write(spiggot_pos);
              area1.write(area1_pos);
              area2.write(area2_pos);
              area3.write(area3_pos);
	      //Delay takes the time in milliseconds 
              delay(MILLIHOUR/2);
              spiggot_pos=0;
              area1_pos=0;
              area2_pos=0;
              dry =0;
	      //turn off the hose
              spiggot.write(spiggot_pos);
              area1.write(area1_pos);
              area2.write(area2_pos);
              area3.write(area3_pos);
         }
         
    }

    delay(MILLIHOUR/4);
}



