#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H

class LEDInterface
{
public:
   virtual ~LEDInterface() {}
   virtual void TurnOn() = 0;
   virtual void TurnOff() = 0;
};

#endif
