#include <Arduino.h>
// Подключаем библиотеку для создания дополнительных последовательных (Serial) портов.
#include <SoftwareSerial.h>
#include "BluetoothCommandSystem.h"
// Создаем последовательный порт на пинах 10-чтение и 11-передача.
SoftwareSerial BTSerial(10, 11); // RX, TX
// Переменные – номера контактов (пинов) Arduino.
// Для левых и правых моторов машинки.
MotorSystem4x4 motorSystem = MotorSystem4x4(2, 3, 4, 5);
BluetoothCommandSystem btCommandSystem = BluetoothCommandSystem(&motorSystem);
// Хранит время последнего нажатия кнопки.
unsigned long _time;
//=================================//
//== Функция инициализации
void setup()
{
    motorSystem.setup();
    // Устанавливаем скорость передачи данных для НС-05 (Bluetooth-модуль).
    BTSerial.begin(9600);
    // Переключаем A0 в двоичный режим работы, на передачу.
    // если вы его еще не отключили
    //  pinMode(14, OUTPUT);
    // Устанавливаем скорость передачи данных по кабелю.
    // Порт компьютера
    //Serial.begin(9600);
    _time = micros();
}
// Основная программа.
void loop()
{
  // Переменная для приема данных по Bluetooth.
  char bt_input;
  if (BTSerial.available())
  {
    // Читаем команду и заносим ее в переменную. char преобразует
    // код символа команды в символ.
    bt_input = (char)BTSerial.read();
    // Отправляем команду в порт, чтобы можно было
    // их проверить в "Мониторе порта".
    //Serial.println(bt_input);
    //Вызов функции выбора действия по команде
      btCommandSystem.processCommand(bt_input);
    _time = micros();
  }
  if ((micros() - _time) > btCommandSystem.getMoveTime())
  {
      motorSystem.stop();
  }
  if ((micros() - _time) >= FULL_MOVE_TIME)
  {
    _time = micros();
      btCommandSystem.processCommand(bt_input);
  }
}
