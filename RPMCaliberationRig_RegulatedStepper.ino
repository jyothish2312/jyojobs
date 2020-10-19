#include<LiquidCrystal.h>
float rajmachawal;
float nirdesh;
int deri;
int disha = 10;
int kadam = 11;

LiquidCrystal darpan(2,3,4,5,6,7);

void setup() {
  Serial.begin(9600);
  darpan.begin(16,2);
  pinMode(disha,OUTPUT);
  pinMode (kadam, OUTPUT);
  digitalWrite(disha, HIGH);
}

void loop() {
deri = bakisabbakwas();
digitalWrite(kadam, HIGH);
delayMicroseconds(deri);
digitalWrite(kadam, LOW);
delayMicroseconds(deri);
}

int bakisabbakwas(){
  nirdesh = analogRead(A0);
  nirdesh = map(nirdesh, 0, 1024, 150, 15000);
  rajmachawal = map(nirdesh, 150,15000, 1000, 10);
  Serial.print("Theoretical RPM Currently: ");
  Serial.print(rajmachawal);
  darpan.setCursor(0,0);
  darpan.write("Theoretical RPM:");
  darpan.setCursor(6,1);
  darpan.write(rajmachawal);
  return nirdesh;
}
