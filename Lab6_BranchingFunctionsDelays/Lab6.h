#ifndef LAB6_H
#define LAB6_H

#include "TimerInterface.h"
#include "SwitchInterface.h"
#include "RGBLEDInterface.h"

class Lab6
{
public:
   Lab6(TimerInterface timer,
        SwitchInterface switch1,
        RGBLEDInterface led);
};

#endif
