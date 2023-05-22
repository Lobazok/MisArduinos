#include <LiquidCrystal.h>

LiquidCrystal lcd(0, 1, 2, 4, 7, 8);

int contrast = 0;

//tecla A, B y X
const int pinA = 12;
const int pinB = 10;
const int pinX = 9;

const int pinTrans = 11;

const int piezo = 3;

//estado X
int stateX = 0;
int pevStateX = 0;

//estado A
int stateA = 0;
int pevStateA = 0;

//estado B
int stateB = 0;
int pevStateB = 0;

int lugar = 0; //p del menu
int menu = 0; //lugar del menu

int tonito = 500;

// Tabla de letras Morse
const char* morseLetters[] = {
  ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..",
  "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."
};

// Variables para el código Morse
String morseCode = "";
String currentLetter = "";

unsigned long tiempoInicio = 0;  // Variable para almacenar el tiempo de inicio de la pulsación
String pulsaciones = "";  // Cadena para almacenar las pulsaciones
String pulsacionesPantalla = "";

String obtenerUltimos16(String cadena) {
  int longitudTotal = cadena.length();
  
  if (longitudTotal <= 16) {
    return cadena;
  } else {
    int indiceInicial = longitudTotal - 16;
    return cadena.substring(indiceInicial);
  }
}

void setup() {

    //definimos botones
    pinMode(pinX, INPUT);
    pinMode(pinA, INPUT);
    pinMode(pinB, INPUT);
  
    pinMode(pinTrans, OUTPUT);
  
    pinMode(6, OUTPUT);
    pinMode(5, OUTPUT);
    lcd.begin(16, 2);

    lcd.print("Termi");
    lcd.setCursor(0, 1);
    lcd.print("by lobazok");
}



void loop() {
  lcd.clear();
  if (menu == 4){
          if(stateA == HIGH){ 
            pulsaciones += "1";
          }else{ 
            pulsaciones += "0";
          }
    if(stateB == HIGH){ 
      for (int i = 0; i < pulsaciones.length(); i++) {
        char pulso = pulsaciones[i];
        if(pulso == '1'){
          digitalWrite(pinTrans , HIGH);
        }else digitalWrite(pinTrans , LOW);
        delay(500);
      }
   }
  }
  analogWrite(6, contrast);
  
   stateX = digitalRead(pinX);
   stateA = digitalRead(pinA);
   stateB = digitalRead(pinB);


    if (stateX == HIGH || stateA == HIGH || stateB == HIGH) {
        if (stateX != pevStateX || stateA != pevStateA || stateB != pevStateB) {
         tone(piezo,tonito , 100);
            if(stateA == HIGH & lugar > 0){
              lugar--;
              
            }else{
              if(stateB == HIGH & lugar < 5){
              lugar++;
              }
            }
            
            
            
          }else if(menu == 1){
            
            if(stateA == HIGH & contrast > 0){
              contrast = contrast - 5;
              
            }else if(stateB == HIGH & contrast < 100){
              contrast = contrast + 5;
             }else if(stateX == HIGH){
              menu = 0;
              lugar = 0;
             
            }
            
            
          }else if(menu == 2){
            
            if(stateA == HIGH & tonito > 50){
              tonito = tonito - 50;
              
            }else if(stateB == HIGH & tonito < 1000){
              tonito = tonito + 50;
             }else if(stateX == HIGH){
              menu = 0;
              lugar = 0;
             
            }
            
            
        }else if (menu == 4){

        }
         
           if(menu == 0){
            if(stateX == HIGH){ 
            if(lugar == 0){
              
              menu = 1;
            }else if(lugar == 1){
              
              menu = 2;
            }else if(lugar == 2){
              
              menu = 3;
            }else if(lugar == 3){
              
              menu = 4;
            }
          }
        }else if(menu != 0){
            if(stateX == HIGH){ 
              menu = 0;
          }
        }

    }

     
  if(menu == 0){
    if(lugar == 0){
       lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("> contrase ");
        lcd.setCursor(0, 1);
        lcd.print("  tono");
     }else if(lugar == 1){
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("> tono");
        lcd.setCursor(0, 1);
        lcd.print("  temperatura");
     }else if(lugar == 2){
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("> temperatura");
        lcd.setCursor(0, 1);
        lcd.print("  morse");
     }else if(lugar == 3){
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("> morse");
        lcd.setCursor(0, 1);
        lcd.print("");
     }else if(lugar == 4){
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("By el mejor");
        lcd.setCursor(0, 1);
        lcd.print("equipo del ACLE!");
     }else  if(lugar == 5){
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Tesli");
        lcd.setCursor(0, 1);
        lcd.print("prueba v0.1");
     }else{
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Tesli");
        lcd.setCursor(0, 1);
        lcd.print("prueba v0.1");
     }
  }
    
  if(menu == 1){
    
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("- contrase +");
    lcd.setCursor(0, 1);
    lcd.print("contrase: ");
    lcd.print(contrast);
  }else if(menu == 2){
    
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("- tono +");
    lcd.setCursor(0, 1);
    lcd.print("tono: ");
    lcd.print(tonito);
  }else if(menu == 3){
    // el volor del sensor es TMPval
  int TPMval = analogRead(A1);
  float voltaje = (TPMval / 1024.0) * 5;
  float temperatura = (voltaje - .5) * 100;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("temperatura en C");
    lcd.setCursor(0, 1);
    
    lcd.print(temperatura);
    lcd.print("c");
  }if(menu == 4){
      pulsacionesPantalla = obtenerUltimos16(pulsaciones);
    
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(pulsacionesPantalla);
    lcd.setCursor(0, 1);
    lcd.print("morse sin cifrado");
  }else
    //actualizamos estado
    pevStateX = stateX;
    pevStateA = stateA;
    pevStateB = stateB;
  delay(250);
}
