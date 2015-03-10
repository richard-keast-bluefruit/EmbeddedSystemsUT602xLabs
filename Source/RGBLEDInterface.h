#ifndef RGB_LED_INTERFACE_H
#define RGB_LED_INTERFACE_H

struct RGBLEDColours
{
   enum Value
   {
      Dark,
      Red,
      Blue,
      Green,
      Yellow,
      SkyBlue,
      White,
      Pink,
      ColourCount
   };
};

class RGBLEDInterface
{
public:
   virtual ~RGBLEDInterface() {}
   virtual void SetColour(RGBLEDColours::Value colour) = 0;
};

#endif
