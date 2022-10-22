int sensor_pin = A0; 
int led_pin = 3;
int output_value ;

void setup() {
  Serial.begin(9600);
  Serial.println("Reading From the Sensor ...");
  delay(2000);
  pinMode(led_pin, OUTPUT);
  }

void loop() {
  output_value= analogRead(sensor_pin);


  Serial.print("Mositure : ");
  while (output_value < 190)
  {
 analogWrite(led_pin, 0);
  output_value= analogRead(sensor_pin);
    Serial.print(output_value);
      Serial.println("%");
  delay(1000);
   }
  while (output_value > 190)
  {
    analogWrite(led_pin, 127);
  output_value= analogRead(sensor_pin);
    Serial.print(output_value);
      Serial.println("%");
  delay(1000);
   }
  }
  
