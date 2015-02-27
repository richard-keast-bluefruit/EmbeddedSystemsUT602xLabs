#include "LaunchPad.h"
#include <cstdio>
#include <cstdlib>
#include <string>
#include "tm4c123gh6pm.h"

using namespace ::std;

LaunchPad::LaunchPad(SerialIOInterface &serialIO, Lab5 &lab5)
 : m_serialIO(serialIO),
   m_lab5(lab5)
{
}

void LaunchPad::Run()
{
   unsigned long length, width, area;
   string lengthString;
   string widthString;
   string areaString;
   
   m_serialIO.SendString("\nGive length: ");
   lengthString = m_serialIO.ReceiveString();
   length = atoi(lengthString.c_str());
   
   m_serialIO.SendString("\nGive width: ");
   widthString = m_serialIO.ReceiveString();
   width = atoi(widthString.c_str());
   
   area = m_lab5.CalcArea(length, width);
   char temp[15];
   sprintf(temp, "%lu", area);
   areaString = temp;
   
   m_serialIO.SendString("\nArea of the room is " + areaString + "\n");
}
