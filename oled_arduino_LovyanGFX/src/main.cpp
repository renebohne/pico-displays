#include <Arduino.h>
#include <Wire.h>

#include "LGFX_SSD1306_I2C.hpp"

static LGFX_SSD1306 lcd;


void setup() {
    Serial.begin(115200);
    delay(3000);
  Wire.begin();
  if(!lcd.init())
  {
    Serial.println("init failed!");
  }
  lcd.setFont(&fonts::Font0);
  lcd.println("www.digitale-dinge.de");

  Serial.printf("SDA: %d, SCL: %d\n", SDA, SCL);
  delay(1000);
}

void loop() {
  
}