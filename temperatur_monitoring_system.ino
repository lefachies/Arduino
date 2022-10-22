
const int gate_pin = 16;  // 16 corresponds to GPIO16
const int trigger_pin = 5;



 
void setup(){
Serial.begin(115200); 
pinMode(gate_pin, OUTPUT);
pinMode(trigger_pin, INPUT);
}
 
void loop(){
  bool state = digitalRead(trigger_pin);
  if(state){
      digitalWrite(gate_pin, HIGH);
      delay(100);
      digitalWrite(gate_pin, LOW);
    }
}
