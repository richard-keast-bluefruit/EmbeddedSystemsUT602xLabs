#ifndef LAUNCHPAD_H
#define LAUNCHPAD_H

class LaunchPad
{
public:
   LaunchPad();
   void Run();

private:
   unsigned long m_switch1;
   unsigned long m_switch2;  // input from PF4,PF0
   unsigned long m_LEDOut;      // outputs to PF3,PF2,PF1 (multicolor LED)
   
   void InitPortF();
};

#endif
