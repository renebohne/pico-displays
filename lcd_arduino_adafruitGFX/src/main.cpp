#include <Arduino.h>

#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include <SPI.h>

#include <Fonts/FreeMono9pt7b.h>

#define TFT_DC 8
#define TFT_CS 9
#define TFT_SCLK 10
#define TFT_MOSI 11
#define TFT_RST 12
#define TFT_BACKLIGHT 13

Adafruit_ST7789 tft = Adafruit_ST7789(&SPI1, TFT_CS, TFT_DC, TFT_RST);

void setupSPI()
{
    SPI1.setTX(TFT_MOSI);
    SPI1.setSCK(TFT_SCLK);
    SPI1.setCS(TFT_CS);
    SPI1.begin();
}

void setup()
{
    Serial.begin(115200);
    delay(1000);
    setupSPI();

    tft.init(135, 240);
    tft.setRotation(3);

    pinMode(TFT_BACKLIGHT, OUTPUT);
    digitalWrite(TFT_BACKLIGHT, HIGH);

    tft.fillScreen(ST77XX_BLACK);

    tft.setFont(&FreeMono9pt7b);

    int16_t x1,y1;
    uint16_t w,h;
    char* msg = "www.digitale-dinge.de";
    tft.getTextBounds(msg, 0, 0, &x1, &y1, &w, &h);
    tft.setCursor((240-w)/2, (135+h)/2);

    tft.println(msg);
}


void loop()
{

}