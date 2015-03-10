#ifndef LAUNCHPAD_SWITCH_H
#define LAUNCHPAD_SWITCH_H

#include "SwitchInterface.h"
#include "LaunchPadSwitches.h"
   
class LaunchPadSwitch : public SwitchInterface
{
public:
   LaunchPadSwitch(Switches::Value whichSwitch);
   virtual bool IsPressed();

private:
   Switches::Value m_switch;
};

#endif
