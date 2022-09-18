#ifndef __CLOCKVIEW_H__
#define __CLOCKVIEW_H__

#include <time.h>
#include "LCD.h"

class ClockView
{
private:
    struct tm timeDate;
    LCD *lcd;

public:
    ClockView(LCD *lcd);
    virtual ~ClockView();
    void updateTime(struct tm *timeData);
    void updateTimer(int cnt);
};

#endif /* __CLOCKVIEW_H__ */