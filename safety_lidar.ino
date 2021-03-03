#include <Wire.h>
#include <LIDARLite.h>
#include <LiquidCrystal.h>


// Globals
LIDARLite lidarLite;
int cal_cnt = 0;
unsigned long t1 = 0;

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


void setup()
{
  lcd.begin(16, 2);

  Serial.begin(9600);           // Initialize serial connection to display distance readings

  lidarLite.begin(0, true);     // Set configuration to default and I2C to 400 kHz
  lidarLite.configure(0);       // Change this number to try out alternate configurations
}


int dist, v, prev_dist, dt;
void loop()
{
  dt = millis() - t1;
  t1 = millis();
  prev_dist = dist;

  // At the beginning of every 100 readings,
  // take a measurement with receiver bias correction
  if ( cal_cnt == 0 ) {
    dist = lidarLite.distance();              // With bias correction
  } else {
    dist = lidarLite.distance(false);         // Without bias correction
  }

  // Increment reading counter
  cal_cnt++;
  cal_cnt = cal_cnt % 100;


  v = ( (dist - prev_dist) * 1000 ) / dt; // cm/s
  //v *= 36/1000;                                // km/h

  // lcd_display
  /*
    lcd.setCursor(0, 0); // set the cursor on the first row and column
    lcd.print("S = ");
    lcd.print(prev_dist);
    lcd.print(" cm");
    lcd.setCursor(0, 1); //set the cursor on the second row and first column
    lcd.print("V = ");
    lcd.print(v);
    lcd.print(" cm/s");
  */
  Serial.print("S = ");
  Serial.print(dist);
  Serial.println(" cm");
  Serial.print("V = ");
  Serial.print(v);
  Serial.println(" cm/s");
  //Serial.print("dt = ");
  //Serial.println(dt);


  delay(100);
  lcd.clear();
}
