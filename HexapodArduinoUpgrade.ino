#include "Hexapod.h"
Hexapod hexapod;

void setup() {
delay(2000);
hexapod.positioning(1200);
delay(2000);
while(!Serial){};
}

void loop() 
{
 legsMoveUp();
 Serial.println(hexapod.servosPositions[19]);
 legsMoveForward();
 delay(2000);
 legsMoveDown();
 Serial.println(hexapod.servosPositions[19]);
 legsMoveForward();
 delay(2000);
 hexapod.sensorLeft();
 hexapod.sensorRight();
 hexapod.dataFromSensor();
 if (hexapod.state == 0 ) {
  //if sensor didn't detects anything do...
  }
  if (hexapod.state == 1 ) {
  //if sensor detects something on the left do...
  }
  if (hexapod.state == 2 ) {
  //if sensor detects something on the right do...
  }
  if (hexapod.state == 3 ) {
  //if sensor detects something on the both sides do...
  }
}

void legsMoveUp()
{
  hexapod.servosPositions[1]=hexapod.servosPositions[1]-hexapod.verticalPosition;
  hexapod.servosPositions[19]=hexapod.servosPositions[19]+hexapod.verticalPosition;
  hexapod.servosPositions[5]=hexapod.servosPositions[5]-hexapod.verticalPosition;
}

void legsMoveDown()
{
  hexapod.servosPositions[1]=hexapod.servosPositions[1]+hexapod.verticalPosition;
  hexapod.servosPositions[19]=hexapod.servosPositions[19]-hexapod.verticalPosition;
  hexapod.servosPositions[5]=hexapod.servosPositions[5]+hexapod.verticalPosition;
}

void legsMoveForward()
{
  hexapod.servoMove(1,1500);
  hexapod.servoMove(19,1500);
  hexapod.servoMove(5,1500);
}
