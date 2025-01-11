const int segmentPins[] = {29, 28, 27,26, 25, 24  ,23,22};
const int digitPins[] = {A3, A4, A5, A2};

// Определение символов для каждой цифры (a, b, c, d, e, f, g)
const byte digits[][7] = {
  {1, 1, 1, 1, 1, 1, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1}, // 2
  {1, 1, 1, 1, 0, 0, 1}, // 3
  {0, 1, 1, 0, 0, 1, 1}, // 4
  {1, 0, 1, 1, 0, 1, 1}, // 5
  {1, 0, 1, 1, 1, 1, 1}, // 6
  {1, 1, 1, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1}, // 8
  {1, 1, 1, 1, 0, 1, 1}  // 9
};

void setup() {
  // Настройка пинов сегментов и разрядов как выходов
  for (int i = 0; i < 7; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }
  for (int i = 0; i < 4; i++) {
    pinMode(digitPins[i], OUTPUT);
  }
}

void loop() {
  // Отображение числа "1234" на индикаторе
  displayNumber(1234);
  //delay(1000);
}

void displayNumber(int number) {
  for (int digit = 3; digit >= 0; digit--) {
    // Включение нужного разряда
    for (int i = 0; i < 4; i++) {
      if (i == digit) {
        digitalWrite(digitPins[i], LOW); // Включаем разряд
      } else {
        digitalWrite(digitPins[i], HIGH); // Выключаем остальные разряды
      }
    }
    
    // Отображение соответствующей цифры на сегментах
    for (int segment = 0; segment < 7; segment++) {
      if (digits[number % 10][segment]) {
        digitalWrite(segmentPins[segment], HIGH); // Включаем сегмент
      } else {
        digitalWrite(segmentPins[segment], LOW); // Выключаем сегмент
      }
    }

    // Сдвигаем число вправо для следующей цифры
    number /= 10;
    
    // Задержка для отображения цифры
    delay(5); // Можно увеличить или уменьшить для настройки яркости
  }
}
