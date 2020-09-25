#include <LiquidCrystal.h>
#define trigger 10
#define echo 11
#define motor 8
#define buzzer 12
#define led1 9
#define led2 13
#define led3 1
 
LiquidCrystal lcd(7,6,5,4,3,2);
 
float time=0,distance=0;
int temp=0; 
void setup()
{
 lcd.begin(16,2);
 pinMode(trigger,OUTPUT);
 pinMode(echo,INPUT);
 pinMode(motor, OUTPUT);
 pinMode(buzzer, OUTPUT);
 pinMode(led1, OUTPUT);
 pinMode(led2, OUTPUT);
 pinMode(led3, OUTPUT);
 }
 void loop()
{
 lcd.clear();
 digitalWrite(trigger,LOW);
 delayMicroseconds(2);
 digitalWrite(trigger,HIGH);
 delayMicroseconds(10);
 digitalWrite(trigger,LOW);
 delayMicroseconds(2);
 time=pulseIn(echo,HIGH);
 distance=time*340/20000;
 lcd.clear();
 lcd.print("AWL CONTROL");
 delay(2000);
 if(distance<500)
 {
     digitalWrite(motor, LOW);
     digitalWrite(led1, HIGH);
     lcd.clear();
     lcd.print("Water Tank Full ");
     lcd.setCursor(0,1);
     lcd.print("Motor Turned OFF");
     delay(5000);
     digitalWrite(led1, LOW);
     }
 
  else if(distance>500 && distance<750)
 {
     digitalWrite(motor, LOW);
     digitalWrite(led2, HIGH);
     lcd.clear();
     lcd.print("Water Tank Full ");
     lcd.setCursor(0,1);
     lcd.print("Motor Turned OFF");
     delay(5000);
     digitalWrite(led2, LOW);
 }
 
 else if(distance>750)
 {
   digitalWrite(motor, HIGH);
   digitalWrite(buzzer, HIGH);
   digitalWrite(led3, HIGH);
   lcd.clear();
   lcd.print("LOW Water Level");
   lcd.setCursor(0,1);
   lcd.print("Motor Turned ON");
   delay(5000);
   digitalWrite(buzzer, LOW);
   digitalWrite(led3, LOW);
    }
}
