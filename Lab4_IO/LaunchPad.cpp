#include "LaunchPad.h"
#include "tm4c123gh6pm.h"

LaunchPad::LaunchPad()
{
   InitPortF();
}

void LaunchPad::Run()
{
   m_switch1 = GPIO_PORTF_DATA_R & 0x10;
   m_switch2 = GPIO_PORTF_DATA_R & 0x01;
   
   if (!m_switch1 && !m_switch2)
	{                     
      GPIO_PORTF_DATA_R = 0x04;
   } 
	else
	{                           
      if ((!m_switch1) && m_switch2)
		{                
        GPIO_PORTF_DATA_R = 0x02;
      } 
		else if (m_switch1 && (!m_switch2))
      {              
         GPIO_PORTF_DATA_R = 0x08;
      }
		else
		{                        
         GPIO_PORTF_DATA_R = 0x00;
      }
   }
}

void LaunchPad::InitPortF()
{
   volatile unsigned long delay;
   SYSCTL_RCGC2_R |= 0x00000020;     // 1) F clock
   delay = SYSCTL_RCGC2_R;           // delay   
   GPIO_PORTF_LOCK_R = 0x4C4F434B;   // 2) unlock PortF PF0  
   GPIO_PORTF_CR_R = 0x1F;           // allow changes to PF4-0       
   GPIO_PORTF_AMSEL_R = 0x00;        // 3) disable analog function
   GPIO_PORTF_PCTL_R = 0x00000000;   // 4) GPIO clear bit PCTL  
   GPIO_PORTF_DIR_R = 0x0E;          // 5) PF4,PF0 input, PF3,PF2,PF1 output   
   GPIO_PORTF_AFSEL_R = 0x00;        // 6) no alternate function
   GPIO_PORTF_PUR_R = 0x11;          // enable pullup resistors on PF4,PF0       
   GPIO_PORTF_DEN_R = 0x1F;          // 7) enable digital pins PF4-PF0      
}
