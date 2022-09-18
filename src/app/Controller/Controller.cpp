#include "Controller.h"

Controller::Controller(Service *serv, ClockService *clockServ, TempHumidService *tempHumiService, MotorService *motorService)
{
    this->service = serv;
    this->clockService = clockServ;
    this->tempHumidService = tempHumiService;
    this->lightState = LIGHT_OFF;
    this->motorService = motorService;
}

Controller::~Controller()
{
}

void Controller::updateEvent(std::string strBtn)
{
    if (strBtn == "modeButton")
    {
        service->updateState("modeButton");
    }
    if (strBtn == "powerButton")
    {
        service->updateState("powerButton");
    }
    if (strBtn == "motorButton")
    {
        motorService->updateMotor("motorButton");
    }
    if (strBtn == "timerModeButton")
    {
        clockService->timerMode = !(clockService->timerMode);
        //std::cout << clockService->timerMode << std::endl;
    }
    if(clockService->timerMode)
    {
        if (strBtn == "timerButton")
        {
            clockService->updateTimerStopStart();
        }
        else
        {
            clockService->updateTimer();
        }
    }
    else
    {
        if (strBtn == "clockUpdate")
        {
            clockService->updateEvent();
        }
    }
    
    //todo 버튼 눌렀을때 clock 모드와 timer모드 변환하기
}

void Controller::updateTempHumid(DHT_Data dhtData)
{
    tempHumidService->updateEvent(dhtData);
}

void Controller::updateDistance(int distance)
{
    service->updateDistance(distance);
}

void Controller::updateMotor(bool onoff)
{
    if(onoff)
        motorService->updateMotor("true");
    else
        motorService->updateMotor("false");
}