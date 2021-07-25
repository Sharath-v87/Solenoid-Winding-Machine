#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 9 , 10, 11, 12, 13); 
int IR1=6;      
int MotorAip1 = 3;
int MotorAip2 = 4;
int c=0;
int a=10; // This represents the number of turns that you need in your wire to be winded
void setup() 
{ 
  lcd.begin(16, 2); // initializes the 16x2 LCD 
  lcd.print("Windings : "); // prints 16x2 LCD MODULE 
  pinMode(IR1,INPUT);
  pinMode (MotorAip1, OUTPUT);
  pinMode (MotorAip2, OUTPUT);
}

void loop(){
  lcd.display();
  delay(900);      
  if(digitalRead(IR1)==LOW)
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
  lcd.setCursor(0,1); 
}