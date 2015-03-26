#ifndef MOCK_SWITCH_H
#define MOCK_SWITCH_H

#include "SwitchInterface.h"

class MockSwitch : public SwitchInterface
{
public:
   MockSwitch()
   : m_switchPressed(false),
   m_timesChecked(0)
   {
   }

   bool IsPressed()
   {
      m_timesChecked++;
      return m_switchPressed;
   }

   // mock helpers
   void SetPressed(bool pressed)
   {
      m_switchPressed = pressed;
   }

   int m_timesChecked;

private:
   bool m_switchPressed;
};

#endif
