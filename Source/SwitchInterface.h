#ifndef SWITCH_INTERFACE_H
#define SWITCH_INTERFACE_H

class SwitchInterface
{
public:
   ~SwitchInterface() {}
   virtual bool IsPressed() = 0;
};

#endif
