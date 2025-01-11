#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include <SPI.h>

#define TFT_CS 10
#define TFT_RST 9
#define TFT_DC 8
#define TFT_MOSI 51
#define TFT_SCLK 52
Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);


void setup(void)
{
  tft.init(240, 240, SPI_MODE2);          
  tft.setRotation(2);
  tft.fillScreen(ST77XX_BLACK);
  testdrawtext();
}

String utf8rus(String source)
{
  int i,k;
  String target;
  unsigned char n;
  char m[2] = { '0', '\0' };

  k = source.length(); i = 0;

  while (i < k) {
    n = source[i]; i++;

    if (n >= 0xC0) {
      switch (n) {
        case 0xD0: {
          n = source[i]; i++;
          if (n == 0x81) { n = 0xA8; break; }
          if (n >= 0x90 && n <= 0xBF) n = n + 0x30;
          break;
        }
        case 0xD1: {
          n = source[i]; i++;
          if (n == 0x91) { n = 0xB8; break; }
          if (n >= 0x80 && n <= 0x8F) n = n + 0x70;
          break;
        }
      }
    }
    if (n >= 192 && n <= 223){n = n - 1;}
    if (n >= 224 && n <= 255){n = n - 1;}
    m[0] = n; target = target + String(m);
  }
return target;
}



void loop()
{
}



void testdrawtext()
{
  tft.setCursor(58,116);
  tft.setTextSize(3);
  tft.setTextColor(ST77XX_RED);
  tft.setTextWrap(true);
  tft.print(" ## ##");
  tft.setCursor(58, 140);
  tft.print("#######");
  tft.setCursor(58, 164);
  tft.print(" ##### ");
  tft.setCursor(58, 188);
  tft.print("  ###  ");
  tft.setCursor(58, 212);
  tft.print("   #   ");
  tft.setCursor(0, 16);
  tft.setTextSize(2);
  tft.setTextColor(ST77XX_WHITE);
  tft.print(utf8rus("Елизавета Михайловна"));
  tft.setCursor(110, 32);
  tft.print(utf8rus("мы"));
  tft.setCursor(105, 48);
  tft.print(utf8rus("вас"));
  
  tft.setCursor(78, 80);
  tft.setTextSize(3);
  tft.print(utf8rus("ЛЮБИМ"));
}



