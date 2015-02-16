#ifndef MOCK_SERIAL_IO_H
#define MOCK_SERIAL_IO_H

#include "SerialIOInterface.h"

class MockSerialIO : public SerialIOInterface
{
public:
   virtual void SendString(std::string txString)
   {

   }
   virtual std::string ReceiveString()
   {
      return "";
   }
};

#endif
