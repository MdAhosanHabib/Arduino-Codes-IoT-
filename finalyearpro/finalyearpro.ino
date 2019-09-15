int red = 8;
int green = 9;
char sms;
void setup() {
  Serial.begin(9600);
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
}

void loop() {
  if(Serial.available()!=0){
    sms = Serial.read();
  }
   if(sms=='1'){
    digitalWrite(red,HIGH);
   }
   if(sms=='2'){
    digitalWrite(red,LOW);
   }
   if(sms=='3'){
    digitalWrite(green,HIGH);
   }
   if(sms=='4'){
    digitalWrite(green,LOW);
   }
}
