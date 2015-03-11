#ifndef SERIAL_IO_INTERFACE_H
#define SERIAL_IO_INTERFACE_H

#include <string>

class SerialIOInterface
{
public:
   virtual ~SerialIOInterface() {}
   virtual void SendString(std::string txString) = 0;
   virtual std::string ReceiveString() = 0;
};

#endif
