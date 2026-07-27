#include <LiquidCrystal.h> 

LiquidCrystal lcd(12,11,5,4,3,2); 

void setup() {
  lcd.begin(16,2); 
  lcd.setCursor(3,1); 
  lcd.print("push button");
}

void loop() {
  lcd.noDisplay();
  delay(270);
  
  lcd.display();
  delay(270);
}