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

   TEST_F(TestLab5, Calculate_area_with_length_5_and_width_5_returns_area)
   {
      // Given
      unsigned int length = 5;
      unsigned int width = 5;
      unsigned int actualArea = 0;
      unsigned int expectedArea = 25;

      // When
      actualArea = lab5->CalcArea(length, width);

      // Then
      ASSERT_EQ(expectedArea, actualArea);
   }

   TEST_F(TestLab5, Calculate_area_with_length_less_than_3_returns_zero)
   {
      // Given
      unsigned int length = 2;
      unsigned int width = 5;
      unsigned int actualArea = 10;
      unsigned int expectedArea = 0;

      // When
      actualArea = lab5->CalcArea(length, width);

      // Then
      ASSERT_EQ(expectedArea, actualArea);
   }

   TEST_F(TestLab5, Calculate_area_with_width_less_than_3_returns_zero)
   {
      // Given
      unsigned int length = 5;
      unsigned int width = 2;
      unsigned int actualArea = 10;
      unsigned int expectedArea = 0;

      // When
      actualArea = lab5->CalcArea(length, width);

      // Then
      ASSERT_EQ(expectedArea, actualArea);
   }

   TEST_F(TestLab5, Calculate_area_with_length_more_than_20_returns_zero)
   {
      // Given
      unsigned int length = 21;
      unsigned int width = 10;
      unsigned int actualArea = 210;
      unsigned int expectedArea = 0;

      // When
      actualArea = lab5->CalcArea(length, width);

      // Then
      ASSERT_EQ(expectedArea, actualArea);
   }

   TEST_F(TestLab5, Calculate_area_with_width_more_than_20_returns_zero)
   {
      // Given
      unsigned int length = 10;
      unsigned int width = 21;
      unsigned int actualArea = 210;
      unsigned int expectedArea = 0;

      // When
      actualArea = lab5->CalcArea(length, width);

      // Then
      ASSERT_EQ(expectedArea, actualArea);
   }
}
