# Arduino-Gardening-System
This is the code to a self monitoring and watering gardening system that uses soil moisture sensors, a rain sensor, and a few servo motors to keep the garden growing and happy. 

There are a few custom made classes that come with the Arduino code so know where to put them. On a mac it is usually in ~/Documents/Arduino/libraries is where you want to put the classes and then start up the Arduino IDE. For PC it would be located in the same place, so C:\\Users\$Your_User_Name_Here\Documents\Arduino\libraries. I might write a shell script for Linux and Mac users and a executable for Windows users, so they don't have to worry about copy and pasting it to their respected locations. 

The .ino file is the Arduino file that will have to be uploaded to the Arduino board.

If you have any questions, comments, or words of abuse please let me know.

EDIT: changed the servo code because the valve doesn't require 180 degrees to open. In my case it was just 100 degrees. Also made the servos start off in their default position, which is 0, in setup. 