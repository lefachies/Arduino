int joystick_X = A0;
int joystick_Y = A1;
unit8_t

void setup() {
  pinMode(joystick_X, INPUT);
  pinMode(joystick_Y, INPUT);
  Serial.begin(9600);
  

}

void loop() {
int x_Value = map(analogRead(joystick_X), 0, 1023, 0, 255);
  Serial.print(x_Value);
  Serial.print("\n");

int y_Value = map(analogRead(joystick_y), 0, 1023, 0, 255);
  Serial.print(y_Value);
  Serial.print("\n");
  //Serial.print(analogRead(joystick_Y));
  Serial.print("\n");
}
