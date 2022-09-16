#include "Service.h"

Service::Service(View *viewer)
{
    view = viewer;
    lightState = LIGHT_OFF;
    bDistacneLight = false;
    distanceOffCounter = 0;
}

Service::~Service()
{

}

void Service::updateState(std::string strState)
{
    switch (lightState)
    {
        case LIGHT_OFF:
            if (strState == "modeButton") {
                lightState = LIGHT_1;
                view->setState(lightState);
            }
        break;

        case LIGHT_1:
            printf("LIGHT_1!!!!\n");
            if (strState == "modeButton") {
                lightState = LIGHT_2;
            }
            if (strState == "powerButton") {
                lightState = LIGHT_OFF;
            }
            if(bDistacneLight)
            {
                view->setState(lightState);
            }
            else
            {
                view->setState(LIGHT_OFF);
            }
            // view->setState(lightState);
        break;
        case LIGHT_2:
            if (strState == "modeButton") {
                lightState = LIGHT_3;
            }
            if (strState == "powerButton") {
                lightState = LIGHT_OFF;
            }
            view->setState(lightState);
        break;
        case LIGHT_3:
            if (strState == "modeButton") {
                lightState = LIGHT_4;
            }
            if (strState == "powerButton") {
                lightState = LIGHT_OFF;
            }
            if(bDistacneLight)
            {
                view->setState(lightState);
            }
            else
            {
                view->setState(LIGHT_OFF);
            }
            // view->setState(lightState);
        break;
        case LIGHT_4:
            if (strState == "modeButton") {
                lightState = LIGHT_5;
            }
            if (strState == "powerButton") {
                lightState = LIGHT_OFF;
            }
            if(bDistacneLight)
            {
                view->setState(lightState);
            }
            else
            {
                view->setState(LIGHT_OFF);
            }
            // view->setState(lightState);
        break;
        case LIGHT_5:
            if (strState == "modeButton") {
                lightState = LIGHT_OFF;
            }
            if (strState == "powerButton") {
                lightState = LIGHT_OFF;
            }
            if(bDistacneLight)
            {
                view->setState(lightState);
            }
            else
            {
                view->setState(LIGHT_OFF);
            }
            // view->setState(lightState);
        break;
    }
}

void Service::updateDistance(int distance)
{
    printf("distance : %d\n", distance);
    
    if(distance < 0)
    {
        // Light off
        distanceOffCounter++;
        if(distanceOffCounter >= 10)
        {
            distanceOffCounter = 0;
            bDistacneLight = false;
            view->setState(LIGHT_OFF);
        }
    }
    else
    {
        distanceOffCounter = 0;
        // Light on
        bDistacneLight = true;
        view->setState(lightState);
    }
}
