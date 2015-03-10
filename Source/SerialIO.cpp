#include "SerialIO.h"

using namespace ::std;

SerialIO::SerialIO(UartInterface &uart)
   : m_uart(uart)
{
}

void SerialIO::SendString(std::string txString)
{
   for (unsigned int index = 0 ; index < txString.length() ; index++)
   {
      m_uart.TransmitByte(txString.at(index));
   }
   m_uart.TransmitByte('\n');
}

string SerialIO::ReceiveString()
{
   string rxString;
   unsigned char rxChar;
   
   while (rxChar != '\n')
   {
      rxChar = m_uart.GetByteReceived();
      rxString.append(1, rxChar);
   }
   
   return rxString;
}
