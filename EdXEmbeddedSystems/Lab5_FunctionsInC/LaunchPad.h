#ifndef LAUNCHPAD_H
#define LAUNCHPAD_H

#include "SerialIOInterface.h"
#include "Lab5.h"

class LaunchPad
{
public:
   LaunchPad(SerialIOInterface &serialIO, Lab5 &lab5);
   void Run();

private:
   SerialIOInterface &m_serialIO;
   Lab5 &m_lab5;
};

#endif
