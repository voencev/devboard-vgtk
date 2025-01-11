#include <DS3231.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include <SPI.h>

#define TFT_CS 10
#define TFT_RST 9
#define TFT_DC 8
#define TFT_MOSI 51
#define TFT_SCLK 52
Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

RTClib myRTC;

void setup() {

	Wire.begin();
 
	tft.init(240, 240, SPI_MODE2);          
  tft.setRotation(2);
  tft.fillScreen(ST77XX_BLACK);

	Serial.begin(9600);
}

void loop() {

  tft.fillScreen(ST77XX_BLACK);
  DateTime now = myRTC.now();

  tft.setCursor(0,0);
  tft.setTextSize(4);
  tft.setTextColor(ST77XX_GREEN);
  String datee = String(now.day()) +'.' +String(now.month()) +'.' + String(now.year());
  tft.print(datee);

  tft.setCursor(0,48);
  tft.setTextSize(4);
  tft.setTextColor(ST77XX_GREEN);
  String timee = String(now.hour()) +':'+ String(now.minute()) +':'  + String(now.second());
  tft.print(timee);

  delay(1000);
}
	