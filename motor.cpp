#include "motor.h"
//https://github.com/RoboticsBrno/ServoESP32
#include <Servo.h>

Servo servo1;
int currentDegree ;

void motor_begin(void)
{
  pinMode(MOTOR_PIN_1, OUTPUT);
  pinMode(MOTOR_PIN_2, OUTPUT);
  
  servo1.attach(SERVO_PIN);
  currentDegree = 90;
}
void motor_forward(int speed)
{
    analogWrite(MOTOR_PIN_1, speed);
    analogWrite(MOTOR_PIN_2, 0);
    currentDegree = 90;
    servo1.write(currentDegree);

}

void motor_backward(int speed)
{
    analogWrite(MOTOR_PIN_1, 0);
    analogWrite(MOTOR_PIN_2, speed);
  
    currentDegree = 90;
    servo1.write(currentDegree);
}

void motor_left(int speed)
{
    analogWrite(MOTOR_PIN_1, speed);
    analogWrite(MOTOR_PIN_2, 0);

    currentDegree = 50;
    servo1.write(currentDegree);
}

void motor_right(int speed)
{
    analogWrite(MOTOR_PIN_1, speed);
    analogWrite(MOTOR_PIN_2, 0);

    currentDegree = 130;
    servo1.write(currentDegree);
}

void motor_stop(void)
{
    currentDegree = 90;
    servo1.write(currentDegree);
    analogWrite(MOTOR_PIN_1, 0);
    analogWrite(MOTOR_PIN_2, 0);
}
