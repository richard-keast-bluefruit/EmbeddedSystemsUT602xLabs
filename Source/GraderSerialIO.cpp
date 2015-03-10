#include "GraderSerialIO.h"
#include <cstdio>

using namespace ::std;

GraderSerialIO::GraderSerialIO()
{
}

void GraderSerialIO::SendString(string txString)
{
   std::printf("%s", txString.c_str());
}

string GraderSerialIO::ReceiveString()
{
   char rxChars[MaxCharsToReceive];
   std::scanf("%s", &rxChars[0]);
   string rxString = static_cast<string>(rxChars);
   return rxString;
}
