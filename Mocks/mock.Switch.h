#ifndef MOCK_SWITCH_H
#define MOCK_SWITCH_H

#include "SwitchInterface.h"
#include "Switches.h"

class MockSwitch : public SwitchInterface
{
public:
   MockSwitch(Switches::Value switchValue)
      :
      m_switch(switchValue)
   {
   }

   bool IsPressed()
   {
      return false;
   }

   // mock helpers
   void SetPressedState(bool state)
   {

   }

private:
   Switches::Value m_switch;
};

#endif
