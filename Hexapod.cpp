//IMPLEMENTATION FILE
#include "Hexapod.h"

Hexapod::Hexapod() {
 Serial.begin(9600);
 pinMode(IRPD_LEFT_PIN, OUTPUT);
 pinMode(IRPD_RIGHT_PIN, OUTPUT);
 pinMode(SENSOR_PIN, INPUT);
}
  
void Hexapod::wait() {
  label:
  Serial.println("Q");
  ans = Serial.read();
  if (ans == '+' )
  {
    delay(10);
   digitalWrite(LED_PIN, HIGH);
    goto label;
    }
    delay(10);
   digitalWrite(LED_PIN, LOW);
  }

void Hexapod::servoMove(int number, int velocity) {
   Serial.print("#");
   Serial.print(number);
   Serial.print(" P");
   Serial.print(servosPositions[number]);
   Serial.print(" S");
   Serial.println(velocity);
}

void Hexapod::servoDirectMove(int number,int directPosition,int velocity) {
   Serial.print("#");
   Serial.print(number);
   Serial.print(" P");
   Serial.print(directPosition);
   Serial.print(" S");
   Serial.println(velocity);
   wait();
}

void Hexapod::positioning(int velocity) {
  for (int i=0; i<6; i++) 
  {
   Serial.print("#");
   Serial.print(i);
   Serial.print(" P");
   Serial.print(POSITIONING_POINTS_SERVO_LEFT[i]);
   Serial.print(" S");
   Serial.println(velocity);
   wait();
   Serial.print("#");
   Serial.print(i+16);
   Serial.print(" P");
   Serial.print(POSITIONING_POINTS_SERVO_RIGHT[i]);
   Serial.print(" S");
   Serial.println(velocity);
   wait();
  }
}

void Hexapod::sensorRight() {
  delay(100);
  digitalWrite(IRPD_RIGHT_PIN, HIGH); 
  delay(1);
  temperatureRight = digitalRead(SENSOR_PIN); 
  digitalWrite(IRPD_RIGHT_PIN, LOW); 
  delay(1);
} 

void Hexapod::sensorLeft() {
  digitalWrite(IRPD_LEFT_PIN, HIGH); 
  delay(1);
  temperatureLeft = digitalRead(SENSOR_PIN);
  digitalWrite(IRPD_LEFT_PIN, LOW);
  delay(1);
}

int Hexapod::dataFromSensor() {
  if ((temperatureLeft == HIGH) && (temperatureRight == HIGH) )
  {
    state = 0;
    return state;
  }
   if ((temperatureLeft == LOW) && (temperatureRight == HIGH) )
  {
    state = 1;
    return state;
  }
     if ((temperatureLeft == HIGH) && (temperatureRight == LOW) )
  {
    state = 2;
    return state;
  }
   if ((temperatureLeft == LOW) && (temperatureRight == LOW) )
  {
    state = 3;
    return state;
  }
}
