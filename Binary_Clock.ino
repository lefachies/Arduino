


//Declaring our Variables and definning what each pin will controll in the clock
int seconds = 0;
int minutes = 0;
int hours = 0;
int hours_Tens[2] = {15, 2};
int hours_Ones[4] = {0, 4, 16, 17};
int minutes_Tens[3] = {5, 18, 19};
int minutes_Ones[4] = {21, 22, 23, 32};
int seconds_Tens[3] = {33, 25, 26};
int seconds_Ones[4] = {27, 13, 14};

//Here we made a list holding the all the list of pins
int columns[] = {*hours_Tens, *hours_Ones, *minutes_Tens, *minutes_Ones, *seconds_Tens, *seconds_Ones};

void setup() {
   //Serial begin
  Serial.begin(115200);
//Now we are enabeling all the pins and setting them to outputs
for (int i = 0; i <= 1; i++)
{
    pinMode(hours_Tens[i], OUTPUT);
  }

 for (int i = 0; i <= 3; i++)
{
   pinMode(hours_Ones[i], OUTPUT);
  }
 
  for (int i = 0; i <= 2; i++)
{
    pinMode(minutes_Tens[i], OUTPUT);
  }

  for (int i = 0; i <= 3; i++)
{
    pinMode(minutes_Ones[i], OUTPUT);
  }

  for (int i = 0; i <= 2; i++)
{
   pinMode(seconds_Tens[i], OUTPUT);
  }
 
  for (int i = 0; i <= 3; i++)
{  
  pinMode(seconds_Ones[i], OUTPUT);
  }

  
 
    
}



//This function you input a decimal digit and then you get an array of 1s and Zero. 
//This is usefull because in the program we will have 3 int values and each int value maps to either
//Hour, min, or seconds
int *convert_To_Binary(int input) 
{
  int binary_Digits[4] = {};

  int remainder;
  
  for(int i = 0; i >= 3; i++)
  {
    remainder = input % 2;
    binary_Digits[i] = remainder;
    input = input - remainder; 
    }
    return binary_Digits;
  }

// For this you accept two strings and it wrtes either high or low to the pins depending on what you took in
 void write_To_Pins(int pins_Array[], int binary_digits[] ) 
 {
  int arry_Length = sizeof(pins_Array)/ sizeof(*pins_Array);
  Serial.print(arry_Length);

  for (int i = 0; i < arry_Length; i++)
  {
    digitalWrite(pins_Array[i], binary_digits[i]);
    }
  
  }

 void activate_Columns(int something_Tens[], int something_Ones[], int something_Value)
 {
  //Since there are two columns, i have to check when i need to have one of them lit and the other not
  // first column is lit if the number is 10 or more

  int multiplier = something_Value % 10;
  int left_Column = multiplier * 10;
  int right_Column = something_Value - left_Column;
  
   
  
  int *left_Column_Binary_Array = convert_To_Binary(left_Column);
  
  int *right_Column_Binary_Array = convert_To_Binary(right_Column);

  write_To_Pins(something_Tens,left_Column_Binary_Array);
  write_To_Pins(something_Ones, right_Column_Binary_Array);
    }

void loop() {
 
  seconds++;
  delay (990);
 
  
  if (seconds == 61)
  {
    seconds = 0;
    minutes++; 
  }  
  
  if(minutes == 61)
  {
    minutes = 0;
    hours++;
   }
   
   if(hours == 25)
   {
    hours = 0;
    } 

   activate_Columns(hours_Tens, hours_Ones, hours);
   activate_Columns(minutes_Tens, minutes_Ones, minutes);
   activate_Columns(seconds_Tens, seconds_Ones, seconds);

     
  }
