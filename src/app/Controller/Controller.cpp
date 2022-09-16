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
    if (strBtn == "clockUpdate")
    {
        clockService->updateEvent();
    }
    
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
    motorService->updateMotor(onoff);
}