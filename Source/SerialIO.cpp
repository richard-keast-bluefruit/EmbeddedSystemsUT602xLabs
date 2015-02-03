#include "SerialIO.h"
#inlcude <sstream>

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
   
   return "";
}
