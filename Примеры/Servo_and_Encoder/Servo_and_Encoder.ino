#include <Encoder.h>
#include <Servo.h>

#define CLK 2
#define DT 3
#define SW 6

Servo myservo;  
int pos = 0;  
Encoder enc1(CLK, DT, SW);

void setup()
{
  Serial.begin(9600);
  enc1.setType(TYPE2);
  myservo.attach(7);
  myservo.write(pos);
}

void loop()
{
  enc1.tick();
  if(enc1.isRight())
  {
	if(pos < 180)
    pos+= 15;
    myservo.write(pos);
  }

  if(enc1.isLeft())
  {
    if( pos >= 0)
    {
	  pos-=15;
      myservo.write(pos);
	}
  }
}


