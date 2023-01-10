#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int switchPin = 6;
int switchState = 0;
int prevswitchState = 0;
int reply;

void setup() {
  Serial.begin(9600);
  Serial.println("Iniciado");
  
  lcd.begin(16, 2);
  pinMode(switchPin, INPUT);
  
  lcd.print("Preguntale a");
  lcd.setCursor(0,1);
  lcd.print("Termi");
}

void loop() {
  switchState = digitalRead(switchPin);

  if(switchState != prevswitchState){
    Serial.println("cambio de valor");
    if(switchState == HIGH){
      reply = random(8);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Termi dice:");
      lcd.setCursor(0, 1);

      switch(reply){
        case 0:
        lcd.print("No se");
        break;
        
        case 1:
        lcd.print("Me da igual");
        break;
        
        case 2:
        lcd.print("2 + 2 = 4");
        break;
        
        case 3:
        lcd.print("2 + 2 = 5");
        break;
        
        case 4:
        lcd.print("Si");
        break;
        
        case 5:
        lcd.print("No");
        break;
        
        case 6:
        lcd.print("PHP");
        break;
        
        case 7:
        lcd.print("JavaScript");
        break;
      }
   }
 }
 prevswitchState = switchState;
}
