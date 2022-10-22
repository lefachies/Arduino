//Initializing LED Pin
int led_pin1 = 5;
int led_pin2 = 11;
void setup() {
  //Declaring LED pin as output
  pinMode(led_pin1, OUTPUT);
  pinMode(led_pin2, OUTPUT);
}
void loop() {

    analogWrite(led_pin1, 127);


}
