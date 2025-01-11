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

#define maxString 100 // ограничиваем строку шириной экрана
char target[maxString + 1] = "";

char *utf8rus2(char *source)
{
  int i,j,k;
  unsigned char n;
  char m[2] = { '0', '\0' };
  strcpy(target, ""); k = strlen(source); i = j = 0;
  while (i < k) {
    n = source[i]; i++;

    if (n >= 127) {
      switch (n) {
        case 208: {
          n = source[i]; i++;
          if (n == 129) { n = 192; break; } // перекодируем букву Ё
          break;
        }
        case 209: {
          n = source[i]; i++;
          if (n == 145) { n = 193; break; } // перекодируем букву ё
          break;
        }
      }
    }

    m[0] = n; strcat(target, m);
    j++; if (j >= maxString) break;
  }
  return target;
}

void loop()
{
}



void drawtext()
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
  tft.print(utf8rus2("Елизавета Михайловна"));
  tft.setCursor(110, 32);
  tft.print(utf8rus2("мы"));
  tft.setCursor(105, 50);
  tft.print(utf8rus2("вас"));
  
  tft.setCursor(78, 80);
  tft.setTextSize(3);
  tft.print(utf8rus2("ЛЮБИМ"));
}
