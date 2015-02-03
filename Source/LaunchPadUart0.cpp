#include "LaunchPadUart0.h"
#include "tm4c123gh6pm.h"

LaunchPadUart0::LaunchPadUart0()
{
  Initialise();
}

void LaunchPadUart0::Initialise()
{
  SYSCTL_RCGC1_R |= SYSCTL_RCGC1_UART0;                              // activate UART0
  SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOA;                              // activate port A
  UART0_CTL_R &= ~UART_CTL_UARTEN;                                   // disable UART
  UART0_IBRD_R = 43;                                                 // IBRD = int(80,000,000 / (16 * 115200)) = int(43.402778)
  UART0_FBRD_R = 26;                                                 // FBRD = round(0.402778 * 64) = 26
  UART0_LCRH_R = (UART_LCRH_WLEN_8 | UART_LCRH_FEN);                 // 8 bit word length (no parity bits, one stop bit, FIFOs)
  UART0_CTL_R |= UART_CTL_UARTEN;                                    // enable UART
  GPIO_PORTA_AFSEL_R |= 0x03;                                        // enable alt funct on PA1-0
  GPIO_PORTA_DEN_R |= 0x03;                                          // enable digital I/O on PA1-0
  GPIO_PORTA_PCTL_R = (GPIO_PORTA_PCTL_R & 0xFFFFFF00) + 0x00000011; // configure PA1-0 as UART
  GPIO_PORTA_AMSEL_R &= ~0x03;                                       // disable analog functionality on PA
}

bool LaunchPadUart0::ReadyToSend()
{
   return ((UART0_FR_R & UART_FR_TXFF) == 0);
}

void LaunchPadUart0::TransmitByte(unsigned char txData)
{
  while(!ReadyToSend());
  UART0_DR_R = txData;
}

bool LaunchPadUart0::IsByteReceived()
{
   return ((UART0_FR_R & UART_FR_RXFE) == 0);
}

unsigned char LaunchPadUart0::GetByteReceived()
{
  while(!IsByteReceived());
  return((unsigned char)(UART0_DR_R&0xFF));
}
