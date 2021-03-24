// Шаг времени работы двигателей (мксек)
const int MOVE_TIME_STEP = 50;
// Время одного цикла работы двигателей (мксек)
const int FULL_MOVE_TIME = MOVE_TIME_STEP * 10;
// Пременная изменения скорости.
unsigned long  _move_time;
// == Выбор действий
void move_case(char bt_input)
{
  switch (bt_input) {
    // Вперед
    case 'F':
      forward();
      break;
    // Назад
    case 'B':
      backward();
      break;
    // Влево
    case 'L':
      left();
      break;
    // Вправо
    case 'R':
      right();
      break;
    // Прямо и влево
    case 'G':
      forward_left();
      break;
    // Прямо и вправо
    case 'I':
      forward_right();
      break;
    // Назад и влево
    case 'H':
      backward_left();
      break;
    // Назад и вправо
    case 'J':
      backward_right();
      break;
    // Стоп
    case 'S':
      _stop();
      break;
    // Скорость 0%, 10%, 20%, ..., 90%
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
      _move_time = MOVE_TIME_STEP * (bt_input - 48);
      break;
    // Скорость 100%
    case 'q':
      _move_time = FULL_MOVE_TIME;
      break;
    case 'X':
      //switch_rejim = 1;
      break;
    case 'x':
      //switch_rejim = 0;
      break;
    case 'D':
      _stop(); //switch_rejim = 0;
      break;
  }
}
