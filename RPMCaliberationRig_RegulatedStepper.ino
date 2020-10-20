#include<LiquidCrystal.h>
float rajmachawal;
int nirdesh;
int disha = 10;
int kadam = 11;
int set=13;

LiquidCrystal darpan(2,3,4,5,6,7);

void setup() {
  Serial.begin(9600);
  darpan.begin(16,2);
  pinMode(disha,OUTPUT);
  pinMode (kadam, OUTPUT);
  pinMode(set, INPUT);
  digitalWrite(disha, HIGH);
  digitalWrite(kadam, LOW);

 while(set){
  nirdesh = analogRead(A0);
  nirdesh = map(nirdesh, 0, 1024, 375, 3000);
  rajmachawal = map(nirdesh,375,3000, 400, 50);
  Serial.print("Theoretical RPM Currently: ");
  Serial.println(rajmachawal);
  darpan.setCursor(0,0);
  darpan.print("  Adjust RPM:   ");
  darpan.setCursor(6, 1);
  darpan.print(rajmachawal);
    if(debounce(set)==HIGH){
  break;
  }
 }
  darpan.setCursor(0,0);
  darpan.print("Set RPM:  ");
  darpan.setCursor(10, 0);
  darpan.print(rajmachawal);
  darpan.setCursor(0,1);
  darpan.print("[RST] -to Change");
}

void loop() {
 
digitalWrite(kadam, HIGH);
delayMicroseconds(nirdesh);
digitalWrite(kadam, LOW);
delayMicroseconds(nirdesh);
}

bool debounce(int pin){
bool a= digitalRead(pin);
delay(50);
bool b= digitalRead(pin);
if(a!=b){
debounce(pin);
}
return a;
}
  

  
  
 
