#include <LiquidCrystal.h>
int buttonpin1= A0;
int blue=A3;
int green=A4;
int red=A2;
int lightPin = 0;
int tiltPin = 2;
int buzzerpin = 12;
int ledPin = 13;
int led1Pin = 10;
int led2Pin = 9;
int led3Pin = 8;
int led4Pin = 7;
int constant = 300 ;
int frequencies[] = {523, 587, 659, 698, 760, 885, 987, 1046};
int i = 0;

void setup() {
 
  pinMode(buttonpin1, INPUT_PULLUP);
  
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  
  pinMode(ledPin, OUTPUT);
  pinMode(tiltPin, INPUT);
  digitalWrite(tiltPin, HIGH);
  
  pinMode(buzzerpin, OUTPUT);
  
  digitalWrite(ledPin, LOW);
 
}

void rgbled(){
  tone(buzzerpin,0);
  
  analogWrite(red, 255);
  analogWrite(green,0);
  analogWrite(blue,0);
  delay(2000);
  
  analogWrite(red, 0);
  analogWrite(green,255);
  analogWrite(blue,0);
  delay(2000);
  
  analogWrite(red, 0);
  analogWrite(green,0);
  analogWrite(blue,255);
  delay(2000);
    
  analogWrite(red,255);
  analogWrite(green,255);
  analogWrite(blue,0);
  delay(2000);
  
  analogWrite(red, 0);
  analogWrite(green,255);
  analogWrite(blue,255);
  delay(2000);
  
  analogWrite(red, 255);
  analogWrite(green,0);
  analogWrite(blue,255);
  delay(2000);
  } 
  


void loop() {
  if (analogRead(buttonpin1) == LOW) {
    rgbled();
  }
  
  int digitalVal = digitalRead(tiltPin);

  if (digitalVal == HIGH) {

    digitalWrite(led1Pin, HIGH);
    digitalWrite(led2Pin, LOW);
    digitalWrite(led3Pin, HIGH);
    digitalWrite(led4Pin, LOW);
    delay(200);

    digitalWrite(led1Pin, LOW);
    digitalWrite(led2Pin, HIGH);
    digitalWrite(led3Pin, LOW);
    digitalWrite(led4Pin, HIGH);
    delay(200);
    
 
    tone(buzzerpin, 300);
     
    
  } 
  else (digitalVal == LOW) ;{
    digitalWrite(led1Pin, LOW);
    digitalWrite(led2Pin, LOW);
    digitalWrite(led3Pin, LOW);
    digitalWrite(led4Pin, LOW);
   
    	for(int i = 0; i <8 ; i++){
      	if (digitalVal == HIGH){
        break;}
        tone(12,frequencies[i]);
        digitalWrite(buzzerpin,LOW);
        delay(15 );
        
        digitalVal = digitalRead(tiltPin);
      }
 
    
 }
    
}
      