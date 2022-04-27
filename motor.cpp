#include "motor.h"

void motor_begin(void)
{
  pinMode(MOTOR_1_PIN_1, OUTPUT);
  pinMode(MOTOR_1_PIN_2, OUTPUT);
  pinMode(MOTOR_2_PIN_1, OUTPUT);
  pinMode(MOTOR_2_PIN_2, OUTPUT);
}
void motor_forward(int speed)
{
    analogWrite(MOTOR_1_PIN_1, speed);
    analogWrite(MOTOR_1_PIN_2, 0);
    analogWrite(MOTOR_2_PIN_1, speed);
    analogWrite(MOTOR_2_PIN_2, 0);
}

void motor_backward(int speed)
{
    digitalWrite(4, LOW);
    analogWrite(MOTOR_1_PIN_1, 0);
    analogWrite(MOTOR_1_PIN_2, speed);
    analogWrite(MOTOR_2_PIN_1, 0);
    analogWrite(MOTOR_2_PIN_2, speed); 
}

void motor_left(int speed)
{
    analogWrite(MOTOR_1_PIN_1, 0);
    analogWrite(MOTOR_1_PIN_2, speed);
    analogWrite(MOTOR_2_PIN_1, speed);
    analogWrite(MOTOR_2_PIN_2, 0);
}

void motor_right(int speed)
{
    analogWrite(MOTOR_1_PIN_1, speed);
    analogWrite(MOTOR_1_PIN_2, 0);
    analogWrite(MOTOR_2_PIN_1, 0);
    analogWrite(MOTOR_2_PIN_2, speed);
}

void motor_stop(void)
{
    analogWrite(MOTOR_1_PIN_1, 0);
    analogWrite(MOTOR_1_PIN_2, 0);
    analogWrite(MOTOR_2_PIN_1, 0);
    analogWrite(MOTOR_2_PIN_2, 0);
}
