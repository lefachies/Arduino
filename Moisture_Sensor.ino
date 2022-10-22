
int moistPin = A3;
int moistVal, soilPercent;
int airVal = 314;
int waterVal = 617;
String moistValStr;
void setup() {
  Serial.begin(9600);
  }

void loop() {
  moistVal = analogRead(moistPin);
  soilPercent = map(moistVal, airVal, waterVal, 0, 100); 
  moistValStr = String(soilPercent);
  Serial.println(moistValStr);
  delay(1000);

  }
