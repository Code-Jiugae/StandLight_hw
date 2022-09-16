#include "MotorService.h"

MotorService::MotorService(MotorView *motorView)
{
    this->motorView = motorView;
    this->cnt = 0;
}

MotorService::~MotorService()
{

}

void MotorService::updateMotor(std::string strCheck)
{
    cnt++;
    if(cnt >= 10)  cnt = 0;
    motorView->updateMotor(cnt*10);
}

void MotorService::updateMotor(bool check)
{
    if(check)
    {
        motorView->updateMotor(100);
    }
    else
    {
        
    }
}