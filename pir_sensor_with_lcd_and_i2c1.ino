#include <LiquidCrystal_I2C.h>

#include<Servo.h>

LiquidCrystal_I2C lcd_1(0x27,16,2);
int pir1_signal=10;
int pir2_signal=9;
int pir3_signal=8;
int piezo1=7;
int piezo2=6;
int piezo3=5;
int led1=13;
int led2=12;
int led3=11;
int positive=4;
int negative=3;

void setup(){
  
  lcd_1.init();
  lcd_1.backlight();
  
  pinMode(pir1_signal, INPUT);
  pinMode(pir2_signal, INPUT);
  pinMode(pir3_signal, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(piezo1, OUTPUT);
  pinMode(piezo2, OUTPUT);
  pinMode(piezo3, OUTPUT);
  pinMode(positive, OUTPUT);
  pinMode(negative,OUTPUT);
}

void loop(){
  lcd_1.clear();
  
  if (digitalRead(pir1_signal)){
    digitalWrite(led1,HIGH);
    digitalWrite(piezo1,HIGH);
    digitalWrite(positive,HIGH);
    digitalWrite(negative,LOW);
    
    lcd_1.setCursor(0,0);
   	lcd_1.print("Michael passe");
    lcd_1.setCursor(7,1);
    lcd_1.print("au 1");
  	delay(1000);
  }
  
  else if (digitalRead(pir2_signal)){
    digitalWrite(led2,HIGH);
    digitalWrite(piezo2,HIGH);
    digitalWrite(positive,HIGH);
    digitalWrite(negative,LOW);
    
    lcd_1.setCursor(0,0);
    lcd_1.print("Michael passe au 2");
  	delay(1000);
  
  }
  
  else if (digitalRead(pir3_signal)){
    digitalWrite(led3,HIGH);
    digitalWrite(piezo3,HIGH);
    digitalWrite(positive,HIGH);
    digitalWrite(negative,LOW);
    
    lcd_1.setCursor(0,0);
    lcd_1.print("Michael passe au 3");
  	delay(1000);
  }
  
  else {
   	digitalWrite(led1,LOW);
    digitalWrite(piezo1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(piezo2,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(piezo3,LOW);
    digitalWrite(positive,LOW);
    digitalWrite(negative,LOW);
    
    lcd_1.setCursor(0,0);
    lcd_1.print("Michael ne passe");
    lcd_1.setCursor(7,1);
    lcd_1.print("pas");
  	delay(1000);
  }
  delay(1000);
}
