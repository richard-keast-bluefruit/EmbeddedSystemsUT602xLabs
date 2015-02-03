extern "C"
{
#include "LED.h"
#include "PLL.h"
#include "UART.h"
}
#include <cstring>
using namespace ::std;

void OutCRLF(void)
{
  UART_OutChar(CR);
  UART_OutChar(LF);
}

void GetLine(char* buffer);
void PutLine(char* buffer);
void InterpretLine(char* buffer);
	
int main(void)
{
  char buffer[20]; 

  PLL_Init();
	LED_Init();
  UART_Init();              // initialize UART
  OutCRLF();

	PutLine("********************************************");
	PutLine("** Welcome");
	PutLine("********************************************");
  while(1)
	{
		GetLine(buffer);
		InterpretLine(buffer);
  }
}

void PutLine(char* buffer)
{
	UART_OutString(buffer); 	
	OutCRLF();		
}

void GetLine(char* buffer)
{
	UART_OutString("InString: ");
	UART_InString(buffer, 19);
	
	OutCRLF();
	UART_OutString("Recieved:"); 
	UART_OutString(buffer); 
	OutCRLF();	
}

void InterpretLine(char* buffer)
{	
	if(strcmp("red",buffer)==0) 
	{
		GPIO_PORTF_DATA_R 	= 0x02;
		return;
	}
	if(strcmp("blue",buffer)==0) 
	{
		GPIO_PORTF_DATA_R 	= 0x04;
		return;
	}
	if(strcmp("green",buffer)==0) 
	{
		GPIO_PORTF_DATA_R = 0x08;
		return;
	}
	if(strcmp("yellow",buffer)==0) 
	{
		GPIO_PORTF_DATA_R 	= 0x0A;
		return;
	}
	if(strcmp("sky",buffer)==0) 
	{
		GPIO_PORTF_DATA_R = 0x0C;
		return;
	}
	if(strcmp("white",buffer)==0) 
	{
		GPIO_PORTF_DATA_R 	= 0x0E;
		return;
	}
	if(strcmp("pink",buffer)==0) 
	{
		GPIO_PORTF_DATA_R 	= 0x06;
		return;
	}	
	GPIO_PORTF_DATA_R 	= 0x00;	
}
