#include <LiquidCrystal.h>

LiquidCrystal lcd(0, 1, 2, 4, 7, 8);

int contrast = 0;

//tecla A, B y X
const int pinA = 13;
const int pinB = 12;
const int pinX = 11;

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

// Función para convertir código Morse a letra
char convertMorseToLetter(String morse) {
  for (int i = 0; i < 26; i++) {
    if (morse == morseLetters[i]) {
      return 'A' + i;
    }
  }
  return '?';
}

// Función para manejar el ingreso de código Morse
void measureMorseCode() {
  if (stateA == HIGH && stateB == LOW) {
    // Botón A presionado
    morseCode += '.';
  } else if (stateA == LOW && stateB == HIGH) {
    // Botón B presionado
    morseCode += '-';
  } else if (stateA == HIGH && stateB == HIGH) {
    // Ambos botones presionados, interpretar el código Morse
    char letter = convertMorseToLetter(morseCode);
    if (letter != '?') {
      currentLetter += letter;
    }
    morseCode = "";
  }
   if (morseCode.length() > 16) {
    morseCode = morseCode.substring(1); // Eliminar el primer carácter
  }
}



void setup() {

    //definimos botones
    pinMode(pinX, INPUT);
    pinMode(pinA, INPUT);
    pinMode(pinB, INPUT);
  
    pinMode(6, OUTPUT);
    pinMode(5, OUTPUT);
    lcd.begin(16, 2);

    lcd.print("Termi");
    lcd.setCursor(0, 1);
    lcd.print("by lobazok");
}



void loop() {
  lcd.clear();
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
          //aqui debes crear una funcion que decteste las teclas A y B, que a sea un 1 y B un 0, con eso debes intepretar y pasar de morse a texto y agregar la letra en texto
          measureMorseCode();
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
        lcd.print("  temp");
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
    
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(morseCode);
    lcd.setCursor(0, 1);
    lcd.print("morse sin cifrado");
  }else
    //actualizamos estado
    pevStateX = stateX;
    pevStateA = stateA;
    pevStateB = stateB;
  delay(200);
}
