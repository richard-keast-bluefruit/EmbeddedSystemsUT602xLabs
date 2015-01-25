#include "LaunchPadSwitch.h"
#include "tm4c123gh6pm.h"

LaunchPadSwitch::LaunchPadSwitch(Switches::Value whichSwitch)
 : m_switch(whichSwitch)
{
}

bool LaunchPadSwitch::IsPressed()
{
   bool switchPinState = GPIO_PORTF_DATA_R & m_switch;
   return !(switchPinState); // negative logic
}
