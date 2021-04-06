/**
 * MotorSystem4x4
 * Моторная система 4x4 (4 ведущих мотор-колеса)
 */
class MotorSystem4x4 {
private:
    // Объявляем переменные для хранения состояния 4-х моторов (2 левых и 2 правых, пины).
    int motor_L1, motor_L2;
    int motor_R1, motor_R2;
public:
    /**
     * Создать моторную систему 4x4
     * @param leftMotorPin1 пин 1-го левого мотора
     * @param leftMotorPin2 пин 2-го левого мотора
     * @param rightMotorPin1 пин 1-го правого мотора
     * @param rightMotorPin2 пин 2-го правого мотора
     */
    MotorSystem4x4(int leftMotorPin1, int leftMotorPin2, int rightMotorPin1, int rightMotorPin2);

    /** Инициализация моторов */
    void setup();

    /** Двигаться вперед. */
    void forward();

    /** Поворот налево с блокировкой левых колес. */
    void forwardLeft();

    /** Поворот направо с блокировкой правых колес. */
    void forwardRight();

    /** Поворот налево на месте. */
    void left();

    /** Поворот направо на месте. */
    void right();

    /** Включаем движение назад. */
    void backward();

    /** Включаем движение назад. */
    void backwardLeft();

    /** Включаем движение назад. */
    void backwardRight();

    /** Остановить все двигатели. */
    void stop();
};
