/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>
int in_pin = 13;
Servo myservo9;  // create servo object to control a servo
Servo myservo5;  // create servo object to control a servo

int val;

int pos = 0;    // variable to store the servo position

void setup() {
  myservo9.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo5.attach(5);
  pinMode(in_pin, INPUT);
}

void loop() {
 
    val = digitalRead(in_pin);
    if (val == HIGH){
      myservo9.write(180);     
      myservo5.write(-90);
    }
    else  {
      myservo9.write(-90);     
      myservo5.write(180);
    }                    
  

}
