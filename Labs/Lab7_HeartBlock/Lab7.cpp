#include "Lab7.h"

Lab7::Lab7(TimerInterface &timer,
   LEDInterface &readyLED,
   LEDInterface &triggerLED,
   SwitchInterface &atrialSensor)
   : m_timer(timer),
   m_readyLED(readyLED),
   m_triggerLED(triggerLED),
   m_atrialSensor(atrialSensor),
   m_timeAtLastCheck(0),
   m_readyState(false)
{
   m_readyLED.TurnOn();
   m_readyState = true;
}

void Lab7::Run()
{
   int timeSinceLastCheck = m_timer.GetTimeElapsed() - m_timeAtLastCheck;
   if (timeSinceLastCheck > 10 || m_readyState)
   {
      if (m_atrialSensor.IsPressed())
      {
         m_readyLED.TurnOff();
         m_readyState = false;
         m_timeAtLastCheck = m_timer.GetTimeElapsed();         
      }
   }
}