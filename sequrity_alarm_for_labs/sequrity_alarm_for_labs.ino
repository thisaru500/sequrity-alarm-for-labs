#include<Wire.h>
#include< LiquidCrystal_I2C.h>


/*A0 = MQ 05 :- tocheaking ntral gases and DETECT LP GASES
 * NORMAL RANGE 230
 * 230-550 NORML GAS POWER BUT DANGER
 * GAS POWER>550 DANGER AND TURN ON BUZZER
 * 
 *A1= MQ-135 :- TO CHEAKING AIR QUALITY
 * VALUE = 60,180 NOMAL
 * VALUE>180 DANGER
 * 
 * A2 = LDR SENSOR
 * A3 = TEMPURATURE SENSOR LM-35  TEMPURATURE = VOLTAGE*100
 */

int pirsensor = 3;
int flamesensor = 4;
int buzzer1 = 5;//gas sensor buzzer
int buzzer2 = 6;//air quality buzzer , fire buzzer
int relay = 7;//for turn on 230v led light
void setup() {
 

}

void loop() {
  

}
