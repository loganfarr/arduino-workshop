#include <LiquidCrystal.h>
LiquidCrystal lcd(7,8,9,10,11,12); //Pins for RS, E, DB4, DB5, DB6, DB7

void setup() {
  lcd.begin(16, 2);
}

void loop() {
  lcd.clear();
  lcd.setCursor(5, 0);
  lcd.print("Hello");
  lcd.setCursor(6, 1);
  lcd.print("world!");
  delay(500);
}

