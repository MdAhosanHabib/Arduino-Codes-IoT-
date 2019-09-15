#include<LiquidCrystal.h>
LiquidCrystal lcd(5,6,7,8,9,10);
int trigpin = 3;
int echopin = 4;
int buzzer = 2;
float time;
float cm;
float inch;
void setup(){
  lcd.begin(16,2);
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
  pinMode(buzzer,OUTPUT);
}
void loop(){
  digitalWrite(trigpin,LOW);
  delay(2);
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin,LOW);
  time = pulseIn(echopin,HIGH);
  cm = (time/58.82);
  inch = (cm/2.54);
  lcd.setCursor(3,1);
  lcd.print(inch);
  lcd.print(" inch");
  if(inch<20){
    digitalWrite(buzzer,HIGH);
    lcd.setCursor(1,0);
    lcd.print("Object in Range");
  }else{
    digitalWrite(buzzer,LOW);
  }
  delay(1000);
  lcd.clear();
}
