#include <cstdint>
#include "tm4c123gh6pm.h"
#include "LaunchPad.h"

int main(void)
{
   LaunchPad launchPad;

   while (1)
   {
      launchPad.Run();
   }
}
