//HEADER FILE
#ifndef Hexapod_h
#define Hexapod_h
const int POSITIONING_POINTS_SERVO_LEFT[] = {1500,1100,1590,1100,1550,1100};
const int POSITIONING_POINTS_SERVO_RIGHT[] = {1500,1900,1500,1900,1550,1900};
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#define IRPD_LEFT_PIN 10
#define IRPD_RIGHT_PIN 11
#define SENSOR_PIN 12
#define LED_PIN 13

class Hexapod
{
  public:
  Hexapod();
  void wait();
  void servoMove(int number,int velocity);
  void servoDirectMove(int number,int directPosition,int velocity);
  void positioning(int velocity);
  int dataFromSensor();
  void sensorLeft();
  void sensorRight();
  int state;
  int temperatureRight;
  int temperatureLeft;
  int n;
  int verticalPosition = 500;
  int horizontalPosition = 500;
  int a=1500,
      b=1100,
      c=1590,
      d=1100,
      e=1550,
      f=1100,
      g=1500,
      h=1900,
      i=1500,
      j=1900,
      k=1550,
      l=1900;
  char ans;
  int servosPositions[22] = {g,h,i,j,k,l,0,0,0,0,0,0,0,0,0,0,a,b,c,d,e,f}; //deklaracja tablicy zmiennych pozycji dla kolejnych serwonapędów robota
};
#endif
