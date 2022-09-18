#include "ClockService.h"
#include <wiringPi.h>

ClockService::ClockService(ClockView *view)
{
    curTime = 0;
    clockView = view;
    timerMode = false;
    cnt = 0;
    restart_cnt = 0;
}

ClockService::~ClockService()
{
}

void ClockService::updateEvent()
{
    curTime = time(NULL);
    struct tm *timeDate = localtime(&curTime);
    clockView->updateTime(timeDate);
}

void ClockService::updateTimerStopStart()
{
    std::cout << "stopREstStart!" << std::endl;
    restart_cnt++;
    // clockView->updateTimer(cnt);
}

static unsigned int prevTimer = 0;
void ClockService::updateTimer()
{
    switch (restart_cnt)
    {
    case 0:
        cnt = 0;
        break;
    case 1:
        if (millis() - prevTimer > 1000)
        {
            prevTimer = millis();
            cnt++;
        }
        
        break;
    case 2:
        /* code */
        break;

    default:
        restart_cnt = 0;
        break;
    }

    clockView->updateTimer(cnt);
}