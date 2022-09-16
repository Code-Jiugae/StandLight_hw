#ifndef MOTORSERVICE_H
#define MOTORSERVICE_H

#pragma once
#include <string.h>
#include "MotorView.h"

class MotorService
{
    
private:
    MotorView *motorView;
    int cnt;

public:
    MotorService(MotorView *motorView);
    ~MotorService();
    void updateMotor(std::string strCheck);
    void updateMotor(bool check);
};

#endif