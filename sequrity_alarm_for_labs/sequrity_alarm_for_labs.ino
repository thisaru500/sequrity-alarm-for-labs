#include<Wire.h>
#include< LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,2,1,0,4,5,6,7,3, POSITIVE);


/*A0 = MQ 05 :- tocheaking ntral gases and DETECT LP GASES
 * NORMAL RANGE 230
 * 230-550 NORML GAS POWER BUT DANGER
 * GAS POWER>550 DANGER AND TURN ON BUZZER
 * 
 *A1= MQ-135 :- TO CHEAKING AIR QUALITY
 * VALUE = 60,180 NOMAL
 * VALUE>180 DANGER
 * 
 * A2 = LDR SENSOR  sensor value>200 it is day time SENSOR value<100 it's night time
 * A3 = TEMPURATURE SENSOR LM-35  TEMPURATURE = VOLTAGE*100
 */

int pirsensor = 3;
int flamesensor = 4;
int buzzer1 = 5;//gas sensor buzzer
int buzzer2 = 6;//air quality buzzer , fire buzzer
int relay1 = 7;//for turn on 230v led light
int relay2 = 10;// turn on door motor
int rled = 8;// red led for day time
int gled = 9;// green led for night time


void setup() {
 Serial.begin(9600);
 lcd.begin(16,4);
 
pinMode(pirsensor,INPUT);
pinMode(flamesensor,INPUT);
pinMode(buzzer1,OUTPUT);
pinMode(buzzer2,OUTPUT);
pinMode(relay1,OUTPUT);
pinMode(relay2,OUTPUT);

}

void loop() {

  // Geting analog values

  int lpgas = analogRead(A0); //to get gas sensor values
  int airquality = analogRead(A1); // to get air quality walues
  int ldr = analogRead(A2); //to get ldr values
  int tempsen = analogRead(A3); // to get tempurature values

  //get digital values
  int pirval = digitalRead(pirsensor);// to get pir sensor reading
  int flameval = digitalRead(flamesensor);// to get flame sensor reading

  if(ldr>100){
    digitalWrite(relay1,HIGH);//to turn on 230v led light
    digitalWrite(gled,HIGH); // TO TURN ON GREEN LED
    }

    else{
      digitalWrite(relay1,LOW);
      digitalWrite(rled,HIGH);// TO  turn on red led
      }

      if(pirval == 1){
        digitalWrite(relay2,HIGH);
        delay (1000);
        digitalWrite(relay2,LOW);
        }

        else{
          digitalWrite(relay2,LOW);
        }

       float voltage = tempsen * (5.0/1023.0);
       float temperature = voltage*100;

      Serial.println("temperature = ");
      Serial.print(temperature);

      lcd.setCursor (0,0);
      lcd.print(temperature);

      if(flameval == 1){
        if(temperature>45){
          lcd.setCursor(0,1);
          lcd.print("fire is begin" );

          digitalWrite(buzzer1,HIGH)
          delay(5000);
        }
      }
      if(lpgas>550){
        lcd.setCursor(0,2);
        lcd.print("it is a gas leak");

        digitalWrite(buzzer2 , HIGH);
        delay(5000);
        
      }

      if(airquality>280){

        lcd.setCursor(0,3);
        lcd.print("air quality is not good");
        
        digitalWrite(buzzer1,HIGH);
        delay(2000);
        digitalWrite(buzzer1,LOW);
        
        }
  
  

}
