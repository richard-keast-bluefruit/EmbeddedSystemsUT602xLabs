#include "Lab7.h"

Lab7::Lab7(TimerInterface &timer,
   LEDInterface &readyLED,
   LEDInterface &triggerLED,
   SwitchInterface &atrialSensor)
   : m_timer(timer),
   m_readyLED(readyLED),
   m_triggerLED(triggerLED),
   m_atrialSensor(atrialSensor)
{
   m_readyLED.TurnOn();
}

void Lab7::Run()
{
   if (m_atrialSensor.IsPressed())
   {
      m_readyLED.TurnOff();
   }
}