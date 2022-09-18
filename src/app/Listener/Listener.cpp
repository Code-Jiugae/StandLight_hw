#include "Listener.h"
#include <wiringPi.h>

Listener::Listener(Button *modeButton, Button *powerButton, Button *motorButton, Button *timerButton, Button *timerModeButton,
                    Controller *control, ClockCheck *clock, DHT11 *dht11, UltraSonic *ultraSonic, Motor *motor)
{
    this->modeButton = modeButton;
    this->powerButton = powerButton;
    this->motorButton = motorButton;
    this->controller = control;
    this->clockCheck = clock;
    this->dht11 = dht11;
    this->ultraSonic = ultraSonic;
    this->motor = motor;
    this->timerButton = timerButton;
    this->timerModeButton = timerModeButton;
}

Listener::~Listener()
{
}

void Listener::checkEvent()
{
    DHT_Data dhtData;
    if (modeButton->getState() == RELEASE_ACTIVE)
    {
        controller->updateEvent("modeButton");
    }

    if (powerButton->getState() == RELEASE_ACTIVE)
    {
        controller->updateEvent("powerButton");
    }

    if (motorButton->getState() == RELEASE_ACTIVE)
    {
        controller->updateEvent("motorButton");
    }

    if (timerButton->getState() == RELEASE_ACTIVE)
    {
        // std::cout <<"timerButton" << std::endl;
        controller->updateEvent("timerButton");
    }

    if (timerModeButton->getState() == RELEASE_ACTIVE)
    {
        // std::cout <<"timerModeButton" << std::endl;
        controller->updateEvent("timerModeButton");
    }

    if (clockCheck->isUpdate())
    {
        controller->updateEvent("clockUpdate");
    }

    static unsigned int prevTempHumidTime = 0;
    
    if (millis() - prevTempHumidTime > 2000)
    {
        prevTempHumidTime = millis();
        dhtData = dht11->readData();
        if (!dhtData.error)
        {
            controller->updateTempHumid(dhtData);
            dht11->pre_RH = dhtData.RH;
            dht11->pre_RHDec = dhtData.RHDec;
            dht11->pre_Temp = dhtData.Temp;
            dht11->pre_TempDec = dhtData.TempDec;
        }
    }

    if(dht11->pre_Temp > 30)
    {
        controller->updateMotor(true);
    }
    else
    {
        controller->updateMotor(false);
    }

    //std::cout << dht11->pre_Temp << std::endl;

    static unsigned int prevUltraSonicTime = 0;
    if (millis() - prevUltraSonicTime > 2000)
    {
        prevUltraSonicTime = millis();
        int distance = ultraSonic->readDistance();
        controller->updateDistance(distance);
        
        
    }
}