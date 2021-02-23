// Include NewPing Library for better calculations using the HC-SR04 sensor
#include "NewPing.h"

// Trig to Arduino Pin 6 and Echo to Arduino Pin 9.

#define TRIGGER_PIN_R       6
#define ECHO_PIN_R          9
#define MAX_DISTANCE      400
#define LED_YELLOW_R        13
#define LED_ORANGE_R       3
#define LED_RED_R          11
//R is for Right , L is for Left


NewPing sonarR(TRIGGER_PIN_R,ECHO_PIN_R,MAX_DISTANCE);

float distanceR;

void setup() {
  Serial.begin(9600);
  pinMode(LED_RED_R, OUTPUT);
  }

void loop() {
  distanceR = sonarR.ping_cm();
  if (distanceR <= 50){
    digitalWrite(LED_RED_R,HIGH);
    digitalWrite(LED_ORANGE_R,HIGH);
    digitalWrite(LED_YELLOW_R,HIGH);
    
    }
  else if(distanceR <= 100) {
    digitalWrite(LED_RED_R,LOW);
    digitalWrite(LED_ORANGE_R,HIGH);
    digitalWrite(LED_YELLOW_R,HIGH);
  }
  else if(distanceR <= 150) {
    digitalWrite(LED_RED_R,LOW);
    digitalWrite(LED_ORANGE_R,LOW);
    digitalWrite(LED_YELLOW_R,HIGH);
 
  }
  else  {
    digitalWrite(LED_RED_R,LOW);
    digitalWrite(LED_ORANGE_R,LOW);
    digitalWrite(LED_YELLOW_R,LOW);
  }

    

  
  //Send results to Serial Monitor
  Serial.print("Distance= ");
  if (distanceR >= 400 || distanceR <=2){
    Serial.println("Out of range");
  }
  else {
    Serial.print(distanceR);
    Serial.println(" cm");
    delay(100);
  }
  delay(100);

}
