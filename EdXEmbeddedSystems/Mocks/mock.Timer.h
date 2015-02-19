#ifndef MOCK_TIMER_H
#define MOCK_TIMER_H

#include "TimerInterface.h"

class MockTimer : public TimerInterface
{
public:
   MockTimer()
   {
      m_elapsedTime = 0;
   }

   // from TimerInterface
   virtual unsigned int GetTimeElapsed()
   {
      return m_elapsedTime;
   }
   virtual void Reset()
   {
      m_elapsedTime = 0;
   }

   // mock helpers
   void MockElapseTime(unsigned int timeInMs)
   {
      m_elapsedTime = timeInMs;
   }

private:
   unsigned int m_elapsedTime;
};

#endif
