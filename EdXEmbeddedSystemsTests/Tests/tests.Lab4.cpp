#include "gtest/gtest.h"
#include <memory>

#include "mock.Switch.h"
#include "mock.RGBLED.h"
#include "Lab4.h"

using namespace ::std;

namespace EdXEmbeddedSystemsTests
{
   class TestLab4 : public ::testing::Test
   {
   public:
      unique_ptr<MockSwitch> mockSwitch1;
      unique_ptr<MockSwitch> mockSwitch2;
      unique_ptr<MockRGBLED> mockRGBLED;
      unique_ptr<Lab4> lab4;

      TestLab4()
      {
         mockSwitch1 = make_unique<MockSwitch>();
         mockSwitch2 = make_unique<MockSwitch>();
         mockRGBLED = make_unique<MockRGBLED>();
         lab4 = make_unique<Lab4>(*mockSwitch1, *mockSwitch2, *mockRGBLED);
      }

      ~TestLab4()
      {
      }
   };

   TEST_F(TestLab4, LED_off_when_neither_switch_pressed)
   {
      // Given
      mockSwitch1->SetPressed(false);
      mockSwitch2->SetPressed(false);

      // When
      lab4->Run();

      // Then
      auto expectedColour = RGBLEDColours::Dark;
      auto actualColour = mockRGBLED->GetLastColour();
      ASSERT_EQ(expectedColour, actualColour);
   }

   TEST_F(TestLab4, LED_is_Red_when_switch1_pressed_and_not_switch2)
   {
      // Given
      mockSwitch1->SetPressed(true);
      mockSwitch2->SetPressed(false);

      // When
      lab4->Run();

      // Then
      auto expectedColour = RGBLEDColours::Red;
      auto actualColour = mockRGBLED->GetLastColour();
      ASSERT_EQ(expectedColour, actualColour);
   }

   TEST_F(TestLab4, LED_is_Green_when_switch2_pressed_and_not_switch1)
   {
      // Given
      mockSwitch1->SetPressed(false);
      mockSwitch2->SetPressed(true);

      // When
      lab4->Run();

      // Then
      auto expectedColour = RGBLEDColours::Green;
      auto actualColour = mockRGBLED->GetLastColour();
      ASSERT_EQ(expectedColour, actualColour);
   }

   TEST_F(TestLab4, LED_is_Blue_when_switch1_pressed_and_switch2_is_pressed)
   {
      // Given
      mockSwitch1->SetPressed(true);
      mockSwitch2->SetPressed(true);

      // When
      lab4->Run();

      // Then
      auto expectedColour = RGBLEDColours::Blue;
      auto actualColour = mockRGBLED->GetLastColour();
      ASSERT_EQ(expectedColour, actualColour);
   }
}
