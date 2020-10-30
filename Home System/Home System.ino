void setup() {
  Serial.begin(9600);
  for(int i = 2;i<=8;i++){
    pinMode(i,OUTPUT);
  }
  pinMode(9,INPUT);
  pinMode(10,INPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(14,OUTPUT);
  Serial.print("Simulation Home Automation with XBee");
  Serial.println();
  Serial.println("CERDAS Bersama Damelia");
  Serial.println();
}

int i,state = 0;
int high9 = 0, high10 = 0;
int DataCheck = 0;

void loop() {
 if(Serial.available())
  {
    char data = Serial.read();
    Serial.print(data);
    Serial.print("    -->  ");
    
    if(data == '1'){DataCheck = 1; digitalWrite(2, HIGH); Serial.println("Lampu dapur menyala");}
    if(data == '2'){DataCheck = 1; digitalWrite(13, HIGH); Serial.println("Lampu kamar tidur menyala");}
    if(data == '3'){DataCheck = 1; digitalWrite(14, HIGH); Serial.println("Lampu ruang keluarga menyala");} 
    if(data == '4'){DataCheck = 1; digitalWrite(2, LOW); Serial.println("Lampu dapur mati");}
    if(data == '5'){DataCheck = 1; digitalWrite(13, LOW); Serial.println("Lampu kamar tidur mati");}
    if(data == '6'){DataCheck = 1; digitalWrite(14, LOW); Serial.println("Lampu ruang keluarga mati");}

    if(data == '7'){DataCheck = 1; digitalWrite(12, LOW);digitalWrite(11, HIGH); Serial.println("Kipas dapur menyala");} 
    if(data == '8'){DataCheck = 1; digitalWrite(6, LOW);digitalWrite(5, HIGH); Serial.println("Kipas kamar tidur menyala");}
    if(data == '9'){DataCheck = 1; digitalWrite(7, LOW);digitalWrite(8, HIGH); Serial.println("Kipas ruang keluarga menyala");}
    if(data == '*'){DataCheck = 1; digitalWrite(12, LOW);digitalWrite(11,  LOW); Serial.println("Kipas dapur mati");}
    if(data == '0'){DataCheck = 1; digitalWrite(6, LOW);digitalWrite(5, LOW); Serial.println("Kipas kamar tidur mati");}
    if(data == '#'){DataCheck = 1; digitalWrite(7, LOW);digitalWrite(8,  LOW); Serial.println("Kipas ruang keluarga mati");}
    if(DataCheck == 0){Serial.println("Perintah Salah. Silakan ulangi !!! ");}
    Serial.println();
    DataCheck = 0;
  }

 if(digitalRead(9)==1 && high9 ==0){
  Serial.print(91);
  Serial.println("    -->  GAS DETECTED");
  Serial.println();
  high9 = 1;
 }
 else if(digitalRead(9)==0 && high9 == 1){
  Serial.print(90);
  Serial.println("    -->  GAS NOT DETECTED");
  Serial.println();
  high9 = 0;
 }
 else if(digitalRead(10)==1 && high10 ==0){
  Serial.print(101);
  Serial.println("    -->  FLAME DETECTED");
  Serial.println();
  high10 = 1;
 }
 else if(digitalRead(10)==0 && high10 == 1){
  Serial.print(100);
  Serial.println("    -->  FLAME NOT DETECTED");
  Serial.println();
  high10 = 0;
 }
}
