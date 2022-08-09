#include <Onyx/Dice.h>

IMPLEMENT_SIMPLE_AUTOMATION_TEST(DiceTest, "Onyx.Dice", (EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::SmokeFilter))

bool DiceTest::RunTest(const FString& Parameters)
{
	{
			TestEqual("1d1", Roll("1d1"),  1);
        	TestEqual("2d1", Roll("2d1"), 2);
        	return true;
	}

}
