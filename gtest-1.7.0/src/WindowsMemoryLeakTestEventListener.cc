#ifdef WIN32

#include "gtest/WindowsMemoryLeakTestEventListener.h"
#include <iostream>

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

namespace TestBase
{
   void WindowsMemoryLeakTestEventListener::OnTestStart(const ::testing::TestInfo& test_info)
   {
      _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
      // This line is used to enforce a breakpoint on the allocation of the memory reported
      // as leaking from _CrtMemDumpAllObjectsSince
      //_CrtSetBreakAlloc(1593);
      _CrtMemCheckpoint(&start);
   }

   const char * WindowsMemoryLeakTestEventListener::GetBlockType(int index)
   {
      switch(index)
      {
      case _FREE_BLOCK:
         return "_FREE_BLOCK";
      case _NORMAL_BLOCK:
         return "_NORMAL_BLOCK";
      case _CRT_BLOCK:
         return "_CRT_BLOCK";
      case _IGNORE_BLOCK:
         return "_IGNORE_BLOCK";
      case _CLIENT_BLOCK:
         return "_CLIENT_BLOCK";
      default:
         return "";
      }
   }
   void WindowsMemoryLeakTestEventListener::OnTestEnd(const ::testing::TestInfo& test_info)
   {
      if(test_info.result()->Passed())
      {
         int index;
         _CrtMemState end, difference;
         _CrtMemCheckpoint(&end);
         _CrtMemDifference(&difference, &start, &end);
         
         for(index = 0; index < _MAX_BLOCKS; index++)
         {
            EXPECT_EQ(0, difference.lCounts[index]) << "Memory Leak " << GetBlockType(index) << " " << difference.lCounts[index] << " block(s), total size " << difference.lSizes[index] << " bytes";
         }         
         _CrtMemDumpAllObjectsSince(&start);
      }
   }

}

#endif
