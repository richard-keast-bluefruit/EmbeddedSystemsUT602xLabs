#include "gtest/gtest.h"
#include <memory>

#include "mock.Timer.h"
#include "mock.RGBLED.h"
#include "mock.Switch.h"
#include "Lab6.h"

using namespace ::std;

namespace EdXEmbeddedSystemsTests
{
   class TestLab6 : public ::testing::Test
   {
   public:
      unique_ptr<MockTimer> mockTimer;
      unique_ptr<MockRGBLED> mockRGBLED;
      unique_ptr<MockSwitch> mockSwitch;
      unique_ptr<Lab6> lab6;

      TestLab6()
      {
         mockTimer = make_unique<MockTimer>();
         mockRGBLED = make_unique<MockRGBLED>();
         mockSwitch = make_unique<MockSwitch>();
         lab6 = make_unique<Lab6>(*mockTimer, *mockRGBLED, *mockSwitch);
      }

      ~TestLab6()
      {
      }
   };

   TEST_F(TestLab6, Led_light_always_blue_when_switch_not_pressed)
   {
      // Given
      mockSwitch->SetPressed(false);

      // When
      lab6->Run();
      
      // Then
      ASSERT_EQ(RGBLEDColours::Blue, mockRGBLED->GetLastColour());
      
      // When
      mockTimer->MockElapseTime(100);
      lab6->Run();

      // Then
      ASSERT_EQ(RGBLEDColours::Blue, mockRGBLED->GetLastColour());

      // When
      mockTimer->MockElapseTime(100);
      lab6->Run();

      // Then
      ASSERT_EQ(RGBLEDColours::Blue, mockRGBLED->GetLastColour());
   }

   TEST_F(TestLab6, Led_light_flashes_for_100ms_every_100ms)
   {
      // Given
      mockSwitch->SetPressed(true);

      // When
      lab6->Run();

      // Then
      ASSERT_EQ(RGBLEDColours::Blue, mockRGBLED->GetLastColour());

      // When
      mockTimer->MockElapseTime(100);
      lab6->Run();

      // Then
      ASSERT_EQ(RGBLEDColours::Dark, mockRGBLED->GetLastColour());

      // When
      mockTimer->MockElapseTime(100);
      lab6->Run();

      // Then
      ASSERT_EQ(RGBLEDColours::Blue, mockRGBLED->GetLastColour());

      // When
      mockTimer->MockElapseTime(100);
      lab6->Run();

      // Then
      ASSERT_EQ(RGBLEDColours::Dark, mockRGBLED->GetLastColour());
   }
   
}
