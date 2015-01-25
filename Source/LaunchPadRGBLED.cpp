#include "LaunchPadRGBLED.h"
#include "tm4c123gh6pm.h"

void LaunchPadRGBLED::SetColour(RGBLEDColours::Value colour)
{
   switch (colour)
   {
      case RGBLEDColours::Red:
         GPIO_PORTF_DATA_R = 0x02;
         break;
      case RGBLEDColours::Blue:
         GPIO_PORTF_DATA_R = 0x04;
         break;
      case RGBLEDColours::Green:
         GPIO_PORTF_DATA_R = 0x08;
         break;
      case RGBLEDColours::Dark:
         GPIO_PORTF_DATA_R = 0x00;
         break;
      default:
         break;
   }
}
