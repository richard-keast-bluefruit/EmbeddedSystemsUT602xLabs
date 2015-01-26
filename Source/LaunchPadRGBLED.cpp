#include "LaunchPadRGBLED.h"
#include "tm4c123gh6pm.h"

static const unsigned short RedLED = 0x02;
static const unsigned short BlueLED = 0x04;
static const unsigned short GreenLED = 0x08;

void LaunchPadRGBLED::SetColour(RGBLEDColours::Value colour)
{
   ClearLEDS();
   
   switch (colour)
   {
      case RGBLEDColours::Red:
         GPIO_PORTF_DATA_R |= RedLED;
         break;
      case RGBLEDColours::Blue:
         GPIO_PORTF_DATA_R |= BlueLED;
         break;
      case RGBLEDColours::Green:
         GPIO_PORTF_DATA_R |= GreenLED;
         break;
      case RGBLEDColours::Yellow:
         GPIO_PORTF_DATA_R |= (RedLED & GreenLED);
         break;
      case RGBLEDColours::SkyBlue:
         GPIO_PORTF_DATA_R |= (BlueLED & GreenLED);
         break;
      case RGBLEDColours::White:
         GPIO_PORTF_DATA_R |= (RedLED & BlueLED & GreenLED);
         break;
      case RGBLEDColours::Pink:
         GPIO_PORTF_DATA_R |= (RedLED & BlueLED);
         break;
      case RGBLEDColours::Dark:
      default:
         break;
   }
}

void LaunchPadRGBLED::ClearLEDS()
{
   GPIO_PORTF_DATA_R &= (~RedLED & ~BlueLED & ~GreenLED);
}
