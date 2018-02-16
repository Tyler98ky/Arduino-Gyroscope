

/*
Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

//#include <Servo.h>
#include "CurieIMU.h"
#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;
//Servo myservo;

const int colorR = 0;
const int colorG = 255;
const int colorB = 0;

//int pos = 0;

void setup()
{
  lcd.begin(16, 2);
  lcd.clear();
    
  lcd.setRGB(colorR, colorG, colorB);
    
  Serial.begin(9600); // initialize Serial communication
  Serial.println("Initializing IMU device...");

//  myservo.attach(9);  // attaches the servo on pin 9 to the servo object

// initialize device
  CurieIMU.begin();

// Set the accelerometer range to 2G
  CurieIMU.setAccelerometerRange(2);
}

void loop()
{
  printAcceloStats();
//  servoMovement();
}

void printAcceloStats(){
  float ax, ay, az;
  CurieIMU.readAccelerometerScaled(ax, ay, az);
  lcd.setCursor(0,0);
  lcd.print("X:");
  lcd.print(ax);
  lcd.print(" Y:");
  lcd.print(ay);
  lcd.setCursor(0,1);
  lcd.print(" Z:");
  lcd.print(az);
}

//void servoMovement(){
//  bool flag = true;
//  if(pos <= 180){
//    flag = true;
//    myservo.write(pos)
//  } else{
//      flag = false 
//   }
//  int delayTime = 0;
//  
//  for(pos = 0; pos <= 180; pos += 1) // goes from 0 degrees to 180 degrees
//  {                                  // in steps of 1 degree
//    myservo.write(pos);
//    delay(delayTime);               // waits 15ms for the servo to reach the position
//  }
//  
//  for(pos = 180; pos>=0; pos-=1)     // goes from 180 degrees to 0 degrees
//  {
//    myservo.write(pos); 
//    delay(delayTime);            // waits 15ms for the servo to reach the position
//  }  
//}
