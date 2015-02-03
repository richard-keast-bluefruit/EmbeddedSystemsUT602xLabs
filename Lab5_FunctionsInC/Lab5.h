#ifndef LAB5_H
#define LAB5_H

#include "SerialIOInterface.h"

class Lab5
{
public:
   Lab5(SerialIOInterface &serialIO);
   void Run();

private:
   SerialIOInterface &m_serialIO;
      
};

#endif
