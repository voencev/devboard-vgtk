#define RELAY_PIN 5

void setup()
{
  pinMode(RELAY_PIN, OUTPUT); //"Включение" реле
}

void loop()
{
  digitalWrite(RELAY_PIN, HIGH); //Переключение реле на одну сторону
  delay(1000);
  digitalWrite(RELAY_PIN, LOW); //Переключение реле на другую сторону
  delay(1000);
}
