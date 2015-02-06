extern "C"
{
#include "TExaS.h"
#include "uart.h"
   void EnableInterrupts(void);  // Enable interrupts
}
#include "LaunchPad.h"
#include "GraderSerialIO.h"
#include "Lab5.h"

using namespace ::std;

int main(void)
{  
   TExaS_Init(UART_PIN_PA0,UART_PIN_PA1); 
   UART_Init();
   printf("\nThis program calculates areas of rectangular rooms.\n");
   EnableInterrupts();
   
   GraderSerialIO serialIO;
   Lab5 lab5;
   LaunchPad launchPad(serialIO, lab5);
  
   
   while(1)
	{
      launchPad.Run();
	}
}
