#ifdef WIN32
#pragma once

#include "gtest/gtest.h"

namespace TestBase
{
	class WindowsMemoryLeakTestEventListener : public ::testing::EmptyTestEventListener
	{
	private:
		_CrtMemState start;

		const char * GetBlockType(int index);
	public:
		//virtual void OnTestProgramStart(const ::testing::UnitTest& unit_test);
		//virtual void OnTestIterationStart(const ::testing::UnitTest& unit_test, int iteration);
		//virtual void OnEnvironmentsSetUpStart(const ::testing::UnitTest& unit_test);
		//virtual void OnEnvironmentsSetUpEnd(const ::testing::UnitTest& unit_test);
		//virtual void OnTestCaseStart(const ::testing::TestCase& test_case);
		virtual void OnTestStart(const ::testing::TestInfo& test_info);
		//virtual void OnTestPartResult(const ::testing::TestPartResult& test_part_result);
		virtual void OnTestEnd(const ::testing::TestInfo& test_info);
		//virtual void OnTestCaseEnd(const ::testing::TestCase& test_case);
		//virtual void OnEnvironmentsTearDownStart(const ::testing::UnitTest& unit_test);
		//virtual void OnEnvironmentsTearDownEnd(const ::testing::UnitTest& unit_test);
		//virtual void OnTestIterationEnd(const ::testing::UnitTest& unit_test, int iteration);
		//virtual void OnTestProgramEnd(const ::testing::UnitTest& unit_test);
	};
} // namespace TestBase

#endif // #ifdef WIN32
