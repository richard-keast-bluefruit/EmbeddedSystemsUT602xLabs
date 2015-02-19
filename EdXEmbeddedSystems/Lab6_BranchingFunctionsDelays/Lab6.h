#ifndef LAB6_H
#define LAB6_H

#include "TimerInterface.h"
#include "RGBLEDInterface.h"
#include "SwitchInterface.h"

class Lab6
{
public:
   Lab6(TimerInterface &timer,
        RGBLEDInterface &led,
        SwitchInterface &switch1);
   void Run();

private:
   TimerInterface &m_timer;
   RGBLEDInterface &m_rgbLED;
   SwitchInterface &m_switch1;
   bool m_isDark;
};

#endif
