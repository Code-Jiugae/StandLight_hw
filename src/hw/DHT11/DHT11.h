#ifndef __DHT11_H__
#define __DHT11_H__

#include "DHT_Data.h"

class DHT11
{
private:
    int pinNumber;
    int data[5];
    DHT_Data dhtData;

    void startTrigger();
    void waitResponse();
    void clearData();

public:
    DHT11(int pin);
    virtual ~DHT11();
    DHT_Data readData();

    
    static int pre_RH;
    static int pre_RHDec;
    static int pre_Temp;
    static int pre_TempDec;
};

#endif /* __DHT11_H__ */