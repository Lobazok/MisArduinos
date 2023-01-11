#include <LiquidCrystal.h>
    LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


//tecla A, B y X
const int pinX = 8;
const int pinA = 9;
const int pinB = 10;

//estado X
int stateX = 0;
int pevStateX = 0;

//estado A
int stateA = 0;
int pevStateA = 0;

//estado B
int stateB = 0;
int pevStateB = 0;

int lugar = 0; //lugar del menu

//estado
int estado = 0;

//
int easterEgg = 0;

void setup() {

    //definimos botones
    pinMode(pinX, INPUT);
    pinMode(pinA, INPUT);
    pinMode(pinB, INPUT);

    lcd.begin(16, 2);

    lcd.print("Termi");
    lcd.setCursor(0, 1);
    lcd.print("by lobazok");
}

void QyA(){
    if (easterEgg > 6) {
        int reply;
        reply = random(12);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("SuperTermi dice:");
        lcd.setCursor(0, 1);

        switch (reply) {
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

            case 10:
                lcd.print("Viva la libertad");
                break;

            case 11:
                lcd.print("Andres Corvalan");
                break;
        }
    } else {
        int reply;
        reply = random(8);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Termi dice:");
        lcd.setCursor(0, 1);

        switch (reply) {
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

    if (stateX == HIGH || stateA == HIGH || stateB == HIGH) {
        if (stateX != pevStateX || stateA != pevStateA || stateB != pevStateB) {

            //menu
            if (estado == 0) {
                //ir a un minijuego
                if (stateA != pevStateA) {
                    if (lugar == -1) {
                        lcd.clear();
                        lcd.setCursor(0, 0);
                        lcd.print("Termi");
                        lcd.setCursor(0, 1);
                        lcd.print("Easter Egg 1");
                    }else if (lugar == 0) {
                        QyA();
                    } else {
                        lcd.clear();
                        lcd.setCursor(0, 0);
                        lcd.print("modo no");
                        lcd.setCursor(0, 1);
                        lcd.print("disponible");
                    }
                }


                //mover >>>
                if (stateB != pevStateB) {
                    
                    if (lugar == -1) {
                        lugar = 0;
                        lcd.clear();
                        lcd.setCursor(0, 0);
                        lcd.print(")1: QyA 2: ???");
                        lcd.setCursor(0, 1);
                        lcd.print("by lobazok");
                    }else if (lugar == 0) {
                        lugar = 1;
                        lcd.clear();
                        lcd.setCursor(0, 0);
                        lcd.print("1: QyA )2: ???");
                        lcd.setCursor(0, 1);
                        lcd.print("by lobazok");
                    }
                }

                //mover <<<
                if (stateX != pevStateX) {
                    if (lugar == 0) {
                        lugar = -1;
                        lcd.clear();
                        lcd.setCursor(0, 0);
                        lcd.print("Termi");
                        lcd.setCursor(0, 1);
                        lcd.print("by lobazok");
                    }else if (lugar == 1) {
                        lugar = 0;
                        lcd.clear();
                        lcd.setCursor(0, 0);
                        lcd.print(")1: QyA 2: ???");
                        lcd.setCursor(0, 1);
                        lcd.print("by lobazok");
                    }
                }
            } else if (estado == 1) {
                if (stateA != pevStateA) {
                    QyA();
                } else if (stateX != pevStateX) {
                    estado = 0;
                    lcd.clear();
                    lcd.setCursor(0, 0);
                    lcd.print(")1: QyA 2: ???");
                    lcd.setCursor(0, 1);
                    lcd.print("by lobazok");
                } else if (stateB != pevStateB) {
                    easterEgg = easterEgg + 1;
                    if (easterEgg == 7) {
                        lcd.clear();
                        lcd.setCursor(0, 0);
                        lcd.print("SuperTemi");
                        lcd.setCursor(0, 1);
                        lcd.print("desbloqueado");
                        easterEgg = easterEgg + 1;
                    } else if (easterEgg > 9) {
                        easterEgg = 0;
                        lcd.clear();
                        lcd.setCursor(0, 0);
                        lcd.print("Modo normal");
                        lcd.setCursor(0, 1);
                        lcd.print("eggStarter 0");
                    }

                }
            }
        }
    }

    //actualizamos estado
    pevStateX = stateX;
    pevStateA = stateA;
    pevStateB = stateB;
} 
