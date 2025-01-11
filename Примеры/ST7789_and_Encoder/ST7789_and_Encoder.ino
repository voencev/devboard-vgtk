#include <Encoder.h>

#define CLK 2
#define DT 3
#define SW 6

Encoder enc1(CLK, DT, SW);

#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include <SPI.h>

#define TFT_CS		10
#define TFT_RST		9
#define TFT_DC		8
#define TFT_MOSI	51
#define TFT_SCLK	52

Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

int x = tft.width()/2-20;

void setup()
{
  tft.init(240, 240);
  tft.setRotation(2);
  tft.fillScreen(ST77XX_BLACK);
  tft.fillRect(x, tft.height()/2-20, 40, 40, ST77XX_GREEN);
  enc1.setType(TYPE2);
}

void loop()
{
  enc1.tick();
  if (enc1.isTurn())
  {
    if(enc1.isRight())
    {
      if(x<200) x += 20;
      tft.fillScreen(ST77XX_BLACK);
      tft.fillRect(x, tft.height()/2-20, 40, 40, ST77XX_GREEN);
    }
    if(enc1.isLeft())
    {
      if(x>0) x -= 20;
      tft.fillScreen(ST77XX_BLACK);
      tft.fillRect(x, tft.height()/2-20, 40, 40, ST77XX_GREEN);
    }
  }
}