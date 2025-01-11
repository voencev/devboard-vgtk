#include <hc_sr04.h>

// Trig - 12, Echo - 11
Ultrasonic ultrasonic(12, 11);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  float dist_cm = ultrasonic.Ranging(CM); 	// Получить дистанцию
  Serial.println(dist_cm); 					// Вывести дистанцию в Serial

  delay(100); // Задержка
}
