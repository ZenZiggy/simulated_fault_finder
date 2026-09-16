#include <LiquidCrystal.h>

//LCD pin declarations.
const int rs = 2;
const int en = 3;
const int d4 = 6;
const int d5 = 7;
const int d6 = 8;
const int d7 = 9;

//LCD declared.
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() 
{

//Initialize LCD.
Serial.begin(9600);
lcd.begin(16, 2);

}

void loop() 
{

}
