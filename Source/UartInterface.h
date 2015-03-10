#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

class UartInterface
{
public:
   virtual ~UartInterface() {}
   virtual bool ReadyToSend() = 0;
   virtual void TransmitByte(unsigned char txData) = 0;
   virtual bool IsByteReceived() = 0;
   virtual unsigned char GetByteReceived() = 0;
};

#endif
