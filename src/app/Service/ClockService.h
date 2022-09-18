#ifndef __CLOCKSERVICE_H__
#define __CLOCKSERVICE_H__

#include <time.h>
#include "ClockView.h"

class ClockService
{
private:
    time_t curTime;
    ClockView *clockView;
    int cnt;
    int restart_cnt;

public:
    bool timerMode;
    ClockService(ClockView *view);
    virtual ~ClockService();
    void updateEvent();
    void updateTimerStopStart();
    void updateTimer();
};

#endif /* __CLOCKSERVICE_H__ */