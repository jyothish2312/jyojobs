/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include <IRremote.h>

#include <Servo.h>


int RECV_PIN = A0;

IRrecv irrecv(RECV_PIN);


Servo jyoservo_1;
Servo jyoservo_2;
Servo jyoservo_3;
Servo jyoservo_4;
Servo jyoservo_5;
int pos =0;
decode_results results;

void setup()
{
  
  irrecv.enableIRIn(); 
  jyoservo_1.attach(3);
  jyoservo_2.attach(6);
  jyoservo_3.attach(7);
  jyoservo_4.attach(9);
  jyoservo_5.attach(10);
 
}

void loop() {
 if (irrecv.decode(&results)) {
  if (results.value==0xFFA25D){ //Move the servo to 35 degrees position
 // You've gotto change these hexadecimal values(0xE0E...) to button values corresponding to your remote
 
    jyoservo_1.write(20);
    delay(15);
    jyoservo_2.write(20);
    delay(35);
    jyoservo_3.write(20);
    delay(55);
    jyoservo_4.write(20);
    delay(75);
    jyoservo_5.write(20);
    delay(95);

   }
    if (results.value==0xFFE21D){//add +10 degress to servo position
 if(pos<180){
     pos=pos+10;
    jyoservo_1.write(pos);
    delay(15);
    jyoservo_2.write(pos);
    delay(15);
    jyoservo_3.write(pos);
    delay(15);
    jyoservo_4.write(pos);
    delay(15);
    jyoservo_5.write(pos);
    delay(15);
    }}
  
  if (results.value==0xFF629D){ //move the servo to 170 degrees position
 
    jyoservo_1.write(180);
    delay(15);
    jyoservo_2.write(180);
    delay(35);
    jyoservo_3.write(180);
    delay(55);
    jyoservo_4.write(180);
    delay(75);
    jyoservo_5.write(180);
    delay(95);
    }
       if (results.value==0xFF22DD){// decrease servo position by 10
       if(pos>0){
  pos=pos-10;
       jyoservo_1.write(pos);
    delay(15);
    jyoservo_2.write(pos);
    delay(15);
    jyoservo_3.write(pos);
    delay(15);
    jyoservo_4.write(pos);
    delay(15);
    jyoservo_5.write(pos);
    delay(15);
    }}
    if (results.value==0xFF02FD){ //move the servo to 170 degrees position
 
    jyoservo_1.write(20);
    delay(15);
    jyoservo_2.write(20);
    delay(15);
    jyoservo_3.write(20);
    delay(15);
    jyoservo_4.write(180);
    delay(15);
    jyoservo_5.write(20);
    delay(15);
    }
    if (results.value==0xFFC23D){ //move the servo to 170 degrees position
 
    jyoservo_1.write(20);
    delay(15);
    jyoservo_2.write(20);
    delay(15);
    jyoservo_3.write(180);
    delay(15);
    jyoservo_4.write(180);
    delay(15);
    jyoservo_5.write(20);
    delay(15);
    }
    if (results.value==0xFFE01F){ //move the servo to 170 degrees position
 
    jyoservo_1.write(20);
    delay(15);
    jyoservo_2.write(180);
    delay(35);
    jyoservo_3.write(180);
    delay(55);
    jyoservo_4.write(180);
    delay(75);
    jyoservo_5.write(20);
    delay(95);
    }
    if (results.value==0xFFA857){ //move the servo to 170 degrees position
 
    jyoservo_1.write(180);
    delay(15);
    jyoservo_2.write(180);
    delay(35);
    jyoservo_3.write(180);
    delay(55);
    jyoservo_4.write(180);
    delay(75);
    jyoservo_5.write(20);
    delay(95);
    }
    if (results.value==0xFF38C7){ //move the servo to 170 degrees position
 
    jyoservo_1.write(20);
    delay(15);
    jyoservo_2.write(20);
    delay(35);
    jyoservo_3.write(180);
    delay(55);
    jyoservo_4.write(20);
    delay(75);
    jyoservo_5.write(20);
    delay(95);
    }
  
  irrecv.resume();
 
}
  
}
