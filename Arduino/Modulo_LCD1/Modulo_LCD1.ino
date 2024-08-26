#include <LiquidCrystal.h>

LiquidCrystal lcd(7,6,5,4,3,2);

int Min;
int Seg;
int Res;

void setup() {
    lcd.begin(16, 2);
}

void loop() {
  lcd.setCursor(0,0);
  lcd.print("Hola, han pasado");
  lcd.setCursor(0,1);
  
  Seg = millis()/1000;
  Min = Seg/60;
  Res = Seg%60;  
  
  lcd.print(Min);
  lcd.print(" Min. ");
  lcd.print(Res);
  lcd.print(" Seg.");
}
