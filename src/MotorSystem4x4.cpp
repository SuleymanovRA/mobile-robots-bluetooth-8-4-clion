#include <Arduino.h>
#include "MotorSystem4x4.h"

MotorSystem4x4::MotorSystem4x4(int leftMotorPin1, int leftMotorPin2, int rightMotorPin1, int rightMotorPin2) {
    // Заносятся в переменные номера контактов (пинов) Arduino.
    motor_L1 = leftMotorPin1; motor_L2 = leftMotorPin2;
    // Для левых и правых моторов робота.
    motor_R1 = rightMotorPin1; motor_R2 = rightMotorPin2;
}

void MotorSystem4x4::setup() {
    // Переводятся указанные порты в состояние вывода данных.
    pinMode(motor_L1, OUTPUT);
    pinMode(motor_L2, OUTPUT);
    pinMode(motor_R1, OUTPUT);
    pinMode(motor_R2, OUTPUT);
    //Двигатели остановлены.
    stop();
}

void MotorSystem4x4::forward() {
    // Если двигатель будет работать не в ту сторону,
    // поменять на нем контакты местами.
    digitalWrite(motor_L1, HIGH);
    digitalWrite(motor_L2, LOW);
    digitalWrite(motor_R1, HIGH);
    digitalWrite(motor_R2, LOW);
}

void MotorSystem4x4::forwardLeft() {
    // блокировка вращения левых колес.
    digitalWrite(motor_L1, LOW);
    digitalWrite(motor_L2, LOW);
    // правые колеса вращаются.
    digitalWrite(motor_R1, HIGH);
    digitalWrite(motor_R2, LOW);
}

void MotorSystem4x4::forwardRight() {
    // левые колеса вращаются.
    digitalWrite(motor_L1, HIGH);
    digitalWrite(motor_L2, LOW);
    // блокировка вращения правых колес.
    digitalWrite(motor_R1, LOW);
    digitalWrite(motor_R2, LOW);
}

void MotorSystem4x4::left() {
    // левые колеса вращаются назад.
    digitalWrite(motor_L1, LOW);
    digitalWrite(motor_L2, HIGH);
    // правые колеса вращаются вперед.
    digitalWrite(motor_R1, HIGH);
    digitalWrite(motor_R2, LOW);
}

void MotorSystem4x4::right() {
    // левые колеса вращаются вперед.
    digitalWrite(motor_L1, HIGH);
    digitalWrite(motor_L2, LOW);
    // правые колеса вращаются назад.
    digitalWrite(motor_R1, LOW);
    digitalWrite(motor_R2, HIGH);
}

void MotorSystem4x4::backward() {
    // Смена направления вращения двигателей.
    digitalWrite(motor_L2, HIGH);
    digitalWrite(motor_L1, LOW);
    digitalWrite(motor_R2, HIGH);
    digitalWrite(motor_R1, LOW);
}

void MotorSystem4x4::backwardLeft() {
    // Смена направления вращения двигателей.
    digitalWrite(motor_L2, LOW);
    digitalWrite(motor_L1, HIGH);
    digitalWrite(motor_R2, HIGH);
    digitalWrite(motor_R1, LOW);
}

void MotorSystem4x4::backwardRight() {
    // Смена направления вращения двигателей.
    digitalWrite(motor_L2, HIGH);
    digitalWrite(motor_L1, LOW);
    digitalWrite(motor_R2, LOW);
    digitalWrite(motor_R1, HIGH);
}

void MotorSystem4x4::stop() {
    // Блокировка всех колес.
    digitalWrite(motor_L2, LOW);
    digitalWrite(motor_L1, LOW);
    digitalWrite(motor_R2, LOW);
    digitalWrite(motor_R1, LOW);
}
