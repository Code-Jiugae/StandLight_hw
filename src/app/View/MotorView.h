#ifndef MOTORVIEW_H
#define MOTORVIEW_H

#pragma once

#include "Motor.h"

class MotorView
{
private:
    Motor *motor;
public:
    MotorView(Motor *motor);
    ~MotorView();
    void updateMotor(int val);

    
};

#endif