#include "Misc/AutomationTest.h"
#include <Onyx/Dice.h>

DEFINE_SPEC(DiceSpec, "Onyx.Dice", EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)

void DiceSpec::Define()
{
	Describe("Rolling one dice of one side", [this]()
	{
		Describe("of one sides", [this]()
		{
			It("should roll 1", [this]()
			{
				TestTrue("1", Roll("1d1") == 1);
			});
		});
		Describe("of two sides", [this]()
		{
			It("should roll between 1 and 2", [this]()
			{
				int roll = Roll("1d2");
				TestTrue("Min", roll >= 1);
				TestTrue("Max", roll <= 2);
			});
		});
	});

	Describe("Rolling two dice of one side", [this]()
	{
		It("should roll 2", [this]()
		{
			TestTrue("2", Roll("2d1") == 2);
		});
	});

	Describe("An invalid roll input", [this]()
	{
		It("should return exception", [this]()
		{
			TArray<FString> InvalidInputs;
			InvalidInputs.Emplace("cd1");
			InvalidInputs.Emplace("0d1");
			InvalidInputs.Emplace("1d0");
			InvalidInputs.Emplace("111");
			for (const auto& InvalidInput : InvalidInputs)
			{
				try
				{
					Roll(InvalidInput);
					TestTrue("Should throw", false);
				}
				catch (FString error)
				{
					FString expectedError = "Roll " + InvalidInput + " is not valid.";
					TestEqual("Expected Error", error, expectedError);
				}
			}
		});
	});
}
