#ifndef LAB7_H
#define LAB7_H

#include "TimerInterface.h"
#include "LEDInterface.h"
#include "SwitchInterface.h"

class Lab7
{
public:
   Lab7(TimerInterface &timer,
      LEDInterface &readyLED,
      LEDInterface &triggerLED,
      SwitchInterface &atrialSensor);
   void Run();

private:
   TimerInterface &m_timer;
   LEDInterface &m_readyLED;
   LEDInterface &m_triggerLED;
   SwitchInterface &m_atrialSensor;
};

#endif
