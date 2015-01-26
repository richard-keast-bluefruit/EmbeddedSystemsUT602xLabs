#ifndef LAUNCHPAD_RGB_LED_H
#define LAUNCHPAD_RGB_LED_H

#include "RGBLEDInterface.h"

class LaunchPadRGBLED : public RGBLEDInterface
{
public:
   virtual void SetColour(RGBLEDColours::Value colour);

private:
   const unsigned short RedLED = 0x02;
   const unsigned short BlueLED = 0x04;
   const unsigned short GreenLED = 0x06;

   void ClearLEDS();
};

#endif
