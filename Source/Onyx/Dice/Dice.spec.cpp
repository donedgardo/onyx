#include <Onyx/Dice/Dice.h>

DEFINE_SPEC(DiceSpec, "Onyx.Dice", EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)

struct FRollRangeTestCase
{
	FString Input;
	int Min;
	int Max;
};

void DiceSpec::Define()
{
	Describe("Roll", [this]()
	{
		It("should return right range", [this]()
		{
			TArray<FRollRangeTestCase> RollRangeTestCases;
			RollRangeTestCases.Emplace(FRollRangeTestCase{
				"1d1",
				1,
				1,
			});
			RollRangeTestCases.Emplace(FRollRangeTestCase{
				"2d1",
				2,
				2,
			});
			RollRangeTestCases.Emplace(FRollRangeTestCase{
				"1d2",
				1,
				2
			});
			RollRangeTestCases.Emplace(FRollRangeTestCase{
				"2d2",
				2,
				4
			});
			RollRangeTestCases.Emplace(FRollRangeTestCase{
				"4d4",
				4,
				16
			});
			RollRangeTestCases.Emplace(FRollRangeTestCase{
				"5d9",
				5,
				45
			});
			RollRangeTestCases.Emplace(FRollRangeTestCase{
				"10d10",
				10,
				100
			});
			for (auto RollTestCase : RollRangeTestCases)
			{
				int roll = Dice().Roll(RollTestCase.Input);
				TestTrue("Min", roll >= RollTestCase.Min);
				TestTrue("Max", roll <= RollTestCase.Max);
			}
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
			InvalidInputs.Emplace("-1d10");
			InvalidInputs.Emplace("1d-10");
			for (const auto& InvalidInput : InvalidInputs)
			{
				try
				{
					Dice().Roll(InvalidInput);
					TestTrue("Should throw exception", false);
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
