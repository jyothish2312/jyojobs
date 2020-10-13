#include <Wire.h>
#include <Adafruit_MLX90614.h>
#include<LiquidCrystal.h>

LiquidCrystal jyo(2,3,4,5,6,7); // LiquidCrystal object jyo attached to the pins rs, en, 4,5,6,7
Adafruit_MLX90614 mlx = Adafruit_MLX90614();
float objtemp;
float ambtemp;

void setup() {
  Serial.begin(9600);
  Serial.println("Adafruit MLX90614 test");  
  jyo.begin(16, 2); // 16x2 display initiated
  mlx.begin();  
}


void loop() {

  objtemp = mlx.readObjectTempC();
  ambtemp = mlx.readAmbientTempC();
  Serial.print("Ambient = "); Serial.print(ambtemp); 
  Serial.print("*C\tObject = "); Serial.print(objtemp); Serial.println("*C");
  delay (200);
  jyo.setCursor(0,0);
jyo.print("ObjTem:");
delay(10);
jyo.setCursor(8,0);
jyo.print(objtemp);
delay(10);

  jyo.setCursor(0,1);
jyo.print("(AmbTemp: ");
delay(10);
jyo.setCursor(10,1);
jyo.print(ambtemp);
delay(10);
 jyo.setCursor(15,1);
jyo.print(")");
delay(10);

}
