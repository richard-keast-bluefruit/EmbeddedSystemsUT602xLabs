#ifndef LAUNCHPAD_H
#define LAUNCHPAD_H

#include "LaunchPadSwitch.h"
#include "LaunchPadRGBLED.h"
#include "Lab4.h"

class LaunchPad
{
public:
   LaunchPad();
   void Run();

private:
   LaunchPadSwitch m_switch1;
   LaunchPadSwitch m_switch2;
   LaunchPadRGBLED m_led;
   Lab4 m_lab4;

   void InitPortF();
};

#endif
