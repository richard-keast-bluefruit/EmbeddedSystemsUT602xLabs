#ifndef TIMER_INTERFACE_H
#define TIMER_INTERFACE_H

class TimerInterface
{
public:
   virtual unsigned int GetTimeElapsed() = 0;
   virtual void Reset() = 0;
};

#endif
