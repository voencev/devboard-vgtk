#include <Encoder.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Max72xxPanel.h>

int pinCS = 18;

#define CLK 2
#define DT 3
#define SW 6

Encoder enc1(CLK, DT, SW);

int numberOfHorizontalDisplays = 4;          // Количество матриц по горизонтали
int numberOfVerticalDisplays = 1;            // Количество матриц по-вертикали
Max72xxPanel matrix = Max72xxPanel(pinCS, numberOfHorizontalDisplays, numberOfVerticalDisplays);

int x = 32/2;

void setup()
{
  matrix.setIntensity(5);
  enc1.setType(TYPE2);
  matrix.drawPixel(x, 3, HIGH);
  matrix.drawPixel(x, 4, HIGH);
  matrix.write();
}

void loop()
{
  enc1.tick();
  if (enc1.isTurn())
  {
    if(enc1.isRight())
    {
      matrix.drawPixel(x, 3, LOW);
      matrix.drawPixel(x, 4, LOW);
      if(x<31) x++;
      matrix.drawPixel(x, 3, HIGH);
      matrix.drawPixel(x, 4, HIGH);
    }
    if(enc1.isLeft())
    {
      matrix.drawPixel(x, 3, LOW);
      matrix.drawPixel(x, 4, LOW);
      if(x>0) x--;
      matrix.drawPixel(x, 3, HIGH);
      matrix.drawPixel(x, 4, HIGH);
    }
    matrix.write();
  }
}