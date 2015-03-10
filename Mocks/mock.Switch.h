#ifndef MOCK_SWITCH_H
#define MOCK_SWITCH_H

#include "SwitchInterface.h"

class MockSwitch : public SwitchInterface
{
public:
   MockSwitch()
   : m_switchPressed(false)
   {
   }

   bool IsPressed()
   {
      return m_switchPressed;
   }

   // mock helpers
   void SetPressed(bool pressed)
   {
      m_switchPressed = pressed;
   }

private:
   bool m_switchPressed;
};

#endif
