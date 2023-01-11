#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


//tecla A, B y X
const int pinX = 8;
const int pinA = 9;
const int pinB = 10;

int stateX = 0;
int pevStateX = 0;

int stateA = 0;
int pevStateA = 0;

int stateB = 0;
int pevStateB = 0;

int lugar = 0;
//estado
int estado = 0; 

int eggStarter0  = 0;

void setup() {
  
  lcd.begin(16, 2);
  pinMode(pinX, INPUT);
  pinMode(pinA, INPUT);
  pinMode(pinB, INPUT);
  
  lcd.print("Termi");
  lcd.setCursor(0,1);
  lcd.print("by lobazok");
}

void QyA(){
      if(eggStarter0 > 10){
        int reply;
      reply = random(10);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("SuperTermi dice:");
      lcd.setCursor(0, 1);

      switch(reply){
        case 0:
        lcd.print("Anarquia");
        break;
        
        case 1:
        lcd.print("Totalitarismo");
        break;
        
        case 2:
        lcd.print("Capitalismo");
        break;
        
        case 3:
        lcd.print("Comunismo");
        break;
        
        case 4:
        lcd.print("Erdogan");
        break;
        
        case 5:
        lcd.print("Milei");
        break;
        
        case 6:
        lcd.print("Micronesia");
        break;
        
        case 7:
        lcd.print("Libertarismo");
        break;

        case 8:
        lcd.print("Derecha");
        break;

        case 9:
        lcd.print("Izquierda");
        break;
      }
      }else{
        int reply;
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
      estado = 1;
}


void loop() {
  stateX = digitalRead(pinX);
  stateA = digitalRead(pinA);
  stateB = digitalRead(pinB);

  if(stateX != pevStateX || stateA != pevStateA || stateB != pevStateB){
   if(estado == 0){
    if(lugar == 0){
    lcd.clear();
      lcd.setCursor(0,0);
      lcd.print(")1: QyA 2: ???");
      lcd.setCursor(0, 1);
      lcd.print("by lobazok");
      
  }
  if(stateA != pevStateA){
    if(lugar == 0){
      QyA();
    }else{
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("modo no");
      lcd.setCursor(0, 1);
      lcd.print("disponible");
    }
  }
  
  if(stateB != pevStateB){
    if(lugar == 0){
      lugar = 1;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("1: QyA )2: ???");
      lcd.setCursor(0, 1);
      lcd.print("by lobazok");
    }
  }
  
  if(stateX != pevStateX){
    if(lugar == 1){
      lugar = 0;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print(")1: QyA 2: ???");
      lcd.setCursor(0, 1);
      lcd.print("by lobazok");
    }
  }
  }else if(estado == 1){
    if(stateA != pevStateA){
      QyA();
    }else if(stateX != pevStateX){
      estado = 0;
    }else if(stateB != pevStateB){
      if(eggStarter0 < 5){
        eggStarter0 = eggStarter0 + 1;
      }else if(eggStarter0 == 5){
        lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("SuperTemi");
      lcd.setCursor(0, 1);
      lcd.print("desbloqueado");
      }else if(eggStarter0 > 5){
        eggStarter0 = eggStarter0 + 1;
      }else if(eggStarter0 > 7){
        lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Modo normal");
      lcd.setCursor(0, 1);
      lcd.print("eggStarter 0");
      }
    }
   }
 }

 //actualizamos estado
 pevStateX = stateX;
 pevStateA = stateA;
 pevStateB = stateB;
} 
