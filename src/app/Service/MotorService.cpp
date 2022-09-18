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
    if(strCheck == "true")
    {
        // std::cout <<"here1"<<std::endl;
        motorView->updateMotor(99);
    }
    else if(strCheck == "motorButton")
    {
        cnt++;
        // std::cout <<"here2"<< cnt <<std::endl;
        if(cnt >= 10)  cnt = 0;
        motorView->updateMotor(cnt*10);
    }
    else
    {
        // std::cout <<"here3" << cnt <<std::endl;
        if(cnt >= 10)  cnt = 0;
        motorView->updateMotor(cnt*10);
    }
    
}