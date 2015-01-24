#ifndef MOCK_RGB_LED_H
#define MOCK_RGB_LED_H

#include "RGBLEDInterface.h"

class MockRGBLED : public RGBLEDInterface
{
public:
   void SetColour(RGBLEDColours::Value colour)
   {

   }

   // mock helpers
   RGBLEDColours::Value GetLastColour()
   {
      return RGBLEDColours::ColourCount;
   }
};

#endif
