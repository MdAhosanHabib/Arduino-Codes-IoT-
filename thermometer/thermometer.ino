#include<LiquidCrystal.h>
LiquidCrystal lcd(5,6,7,8,9,10);
float value;
float milivolt;
int temp;
void setup() {
  lcd.begin(16,2);
}

void loop() {
  value = analogRead(A0);
  milivolt = (value*5000)/1024;
  temp = milivolt/10;
  lcd.setCursor(2,0);
  lcd.print("Ahosan Habib");
  lcd.setCursor(2,1);
  lcd.print("Temp = ");
  lcd.print(temp);
  lcd.print(char(223));
  lcd.print("C");
}
