#include "Motor.h"

Motor::Motor(int pinNum)
{
    this->pinNum = pinNum;
    softPwmCreate(this->pinNum, 0, 100);
    autoMode = false;
}

Motor::~Motor()
{

}

void Motor::PWMWrite(int value)
{
    softPwmWrite(this->pinNum, value);
}