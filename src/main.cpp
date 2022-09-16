#include <iostream>
#include <wiringPi.h>
#include "Button.h"
#include "Led.h"
#include "Listener.h"
#include "Controller.h"
#include "View.h"
#include "Service.h"
#include "LCD.h"
#include "ClockView.h"
#include "ClockService.h"
#include "ClockCheck.h"
#include "I2C.h"
#include "DHT11.h"
#include "TempHumidService.h"
#include "TempHumidView.h"
#include "Motor.h"
#include "MotorService.h"
#include "MotorView.h"

int main()
{
    std::cout << "Hello World!" << std::endl;

    Button modeButton(27);
    Button powerButton(28);
    Button motorButton(29);
    ClockCheck clockCheck;
    Motor motor(26);
    Led led1(21);
    Led led2(22);
    Led led3(23);
    Led led4(24);
    Led led5(25);
    DHT11 dht(7);
    UltraSonic ultraSonic(5, 4);
    LCD lcd(new I2C("/dev/i2c-1", 0x27));

    View view(&led1, &led2, &led3, &led4, &led5, &lcd);
    TempHumidView tempHumidView(&lcd);
    ClockView clockView(&lcd);
    MotorView motorView(&motor);

    Service service(&view);
    ClockService clockSerivce(&clockView);
    TempHumidService tempHumidService(&tempHumidView);
    MotorService motorService(&motorView);
    Controller control(&service, &clockSerivce, &tempHumidService, &motorService);
    Listener listener(&modeButton, &powerButton, &motorButton, &control, &clockCheck, &dht, &ultraSonic, &motor);
    
    
    while (1)
    {
        listener.checkEvent();
        view.lightView();
        
        delay(10);
    }

    return 0;
}