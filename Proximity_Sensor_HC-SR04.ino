//FINAL CODE EVERYTHING WORKS
// Include NewPing Library for better calculations using the HC-SR04 sensor
#include "NewPing.h"

#define TRIGGER_PIN_R       3
#define ECHO_PIN_R          4
#define LED_YELLOW_R        7
#define LED_ORANGE_R        6
#define LED_RED_R           5


#define TRIGGER_PIN_L       13

#define ECHO_PIN_L          2
#define LED_YELLOW_L        11
#define LED_ORANGE_L        10
#define LED_RED_L           9


#define MAX_DISTANCE     400


//R is for Right , L is for Left


NewPing sonarR(TRIGGER_PIN_R,ECHO_PIN_R,MAX_DISTANCE);
NewPing sonarL(TRIGGER_PIN_L,ECHO_PIN_L,MAX_DISTANCE);


float distanceR;
float distanceL;

void setup() {
  Serial.begin(9600);
  pinMode(LED_RED_R, OUTPUT);
  pinMode(LED_ORANGE_R, OUTPUT);
  pinMode(LED_YELLOW_R, OUTPUT);
  pinMode(LED_RED_L, OUTPUT);
  pinMode(LED_ORANGE_L, OUTPUT);
  pinMode(LED_YELLOW_L, OUTPUT);
  }

void loop() {

  //right
  
    distanceR = sonarR.ping_cm();
  if (distanceR <=5) {
    digitalWrite(LED_RED_R,LOW);
    digitalWrite(LED_ORANGE_R,LOW);
    digitalWrite(LED_YELLOW_R,LOW);
  }
  else if ( distanceR <=50 ){
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
  else if (distanceR >= 150) {
    digitalWrite(LED_RED_R,LOW);
    digitalWrite(LED_ORANGE_R,LOW);
    digitalWrite(LED_YELLOW_R,LOW);
  }


  
  //Send results to Serial Monitor

  
  Serial.print("Distance Right= ");
  if (distanceR >= 400 ){
    Serial.print(" Right Out of range");
    Serial.println(distanceR);
  }
 else if (distanceR <=2){
    Serial.print("Right Too Close");
    Serial.println(distanceR);
  }
  else  {
    Serial.print(distanceR);
    Serial.println(" cm");
    delay(100);
  }


 distanceL = sonarL.ping_cm();
  if (distanceL <=5) {
    digitalWrite(LED_RED_L,LOW);
    digitalWrite(LED_ORANGE_L,LOW);
    digitalWrite(LED_YELLOW_L,LOW);
  }
  else if ( distanceL <=50 ){
    digitalWrite(LED_RED_L,HIGH);
    digitalWrite(LED_ORANGE_L,HIGH);
    digitalWrite(LED_YELLOW_L,HIGH);
    
    }
  else if(distanceL <= 100) {
    digitalWrite(LED_RED_L,LOW);
    digitalWrite(LED_ORANGE_L,HIGH);
    digitalWrite(LED_YELLOW_L,HIGH);
  } 
  else if(distanceL <= 150) {
    digitalWrite(LED_RED_L,LOW);
    digitalWrite(LED_ORANGE_L,LOW);
    digitalWrite(LED_YELLOW_L,HIGH);
 
  }
  else if (distanceL >= 150) {
    digitalWrite(LED_RED_L,LOW);
    digitalWrite(LED_ORANGE_L,LOW);
    digitalWrite(LED_YELLOW_L,LOW);
  }

  
 Serial.print("Distance Right= ");
  if (distanceL >= 400 ){
    Serial.print(" Left Out of range");
    Serial.println(distanceR);
  }
 else if (distanceL <=2){
    Serial.print("Left Too Close");
    Serial.println(distanceL);
  }
  else  {
    Serial.print(distanceL);
    Serial.println(" cm");
    delay(100);
  }



  
  delay(1000);

}
