#ifndef MOCK_LED_H
#define MOCK_LED_H

#include "LEDInterface.h"

class MockLED : public LEDInterface
{
public:
   MockLED()
      : isOn(false)
   {
   }

   virtual void TurnOn()
   {
      isOn = true;
   }

   virtual void TurnOff()
   {
      isOn = false;
   }

   bool isOn;
};

#endif
