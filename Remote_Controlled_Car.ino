int VrxAnalogPin = A5; // potentiometer input that contros Servo motors (0 - 1024)
int VryAnalogPin = A6; // Potentiometer inptut that controls DC motors (0 - 1024)

int ENA_pin = 5; // This has to be PWM output pin
int IN1_pin = 6; // Digital out
int IN2_pin = 7; // Digital out
int IN3_pin = 8; // Digital out
int IN4_pin = 9; // Digital out
int ENB_pin = 10; // This has to be a PWM output pin

void move_motors(int AnalogIn_pin, int ENA_pin, int InOdd_pin, int InEven_pin); // This a funciton I defined


void setup() {
  Serial.begin(9600);           //  setup serial

  pinMode(VrxAnalogPin, INPUT); // setup the inptut pins
  pinMode(VrxAnalogPin, INPUT);

  pinMode(ENA_pin, OUTPUT); //setup the output pins
  pinMode(IN1_pin, OUTPUT);
  pinMode(IN2_pin, OUTPUT);
  pinMode(IN3_pin, OUTPUT);
  pinMode(IN4_pin, OUTPUT);
  pinMode(ENB_pin, OUTPUT);

  
  
}

void loop() 
{
  move_motors(VrxAnalogPin, ENA_pin, IN1_pin, IN2_pin);
}
 


void move_motors(int AnalogIn_pin, int EN_pin, int InOdd_pin, int InEven_pin) // This is the funtion that will send the data out from the arduino into the L298N Board
{
  int velocity_int = analogRead(AnalogIn_pin);

  if (velocity_int < 495) //X joystick is moving left
  {
   
    digitalWrite(InOdd_pin, LOW);
    digitalWrite(InEven_pin, HIGH);

    analogWrite(EN_pin, velocity_int/4);
   
    }
    
  else if(velocity_int > 505 ) // X joysticj is moving right
  {
    digitalWrite(InOdd_pin, HIGH);
    digitalWrite(InEven_pin, LOW);

    analogWrite(EN_pin, velocity_int/4);
    }
    
  else // Not moving
  { 
    digitalWrite(InOdd_pin, LOW);
    digitalWrite(InEven_pin, LOW);

    analogWrite(EN_pin, LOW);
    }
  }

  
