// This is your second program to run on the LaunchPad
// You will debug this program as your Lab 4
// If both switches SW1 and SW2 are pressed, the LED should be blue
// If just SW1 switch is pressed,            the LED should be red
// If just SW2 switch is pressed,            the LED should be green
// If neither SW1 or SW2 is pressed,         the LED should be off

// LaunchPad built-in hardware
// SW1 left switch is negative logic PF4 on the Launchpad
// SW2 right switch is negative logic PF0 on the Launchpad
// red LED connected to PF1 on the Launchpad
// blue LED connected to PF2 on the Launchpad
// green LED connected to PF3 on the Launchpad

extern "C"
{
#include "TExaS.h"
}
#include "LaunchPad.h"

int main(void)
{    
  TExaS_Init(SW_PIN_PF40,LED_PIN_PF321); 
  //EnableInterrupts();  // The grader uses interrupts
   
   LaunchPad launchPad;
   
   while(1)
	{
      launchPad.Run();
	}
}

// Color    LED(s) PortF
// dark     ---    0
// red      R--    0x02
// blue     --B    0x04
// green    -G-    0x08
// yellow   RG-    0x0A
// sky blue -GB    0x0C
// white    RGB    0x0E
// pink     R-B    0x06


