#ifndef LAUNCHPAD_RGB_LED_H
#define LAUNCHPAD_RGB_LED_H

#include "RGBLEDInterface.h"

class LaunchPadRGBLED : public RGBLEDInterface
{
public:
   virtual void SetColour(RGBLEDColours::Value colour);

private:
   void ClearLEDS();
};

#endif
