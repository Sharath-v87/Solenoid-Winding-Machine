#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 9 , 10, 11, 12, 13); 
int IR1=6;      
int MotorAip1 = 3;
int MotorAip2 = 4;
//LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // sets the interfacing pins
int c=0;
int a=10;
void setup() 
{ 
  lcd.begin(16, 2); // initializes the 16x2 LCD 
  lcd.print("Windings : "); // prints 16x2 LCD MODULE 

  delay(1000);
  pinMode(IR1,INPUT);
  pinMode (MotorAip1, OUTPUT);
  pinMode (MotorAip2, OUTPUT);
}

void loop() 
{ 
        lcd.display();
        delay(900);
        
        if(digitalRead(IR1)==LOW) //IR will not glow on black line
        {
          c=c+1;
          digitalWrite(MotorAip1,HIGH);
          digitalWrite(MotorAip2,LOW);
          lcd.print(c-1);
        }
        if (c>a)
        {
          c=a;
          digitalWrite(MotorAip1,LOW);
          digitalWrite(MotorAip2,LOW);
          delay(100);
        }
//  {
    //Stop both Motors
    //digitalWrite(MotorAip1,LOW);
//    digitalWrite(MotorAip2,LOW);
//    digitalWrite(MotorBip1,LOW);
//    digitalWrite(MotorBip2,LOW);
//   analogWrite (enA, 0);
//   analogWrite (enB, 0);
//  } 
        lcd.setCursor(0,1); //sets the cursor at row 1 column 2 
        //lcd.print(c); // prints HELLO WORLD
}