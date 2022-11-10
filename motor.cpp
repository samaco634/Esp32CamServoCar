#include "motor.h"
//https://github.com/RoboticsBrno/ServoESP32
#include <Servo.h>

Servo servo1;
int currentDegree ;

void set_servo90(void)
{
  if(int pos = servo1.read() < 90)
  {
    for (pos = servo1.read(); pos < 90; pos += 2) {
      servo1.write(pos);
      delay(40);
    }    
  }
  else
  {
    for (int pos = servo1.read(); pos > 90; pos -= 2) {
      servo1.write(pos);
      delay(40);
    }    
  }
   servo1.write(90);
}

void motor_begin(void)
{
  pinMode(MOTOR_PIN_1, OUTPUT);
  pinMode(MOTOR_PIN_2, OUTPUT);
  
  servo1.attach(SERVO_PIN);
  servo1.write(90);
}
void motor_forward(int speed)
{
    set_servo90();
    analogWrite(MOTOR_PIN_1, speed);
    analogWrite(MOTOR_PIN_2, 0);
}

void motor_backward(int speed)
{
    set_servo90();
    analogWrite(MOTOR_PIN_1, 0);
    analogWrite(MOTOR_PIN_2, speed);

}

void motor_left(int speed)
{
    analogWrite(MOTOR_PIN_1, speed);
    analogWrite(MOTOR_PIN_2, 0);

    for (int pos = servo1.read(); pos > 70; pos -= 2) {
      servo1.write(pos);
      delay(40);
    }
}

void motor_right(int speed)
{
    analogWrite(MOTOR_PIN_1, speed);
    analogWrite(MOTOR_PIN_2, 0);

    for (int pos = servo1.read(); pos < 110; pos += 2) {
      servo1.write(pos);
      delay(40);
    }
}

void motor_stop(void)
{
    set_servo90(); 
    analogWrite(MOTOR_PIN_1, 0);
    analogWrite(MOTOR_PIN_2, 0);
}
