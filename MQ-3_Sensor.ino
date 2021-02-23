/* This is ABSOLUTELY NOT a relaitable and finished measurment process*/
#define Sober 360   // Define max value that we consider sober
#define Drunk 920   // Based on 15 minute warm up callibration and the measurment of wine (11%)
int sensorValue;


void warm_up(){//takes about 12-20 min to warm up with 5V
  Serial.println("Warming Up");
  for(int i = 0; i<20;i++){
    Serial.print("=");
    delay(45000);
  }
  Serial.println();
}

void setup() {
  Serial.begin(9600);
  warm_up();
}

void loop() {
  sensorValue = analogRead(0); // read analog input pin 0

  Serial.print("Sensor Value: ");
  Serial.print(sensorValue);
  
  // alcohol check
  if (sensorValue < Sober) {
    Serial.println("  |  Status: Stone Cold Sober");
  } else if (sensorValue >= Sober && sensorValue < Drunk) {
    Serial.println("  |  Status: Drinking but within legal limits");
  } else {
    Serial.println("  |  Status: DRUNK");
  }
  
  delay(2000); 
}
