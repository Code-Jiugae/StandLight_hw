#ifndef MOTOR_H
#define MOTOR_H

#pragma once

#include <iostream>
#include <softPwm.h>

class Motor
{
private:
    int pinNum;

public:
    bool autoMode;
    Motor(int pinNum);
    ~Motor();
    void PWMWrite(int value);
    


};

#endif