#include "gtest/gtest.h"
#include <memory>

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
         mockSwitch1 = make_unique<MockSwitch>(Switches::Switch1);
         mockSwitch2 = make_unique<MockSwitch>(Switches::Switch2);
         mockRGBLED = make_unique<MockRGBLED>();
         lab4 = make_unique<Lab4>(mockSwitch1, mockSwitch2, mockRGBLED);
      }

      ~TestLab4()
      {
      }
   };

   TEST_F(TestLab4, LED_off_when_neither_switch_pressed)
   {
      // Given
      mockSwitch1->SetPressedState(false);
      mockSwitch2->SetPressedState(false);

      // When
      lab4->Run();
      
      // Then
      auto expectedColour = RGBLEDColours::Dark;
      auto actualColour = mockRGBLED->GetLastColour();
      ASSERT_EQ(expectedColour, actualColour);
   }
}
