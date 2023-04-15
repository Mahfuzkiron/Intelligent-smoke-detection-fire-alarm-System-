//Intelligent smoke detection fire alarm System 
// mahfuz kiron

#include <LiquidCrystal_I2C.h>
#define gasSensor A0
#define ledGreen 7
#define ledRed 6
#define buzzer 5
LiquidCrystal_I2C lcd(0x27, 16, 2);
int Gas_value = 0;


void setup() {
  
   Serial.begin(9600);
   lcd.init();               // initialize the lcd
   lcd.backlight();
   
   pinMode(gasSensor, INPUT);
   pinMode(buzzer, OUTPUT);
   pinMode(ledGreen, OUTPUT);
   pinMode(ledRed, OUTPUT);
   Serial.println("Interfacing of Smoke Sensor with Arduino");
   Serial. println("Designed by mahfuz kiron");
   Serial.println();
  }


void loop() {
  
  Gas_value = analogRead(gasSensor);
  lcd.setCursor(0, 0);
  lcd.print("Smoke Level: ");
  lcd.print(Gas_value);
  lcd.print("%");

  lcd.setCursor(0, 1);
  lcd.print(".....Normal.....");
  
  Serial.println(Gas_value);
  


//check data from sensor if there is smoke, if will execute otherwise else will execute

  if(Gas_value >25)
  {
    lcd.clear();
    digitalWrite(ledRed, HIGH);
    lcd.print("    Alert...!!");
    lcd.setCursor(0, 1);
    lcd.print("Smoke Detected!! ");
    lcd.setCursor(0, 1);
    tone(buzzer, 300);
    digitalWrite(ledGreen,LOW); 
    Serial.println("Smoke Detected . . .");
    Serial.println("    Alert...!!");
  }
  
  else
  {
    
    digitalWrite(ledGreen,HIGH);
    digitalWrite(ledRed, LOW);
    lcd.setCursor(0, 2);
    lcd.print(".....Normal.....");
    noTone(buzzer);
    Serial.println(".....Normal.....");
  }
  delay(3000);
  lcd.clear();  
  }
