extern "C"
{
#include "TExaS.h"
   void EnableInterrupts(void);  // Enable interrupts
}
#include "LaunchPadUart0.h"
#include "SerialIO.h"
#include "Lab5.h"

int main(void)
{  
   LaunchPadUart0 launchPadUart0;
   SerialIO serialIO(launchPadUart0);
   Lab5 lab5(serialIO);
  
   TExaS_Init(UART_PIN_PA0,UART_PIN_PA1); 
   EnableInterrupts();
   
   while(1)
	{
      lab5.Run();
	}
}
