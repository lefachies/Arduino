
// the setup function runs once when you press reset or power the board


void setup() {
  int LEDs[] = {2, 3, 4, 10, 11, 12, A5, A6, A7};
  // initialize digital pin LED_BUILTIN as an output
  for(int i = 0; i <= 8; ++i)
  {
    pinMode(LEDs[i], OUTPUT);
    }
  
}


void loop() {
  int LEDs[] = {2, 3, 4, 10, 11, 12, A5, A6, A7};

    for(int i = 0; i <= 8; ++i)
  {
    digitalWrite(LEDs[i], HIGH);
    }
    
  delay(750);  
  
   for(int i = 0; i <= 8; ++i)
  {
    digitalWrite(LEDs[i], LOW);
    }
 
  delay(750);                     
}
