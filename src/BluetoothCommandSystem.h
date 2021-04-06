#include "MotorSystem4x4.h"

// Шаг времени работы двигателей (мксек)
const int MOVE_TIME_STEP = 50;
// Время одного цикла работы двигателей (мксек)
const int FULL_MOVE_TIME = MOVE_TIME_STEP * 10;

/**
 * Система команд через Bluetooth
 */
class BluetoothCommandSystem {
private:
    MotorSystem4x4 *motorSystem;
    // Пременная изменения скорости.
    unsigned long moveTime;
public:
    /**
     * Создать экземпляр системы команд через Bluetooth.
     * @param motorSystem система моторов 4x4.
     */
    BluetoothCommandSystem(MotorSystem4x4 *motorSystem);

    /**
     * Получить систему моторов 4x4.
     * @return Система моторов 4x4.
     */
    MotorSystem4x4 *getMotorSystem4X4();

    /**
     * Обработать команду.
     * @param bt_input Символ команды.
     */
    void processCommand(char bt_input);

    /** Значение изменения скорости. */
    long getMoveTime();
};
