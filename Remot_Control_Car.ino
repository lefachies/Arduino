int digital_Pins[] = {3, 5 ,6 ,7 ,10 ,11 ,12};
int analog_Pins[] = {A1, A2, A3, A4};
int del_Time = 1000;

void setup() {
  Serial.begin(9600);
  for (int i = 0; i <= 6; i++)
  {
    pinMode(digital_Pins[i], OUTPUT);
    }

  for (int j = 0; j <= 3; j++)
  {
    pinMode(analog_Pins[j], OUTPUT);
    }
    

void loop() {
//The move forward Values by default if the joy stic is idle is 125.
// Min = 0
//Max = 255


  

}

void Move_Forward()
{
  digitalWrite(analog_Pins[2], LOW);
  digitalWrite(analog_Pins[3], HIGH);
  }

void Move_Backwards()
{
  digitalWrite(analog_Pins[2], HIGH);
  digitalWrite(analog_Pins[3], LOW);
  }

void Turn_Right()
{
  digitalWrite(analog_Pins[0], LOW);
  digitalWrite(analog_Pins[1], HIGH);
  }

  void Turn_Left()
{
  digitalWrite(analog_Pins[0], HIGH);
  digitalWrite(analog_Pins[1], LOW);
  }
  
void Grab_Wheel_Speed(int wheel_Speed_Recived)
{
  analogWrite(digital_Pins[0], wheel_Speed_Recived);
  
  }


  void Grab_Turn_Radius(int turn_Radius_Recived)
{
  analogWrite(digital_Pins[1], turn_Radius_Recived);
    
  }
/*
int recive_Speed_Turn_Values()
{
  return 
  }
*/
void wheel_Speed_and_Direction(int wheel_Value)
{
  if(wheel_Value > 125)
    Move_Forward();
  if(wheel_Value < 125)
    Move_Backwards();
  Grab_Wheel_Speed(wheel_Value * 2);
    
  }

void Turn_Radius_and_Direction(int turn_Value)
{
  if(turn_Value > 125)
    Turn_Right();
  if(turn_Value < 125)
    Turn_Left();
  Grab_Turn_Radius(turn_Value * 2);
    
  }
  
