// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


// Define the buttons and the LED light pins
const int p1_button = 10, button_1 = 9, button_2 = 8, button_3 = 7, p2_button = 6, p1_light = 0, p2_light = 1;

// Define the time variables that will be used
unsigned int minutes = 0, seconds = 0;

// This is used to tell us what time is currently running
bool p1_flag = true;
bool p2_flag = false;

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  
  // Set which pins will be the inputs and which pins will be the outputs
 pinMode(p1_button, INPUT);
 pinMode(button_1, INPUT);
 pinMode(button_2, INPUT);
 pinMode(button_3, INPUT);
 pinMode(p2_button, INPUT);



 attachInterrupt(digitalPinToInterrupt(p1_button), ISR_p1_button, RISING)
}

void loop() {

first_screen();
second_screen();
third_screen();
fourth_screen();

}

void first_screen(){
  lcd.clear();
  bool flag = true;
  lcd.setCursor(0, 0);
  lcd.print("Set Time");
  lcd.setCursor(1, 1);
  lcd.print("Minutes: ");
  
  while(flag){
    if(digitalRead(button_1) == HIGH){
      minutes++;
      delay(250);}

      else if((digitalRead(button_2) == HIGH) && minutes > 0){
        minutes--;
        delay(250);}

      else if (digitalRead(button_3) == HIGH){
        flag = false;
        delay(250);
        }

      lcd.setCursor(10, 2);
      lcd.print(minutes);
      lcd.print(" ");
    }
  }

void second_screen(){
  lcd.clear();
  bool flag = true;
  lcd.setCursor(0, 0);
  lcd.print("Add Per Turn");
  lcd.setCursor(1, 1);
  lcd.print("Seconds: ");
  
  while(flag){
    if(digitalRead(button_1) == HIGH){
      seconds++;
      delay(250);}

    else if((digitalRead(button_2) == HIGH) && seconds > 0){
      seconds--;
      delay(250);}

    else if (digitalRead(button_3) == HIGH){
      flag = false;
      delay(250);
        }

      lcd.setCursor(10, 2);
      lcd.print(seconds);
      lcd.print(" ");
    }  
  }

void third_screen(){  
  lcd.clear();
  bool flag = true;
  lcd.setCursor(0, 0);
  lcd.print("Black");
  lcd.setCursor(9, 0);
  lcd.print("White");

  while(flag){
    if(digitalRead(button_1) == HIGH){
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Black");
      lcd.setCursor(9, 0);
      lcd.print("White");
      p1_flag = true;
      p2_flag = false;
      delay(250);}

    else if((digitalRead(button_2) == HIGH) && seconds > 0){
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("White");
      lcd.setCursor(9, 0);
      lcd.print("Black");
      p1_flag = false;
      p2_flag = true;
      delay(250);}

    else if (digitalRead(button_3) == HIGH){
      flag = false;
      delay(250);
        }

    lcd.setCursor(7, 2);
    lcd.print(minutes);
    lcd.print("|");
    lcd.print(seconds);
    lcd.print(" ");
    }  
  }

  void fourth_screen(){
    lcd.clear();
    if (p1_flag){
      lcd.setCursor(0, 0);
      lcd.print("Black");
      lcd.setCursor(9, 0);
      lcd.print("White");}
      
    else{
      lcd.setCursor(0, 0);
      lcd.print("White");
      lcd.setCursor(9, 0);
      lcd.print("Black");}

     bool check_start = 
      
    unsigned int p1_seconds = minutes * 60; // This is how many seconds we have in the timer
    unsigned int p2_seonds = minutes * 60; 
 


    while(p1_seconds > 0 && p2_seconds > 0){

      while(p1_flag){
        
        }
      
      }
  
    
  }


void ISR_p1_button(){
  if(p1_flag)
  }

  
