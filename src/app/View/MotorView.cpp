#include "MotorView.h"

MotorView::MotorView(Motor *motor)
{
    this->motor = motor;
}

MotorView::~MotorView()
{

}

void MotorView::updateMotor(int val)
{
    motor->PWMWrite(val);
    //motor->PWMWrite(50);
}