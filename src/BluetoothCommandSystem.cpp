#include "BluetoothCommandSystem.h"

BluetoothCommandSystem::BluetoothCommandSystem(MotorSystem4x4 *motorSystem) {
    this->motorSystem = motorSystem;
}

void BluetoothCommandSystem::processCommand(char bt_input) {
    switch (bt_input) {
        // Вперед
        case 'F':
            motorSystem->forward();
            break;
            // Назад
        case 'B':
            motorSystem->backward();
            break;
            // Влево
        case 'L':
            motorSystem->left();
            break;
            // Вправо
        case 'R':
            motorSystem->right();
            break;
            // Прямо и влево
        case 'G':
            motorSystem->forwardLeft();
            break;
            // Прямо и вправо
        case 'I':
            motorSystem->forwardRight();
            break;
            // Назад и влево
        case 'H':
            motorSystem->backwardLeft();
            break;
            // Назад и вправо
        case 'J':
            motorSystem->backwardRight();
            break;
            // Стоп
        case 'S':
            motorSystem->stop();
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
            moveTime = MOVE_TIME_STEP * (bt_input - 48);
            break;
            // Скорость 100%
        case 'q':
            moveTime = FULL_MOVE_TIME;
            break;
        case 'X':
            //switch_rejim = 1;
            break;
        case 'x':
            //switch_rejim = 0;
            break;
        case 'D':
            motorSystem->stop(); //switch_rejim = 0;
            break;
    }
}

long BluetoothCommandSystem::getMoveTime() {
    return moveTime;
}

MotorSystem4x4 *BluetoothCommandSystem::getMotorSystem4X4() {
    return motorSystem;
}
