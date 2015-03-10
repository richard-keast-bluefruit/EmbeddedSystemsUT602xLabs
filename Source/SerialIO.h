#ifndef SERIAL_IO_H
#define SERIAL_IO_H

#include "SerialIOInterface.h"
#include "UartInterface.h"
#include <string>

class SerialIO : public SerialIOInterface
{
public:
   SerialIO(UartInterface &uart);

   // from SerialIOInterface
   virtual void SendString(std::string txString);
   virtual std::string ReceiveString();

private:
   UartInterface &m_uart;
};

#endif
