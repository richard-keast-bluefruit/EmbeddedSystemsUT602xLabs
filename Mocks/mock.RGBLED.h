#ifndef MOCK_RGB_LED_H
#define MOCK_RGB_LED_H

#include "RGBLEDInterface.h"

class MockRGBLED : public RGBLEDInterface
{
public:
   MockRGBLED()
   : m_lastColour(RGBLEDColours::ColourCount)
   {
   }

   void SetColour(RGBLEDColours::Value colour)
   {
      m_lastColour = colour;
   }

   // mock helpers
   RGBLEDColours::Value GetLastColour()
   {
      return m_lastColour;
   }

private:
   RGBLEDColours::Value m_lastColour;
};

#endif
