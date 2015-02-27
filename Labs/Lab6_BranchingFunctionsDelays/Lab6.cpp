#include "Lab6.h"

Lab6::Lab6(TimerInterface &timer,
           RGBLEDInterface &led,
           SwitchInterface &switch1)
   : m_timer(timer),
     m_rgbLED(led),
     m_switch1(switch1),
     m_isDark(false)
{
   m_rgbLED.SetColour(RGBLEDColours::Blue);
}

void Lab6::Run()
{
   if (!m_switch1.IsPressed())
   {
      m_rgbLED.SetColour(RGBLEDColours::Blue);
      return;
   }

   if (m_timer.GetTimeElapsed() != 100) return;
   
   if (!m_isDark)
   {
      m_rgbLED.SetColour(RGBLEDColours::Dark);
   }
   else
   {
      m_rgbLED.SetColour(RGBLEDColours::Blue);
   }
   m_isDark = !m_isDark;
   m_timer.Reset();
}