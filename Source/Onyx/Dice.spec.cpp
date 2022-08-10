#include <Onyx/Dice.h>

DEFINE_SPEC(DiceSpec, "Onyx.Dice", EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)

void DiceSpec::Define()
{
	Describe("Roll", [this]()
	{
		It("should return minimum amount", [this]()
		{
			TestTrue("1", Roll("1d1") == 1);
			TestTrue("2", Roll("2d1") == 2);
		});
		It("should return right range", [this]()
		{
			int roll = Roll("1d2");
			TestTrue("Min", roll >= 1);
			TestTrue("Max", roll <= 2);
			roll = Roll("2d2");
			//UE_LOG(LogTemp, Warning, TEXT("Rolled %d"), roll);
			TestTrue("Min", roll >= 2);
			TestTrue("Max", roll <= 4);
			roll = Roll("4d4");
			UE_LOG(LogTemp, Warning, TEXT("Rolled %d"), roll);
			TestTrue("Min", roll >= 4);
			TestTrue("Max", roll <= 16);
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
			InvalidInputs.Emplace("aaa");
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
