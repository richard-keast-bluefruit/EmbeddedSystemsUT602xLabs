#ifndef LAUNCHPAD_UART0_H
#define LAUNCHPAD_UART0_H

#include "UartInterface.h"

class LaunchPadUart0 : public UartInterface
{
public:
   LaunchPadUart0();

   // from UartInterface
   virtual bool ReadyToSend();
   virtual void TransmitByte(unsigned char txData);
   virtual bool IsByteReceived();
   virtual unsigned char GetByteReceived();

private:
   void Initialise();
};

#endif
