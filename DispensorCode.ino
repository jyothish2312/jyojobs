#include <Servo.h>
#include <EEPROM.h>

//servo, sensor, RGB LEDs and Reset button are wired according to the following allocation: 

int counter;  //number of times dispensing has happened
int pumpvol= 5; //volume of pump per dispense
int sensorpin = 7;  //arduino pin the sensor is plugged to 
int servopin = 8; //arduino pin the servo is plugged to 
int minpos = 0;   // initial position of the servo in unpumped state
int maxpos = 180; // final position of the servo when pump is completely pressed
int resetpin = 3; // button to activate counter reset function

// debounce function is used to verify any button inputs; as is required for the counter reset function.
bool debounce(int pin){
  int A = digitalRead(pin);
  delay(30);
  int B = digitalRead(pin);
  if(A == B){return A;}
  else{debounce(pin);}
}

//reset function will reset the counter and 0 address of the EEPROM to 0 when called for
void reset(){
  delay(3000);    // it is required to hold the button for 3 seconds for the reset function to begin it's job
  // after 3 seconds, another reading is taken, which, if matched HIGH, will reset the values
  if((debounce(resetpin)) == 1){ 
  EEPROM.write(0,0);
  counter = EEPROM.read(0);
  }
  }

Servo jyoservo;   
int red=9;    //red led pin
int green = 10; //green led pin 
int blue = 11;  //blue led pin

//********************************************************************************************************************
//********************************************************************************************************************

void setup() {
  counter = EEPROM.read(0); // value of counter is set to the last value of the counter- which was stored in the first address of the EEPROM
  pinMode(sensorpin, INPUT); 
  jyoservo.attach(servopin);   //servo is attached to pin number servopin
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
  jyoservo.write(minpos);   //servo is set to it's initialisation position
  Serial.begin(9600);   //serial communication is started at frequency 9600
 }

void loop() {
//STEP 1: Loop initialisation
  //STEP 1-A: Start the program by an option to reset the counter. if someone holds the reset button for 3 seconds, the counter resets
  if((debounce(resetpin))==HIGH){
    reset();
  }

  //in standby state, the indicator is blue
  digitalWrite(blue,HIGH);
   // STEP 1-B: with every loop, the information about the current statistics is printed in the serial monitor
  Serial.print("Current value of counter is: ");
  Serial.println(counter);
  Serial.print("and amount of sanitizer dispensed in mililiter is approximately =  ");
  Serial.println((counter*pumpvol));
  delay(100);
  //*********************initialisation complete*****************************************************
  
//STEP 2: the sensor status is checked and if activated, dispensor is activated 
      //STEP 2-A: sensor is checked
  if((digitalRead(sensorpin))== HIGH){
      //STEP 2-B: necessary indicators are given/changed
    digitalWrite(blue,LOW);
    digitalWrite(green,HIGH);
      //STEP 2-C: servo is activatedto begin the dispensing.
    jyoservo.write(maxpos);
    delay(1000);
    jyoservo.write(minpos);
    delay(1000);
     
     // STEP 2-D: conter value is increased and EEPROM value is set to counter value.
     counter = counter+1;
     EEPROM.write(0, counter);
     //***************************Action is completed**************************************************
     
    }
    
   else{
    //in lack of an activation from sensor, always send the servo to initial position
    jyoservo.write(minpos);
    delay(1000);
   }
   

}
