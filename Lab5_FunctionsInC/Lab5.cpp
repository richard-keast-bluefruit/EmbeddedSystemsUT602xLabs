#include "Lab5.h"
#include <string>

using namespace ::std;

unsigned int Lab5::CalcArea(unsigned int length, unsigned int width)
{
   if ((length < 3 || length > 20)
      || (width < 3 || width > 20))
   {
      return 0;
   }
   else
   {
      return length * width;
   }
}
