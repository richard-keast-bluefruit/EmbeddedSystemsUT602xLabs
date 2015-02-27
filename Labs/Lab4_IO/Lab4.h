#ifndef LAB4_H
#define LAB4_H

#include "SwitchInterface.h"
#include "RGBLEDInterface.h"

class Lab4
{
public:
   Lab4(SwitchInterface &switch1, SwitchInterface &switch2, RGBLEDInterface &rgbLED);
   void Run();

private:
   SwitchInterface &m_switch1;
   SwitchInterface &m_switch2;
   RGBLEDInterface &m_rgbLED;
};

#endif
