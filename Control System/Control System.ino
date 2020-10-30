#include <Keypad.h>
#include<LiquidCrystal.h>

LiquidCrystal lcd(A0,A1,A2,A3,A4,A5);
const byte ROWS = 4; //empat baris
const byte COLS = 3; //tiga kolom
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#',}
};
byte rowPins[ROWS] = {2,3,4,5}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {6,7,8}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad(makeKeymap(keys),rowPins,colPins,ROWS,COLS);
int KeyCheck = 0;

void setup(){
  Serial.begin(9600);
  lcd.begin(16,2);
  for(int i=2;i<9;i++){
    pinMode(i,OUTPUT);
  }
}

void loop(){
  char key = keypad.getKey();
   if (key)
  {
    if(key == '1'){KeyCheck = 1; Serial.print("1");}
    if(key == '2'){KeyCheck = 1; Serial.print("2");}
    if(key == '3'){KeyCheck = 1; Serial.print("3");}
    
    if(key == '4'){KeyCheck = 1; Serial.print("4");}
    if(key == '5'){KeyCheck = 1; Serial.print("5");}
    if(key == '6'){KeyCheck = 1; Serial.print("6");}

    if(key == '7'){KeyCheck = 1; Serial.print("7");} 
    if(key == '8'){KeyCheck = 1; Serial.print("8");} 
    if(key == '9'){KeyCheck = 1; Serial.print("9");}

    if(key == '*'){KeyCheck = 1; Serial.print("*");} 
    if(key == '0'){KeyCheck = 1; Serial.print("0");} 
    if(key == '#'){KeyCheck = 1; Serial.print("#");}
    if(KeyCheck == 0){Serial.print(key);}
    KeyCheck = 0; 
  }
  if(Serial.available()>0){
    int k = Serial.parseInt();
    if(k == 91){
      lcd.setCursor(0,0);
      lcd.print("GAS DETECTED");
    }
    else if(k == 90){
      lcd.setCursor(0,0);
      lcd.print("GAS NOT DETECTED");
    }
    else if(k == 101){
      lcd.setCursor(0,1);
      lcd.print("FLAME DETECTED");
    }
    else if(k == 100){
      lcd.setCursor(0,1);
      lcd.print("FLAME NOT DETECTED");
    }
  }
}
