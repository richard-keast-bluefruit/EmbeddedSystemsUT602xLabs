#include "gtest/gtest.h"
#include <memory>

#include "mock.Timer.h"
#include "mock.LED.h"
#include "mock.Switch.h"
#include "Lab7.h"

using namespace ::std;

namespace EdXEmbeddedSystemsTests
{
   class TestLab7 : public ::testing::Test
   {
   public:
      unique_ptr<MockTimer> mockTimer;
      unique_ptr<MockLED> mockReadyLED;
      unique_ptr<MockLED> mockTriggerLED;
      unique_ptr<MockSwitch> mockAtrialSensorSwitch;
      unique_ptr<Lab7> lab7;

      TestLab7()
      {
         mockTimer = make_unique<MockTimer>();
         mockReadyLED = make_unique<MockLED>();
         mockTriggerLED = make_unique<MockLED>();
         mockAtrialSensorSwitch = make_unique<MockSwitch>();
         lab7 = make_unique<Lab7>(*mockTimer, *mockReadyLED, *mockTriggerLED, *mockAtrialSensorSwitch);
      }

      ~TestLab7()
      {
      }
   };

   TEST_F(TestLab7, ready_LED_stays_on_while_sensor_is_not_triggered)
   {
      lab7->Run();
      ASSERT_TRUE(mockReadyLED->isOn);
      for (int i = 0; i < 3; i++)
      {
         mockTimer->MockElapseTime(250);
         lab7->Run();
         ASSERT_TRUE(mockReadyLED->isOn);
      }
   }

   TEST_F(TestLab7, when_the_switch_is_pressed_the_ready_LED_is_turned_off)
   {
      // Given
      mockAtrialSensorSwitch->SetPressed(true);

      // When
      lab7->Run();

      // Then
      ASSERT_FALSE(mockReadyLED->isOn);
   }
}
