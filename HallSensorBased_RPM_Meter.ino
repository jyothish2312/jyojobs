#include <LiquidCrystal.h> 
LiquidCrystal jyo(2, 3, 4, 5, 6, 7);
long jazbaat;
float halaat = 0.0;
void setup() {
  pinMode(11,INPUT);
  Serial.begin(9600);
  jyo.begin(16,2);
}

void loop() {
 // put your main code here, to run repeatedly:
if(digitalRead(11)==LOW){
for (int i= 0; i<10; i++){
jazbaat = pulseIn(11, LOW);
 halaat= halaat + (1000000/jazbaat);
delay(50);
}

halaat= (halaat/10);
Serial.print("Detected Rev.Per.Min. = ");
Serial.println(halaat);
}
else{
Serial.println("Nothing is Detected");  
delay(50);
}

if (halaat <= 10.0){
jyo.setCursor(0,0);
jyo.print("Chaddi-Pehen-Ke");
jyo.setCursor(0,1);
jyo.print("Phool-Khila-Hai");
}
else{
jyo.setCursor(0,0);
jyo.print("Vhroom-Vhroom");
jyo.setCursor(0,1);
jyo.print("R.P.M.= ");
jyo.setCursor(8,1);
jyo.print(halaat);
}

halaat = 0.0;
}
