#include <hc_sr04.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include <SPI.h>

Ultrasonic ultrasonic(12, 11);

#define TFT_CS 10
#define TFT_RST 9
#define TFT_DC 8
#define TFT_MOSI 51
#define TFT_SCLK 52
Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

void setup()
{
	tft.init(240, 240, SPI_MODE2);          
  tft.setRotation(2);
  tft.fillScreen(ST77XX_BLACK);

	Serial.begin(9600);
}

void loop()
{
  tft.fillScreen(ST77XX_BLACK);
  tft.setCursor(0,0);
  tft.setTextSize(4);
  tft.setTextColor(ST77XX_GREEN);
  float dist_cm = ultrasonic.Ranging(CM);
  String dist = String(dist_cm);

  tft.print(dist);
  delay(10);
}