extern "C"
{
#include "TExaS.h"
}
#include "LaunchPad.h"

int main(void)
{  
   LaunchPad launchPad;
  
   TExaS_Init(SW_PIN_PF40,LED_PIN_PF321); 
   
   while(1)
	{
      launchPad.Run();
	}
}
