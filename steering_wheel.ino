#define SENSOR A0 // voltage divider with 2 photoresistors in parallel and 1MOhm (pullup) in series
#define LED 22 

float prev_val;

void setup() {  
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  prev_val = (analogRead(SENSOR)+5)*10; 
}

bool touching = false; // if the program starts while driver is touching the wheel (thus initial val is actually true)
                       // only the first cycle will be affected and the program will function properly 

void loop() {
  float val = (analogRead(SENSOR)+5)*10;  
  Serial.print(val);
  
  float average = 0;
  int MeasurementsToAverage = 16;
  for(int i = 0; i < MeasurementsToAverage; ++i)
  {
    average += (analogRead(SENSOR)+5)*10;
    delay(10);
  }
  average /= MeasurementsToAverage;
  Serial.print(" ");
  Serial.println(average);

  

  val = average;
  // Update state:
  if (val/prev_val < 0.01) { // photoresistance drops by an order of mag so sensor starts receiving light
    touching = false; // stopped touching 
  } else if (val/prev_val > 100) { // photoresistance raises by an order of mag so sensor stops receiving light
    touching = true; // started touching
  } //else { // readings remain stable, no change in state, calc running mean
    
 // }

  if (!touching) {
    // blink led 
    digitalWrite(LED, HIGH);
    delay(500);
    digitalWrite(LED, LOW);
    delay(500);
  } else {
    delay(500); 
  }
  
  prev_val = val;
}
