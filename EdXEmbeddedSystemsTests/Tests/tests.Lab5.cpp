#include "gtest/gtest.h"
#include <memory>

#include "mock.SerialIO.h"
#include "Lab5.h"

using namespace ::std;

namespace EdXEmbeddedSystemsTests
{
   class TestLab5 : public ::testing::Test
   {
   public:
      unique_ptr<Lab5> lab5;

      TestLab5()
      {
         lab5 = make_unique<Lab5>();
      }

      ~TestLab5()
      {
      }
   };

   TEST_F(TestLab5, Calculate_area_with_length_and_width)
   {
      // Given


      // When


      // Then

   }

}
