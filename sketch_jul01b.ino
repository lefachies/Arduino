#include <Servo.h>

Servo myservo;  // create servo object to control a servo
Servo myservo2;  // create servo object to control a servo

int potpin = 0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin
int counter = 0;
bool flag = false;

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo2.attach(11);  // attaches the servo on pin 9 to the servo object
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop() {
  counter += 1;
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  myservo.write(val);  
  myservo2.write(val);                 // sets the servo position according to the scaled value
  if(counter == 1000)
  {
  flag = !flag;
  digitalWrite(3, flag);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(4, flag);
  counter = 0;
  }
}
