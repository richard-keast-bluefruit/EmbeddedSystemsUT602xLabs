#ifndef GRADER_SERIAL_IO_H
#define GRADER_SERIAL_IO_H

#include "SerialIOInterface.h"
#include <string>

class GraderSerialIO : public SerialIOInterface
{
public:
   GraderSerialIO();

   // from SerialIOInterface
   virtual void SendString(std::string txString);
   virtual std::string ReceiveString();

   static const unsigned int MaxCharsToReceive = 80;
};

#endif
