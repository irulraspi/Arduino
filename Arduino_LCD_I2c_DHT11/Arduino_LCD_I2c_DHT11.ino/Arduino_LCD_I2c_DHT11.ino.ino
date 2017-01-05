#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
#include "DHT.h"
#define DHTPIN 9 
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
void setup() {
  lcd.begin(16, 2); 
  dht.begin();
}
void loop() {
  int h = dht.readHumidity();   
  int t = dht.readTemperature();
  ///////////////////////////////////////////////////
  lcd.clear();
  lcd.setCursor(4, 0); 
  lcd.print("Humidity ");
  lcd.setCursor(6, 1);
  lcd.print(h);
  lcd.print(" %");
  delay (2500);
  ///////////////////////////////////////////////////
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("Temperatur ");
  lcd.setCursor(6, 1);
  lcd.print(t);
  lcd.print(" C'");
  delay (2500);
  ///////////////////////////////////////////////////
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("catatanraspi.id");
  delay (2500);
}
