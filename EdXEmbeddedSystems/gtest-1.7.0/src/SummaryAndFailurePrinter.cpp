// Copyright 2009 Google Inc. All Rights Reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//     * Neither the name of Google Inc. nor the names of its
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Author: vladl@google.com (Vlad Losev)

// This sample shows how to use Google Test listener API to implement
// an alternative console output and how to use the UnitTest reflection API
// to enumerate test cases and tests and to inspect their results.

#include <stdio.h>
#include "gtest/gtest.h"
#include "gtest/WindowsMemoryLeakTestEventListener.h"

using ::testing::EmptyTestEventListener;
using ::testing::TestEventListener;
using ::testing::InitGoogleTest;
using ::testing::Test;
using ::testing::TestCase;
using ::testing::TestEventListeners;
using ::testing::TestInfo;
using ::testing::TestPartResult;
using ::testing::UnitTest;

namespace TestBase{

   // Provides alternative output mode which produces minimal amount of
   // information about tests.
   class TersePrinter : public EmptyTestEventListener {
   private:
      // Called before any test activity starts.
      virtual void OnTestProgramStart(const UnitTest& /* unit_test */) {}

      // Called after all test activities have ended.
      virtual void OnTestProgramEnd(const UnitTest& unit_test) {
         fprintf(stdout, "TEST %s\n", unit_test.Passed() ? "PASSED" : "FAILED");
         fflush(stdout);
      }

      // Called before a test starts.
      virtual void OnTestStart(const TestInfo& test_info) {
         fprintf(stdout,
            "*** Test %s.%s starting.\n",
            test_info.test_case_name(),
            test_info.name());
         fflush(stdout);
      }

      // Called after a failed assertion or a SUCCEED() invocation.
      virtual void OnTestPartResult(const TestPartResult& test_part_result) {
         fprintf(stdout,
            "%s in %s:%d\n%s\n",
            test_part_result.failed() ? "*** Failure" : "Success",
            test_part_result.file_name(),
            test_part_result.line_number(),
            test_part_result.summary());
         fflush(stdout);
      }

      // Called after a test ends.
      virtual void OnTestEnd(const TestInfo& test_info) {
         fprintf(stdout,
            "*** Test %s.%s ending.\n",
            test_info.test_case_name(),
            test_info.name());
         fflush(stdout);
      }
   };  // class TersePrinter

   class TestEventListenerProxy : public TestEventListener
   {
   public:
      explicit TestEventListenerProxy(TestEventListener* event_listener) { listener = event_listener; };
      virtual ~TestEventListenerProxy() { };

      virtual void OnTestProgramStart(const UnitTest& unit_test) { listener->OnTestProgramStart(unit_test); };
      virtual void OnTestIterationStart(const UnitTest& unit_test, int test_case) { listener->OnTestIterationStart(unit_test, test_case); };
      virtual void OnEnvironmentsSetUpStart(const UnitTest& unit_test) { listener->OnEnvironmentsSetUpStart(unit_test); };
      virtual void OnEnvironmentsSetUpEnd(const UnitTest& unit_test){ listener->OnEnvironmentsSetUpEnd(unit_test); };
      virtual void OnTestCaseStart(const TestCase& test_case){ listener->OnTestCaseStart(test_case); };
      virtual void OnTestStart(const TestInfo& test_info){ listener->OnTestStart(test_info); };
      virtual void OnTestPartResult(const TestPartResult& result){ listener->OnTestPartResult(result); };
      virtual void OnTestEnd(const TestInfo& test_info){ listener->OnTestEnd(test_info); };
      virtual void OnTestCaseEnd(const TestCase& test_case){ listener->OnTestCaseEnd(test_case); };
      virtual void OnEnvironmentsTearDownStart(const UnitTest& unit_test){ listener->OnEnvironmentsTearDownStart(unit_test); };
      virtual void OnEnvironmentsTearDownEnd(const UnitTest& unit_test){ listener->OnEnvironmentsTearDownEnd(unit_test); };
      virtual void OnTestIterationEnd(const UnitTest& unit_test, int iteration){ listener->OnTestIterationEnd(unit_test, iteration); };
      virtual void OnTestProgramEnd(const UnitTest& unit_test){ listener->OnTestProgramEnd(unit_test); };

   protected:
      TestEventListener* listener;
   };

   class CaseSummaryAndFailurePrinter : public TestEventListenerProxy
   {
   public:
      explicit CaseSummaryAndFailurePrinter(TestEventListener* default_printer)
         : TestEventListenerProxy(default_printer)
      {
      }

      virtual void OnEnvironmentsTearDownStart(const UnitTest& /*unit_test*/) { }
      virtual void OnEnvironmentsSetUpStart(const UnitTest& /*unit_test*/) { }
      virtual void OnTestStart(const TestInfo& /*test_info*/) { }

      virtual void OnTestEnd(const TestInfo& test_info) {
         if (test_info.result()->Failed())
            listener->OnTestEnd(test_info);
      }
   };

   class SummaryAndFailurePrinter : public CaseSummaryAndFailurePrinter
   {
   public:
      explicit SummaryAndFailurePrinter(TestEventListener* default_printer)
         : CaseSummaryAndFailurePrinter(default_printer)
      {
      }

      virtual void OnTestCaseStart(const TestCase& /*test_case*/) { }
      virtual void OnTestCaseEnd(const TestCase& /*test_case*/) { }
   };

}  // namespace
