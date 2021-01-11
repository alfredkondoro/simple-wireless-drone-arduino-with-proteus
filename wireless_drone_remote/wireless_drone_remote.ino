#include <LiquidCrystal.h>

LiquidCrystal lcd(A5, A4, A3, A2, A1, A0);
char incomingByte = 0;

int btnlift = 2;
int btnrleft = 3;
int btnrright = 4;
int btnpfoward = 5;
int btnpback = 6;
int btnyclock = 7;
int btnyaclock = 8;

int statelift = 0;
int staterleft = 0;
int staterright = 0;
int statepfoward = 0;
int statepback = 0;
int stateyclock = 0;
int stateyaclock = 0;

void setup() {
  pinMode(btnlift,OUTPUT);
  pinMode(btnrleft,OUTPUT);
  pinMode(btnrright,OUTPUT);
  pinMode(btnpfoward,OUTPUT);
  pinMode(btnpback,OUTPUT);
  pinMode(btnyclock,OUTPUT);
  pinMode(btnyaclock,OUTPUT);
  Serial.begin(9600);
  lcd.begin(16, 4);  
  lcd.clear();      
  lcd.setCursor(0,0);
  lcd.print("W-LESS DRONE");
}

void loop() {
  statelift = digitalRead(btnlift);
  staterleft = digitalRead(btnrleft);
  staterright = digitalRead(btnrright);
  statepfoward = digitalRead(btnpfoward);
  statepback = digitalRead(btnpback);
  stateyclock = digitalRead(btnyclock);
  stateyaclock = digitalRead(btnyaclock);

  if(statelift == HIGH){
    Serial.write(1);
    lcd.setCursor(0,3);
    lcd.print("Lifting up");
  }
    if(staterleft == HIGH){
    Serial.write(2);
    lcd.setCursor(0,3);
    lcd.print("Rolling left");
  }
    if(staterright == HIGH){
    Serial.write(3);
    lcd.setCursor(0,3);
    lcd.print("Rolling right");
  }
    if(statepfoward == HIGH){
    Serial.write(4);
    lcd.setCursor(0,3);
    lcd.print("Pitch Foward");
  }
    if(statepback == HIGH){
    Serial.write(5);
    lcd.setCursor(0,3);
    lcd.print("Pitch Backward");
  }
    if(stateyclock == HIGH){
    Serial.write(6);
    lcd.setCursor(0,3);
    lcd.print("Yaw Clockwise");
  }
    if(stateyaclock == HIGH){
    Serial.write(7);
    lcd.setCursor (0,3);
    lcd.print("Yaw Anticlockwise");
  }
}
