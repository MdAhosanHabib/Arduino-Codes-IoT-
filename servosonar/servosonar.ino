#include<LiquidCrystal.h>
#include<Servo.h>
Servo rakibServo;
LiquidCrystal lcd(12,13,7,8,9,10);
int trigpin = 2;
int echopin = 4;
int srv = 6;
int lm = A1;
int pir = 5;
int state;
int buzzer = 11;
float time;
float cm;
float inch;
const int analogPin = A0;
const int ledCount = 3;
int ledPins[] = {A3,A4,A5};
void setup(){
  pinMode(pir,INPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(lm,INPUT);
  lcd.begin(16,2);
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
  rakibServo.attach(srv);
  for(int thisLed = 0; thisLed < ledCount; thisLed++){
    pinMode(ledPins[thisLed],OUTPUT);
  }
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
    rakibServo.write(180);
    lcd.setCursor(14,1);
    lcd.print("20");
  }else{
    rakibServo.write(0);
  }
  delay(500);
  lcd.clear();

  //led grap
  int sensorReading = analogRead(analogPin);
  int ledLevel = map(sensorReading,0,1023,0,ledCount);
  for(int thisLed = 0; thisLed < ledCount; thisLed++){
    if(thisLed<ledLevel){
      digitalWrite(ledPins[thisLed],HIGH);
    }else{
      digitalWrite(ledPins[thisLed],LOW);
      }
  }

  //pir
  state = digitalRead(pir);
  digitalWrite(buzzer,state);

  //temp
  float value = analogRead(lm);
  float milivolt = (value*5000)/1024;
  int temp = milivolt/10;
  lcd.setCursor(2,0);
  lcd.print("Temp = ");
  lcd.print(temp);
  lcd.print(char(223));
  lcd.print("C");
}
