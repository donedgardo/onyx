#include <Onyx/Dice/Dice.h>

DEFINE_SPEC(DiceSpec, "Onyx.Dice", EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)

struct FRollManyRangeTestCase
{
	FString Input;
	int Min;
	int Max;
};

struct FRollRangeTestCase
{
	int Input;
	int Min;
	int Max;
};

void DiceSpec::Define()
{
	Describe("RollMany", [this]()
	{
		It("should return right range", [this]()
		{
			TArray<FRollManyRangeTestCase> RollRangeTestCases;
			RollRangeTestCases.Emplace(FRollManyRangeTestCase{
				"1d1",
				1,
				1,
			});
			RollRangeTestCases.Emplace(FRollManyRangeTestCase{
				"2d1",
				2,
				2,
			});
			RollRangeTestCases.Emplace(FRollManyRangeTestCase{
				"1d2",
				1,
				2
			});
			RollRangeTestCases.Emplace(FRollManyRangeTestCase{
				"2d2",
				2,
				4
			});
			RollRangeTestCases.Emplace(FRollManyRangeTestCase{
				"4d4",
				4,
				16
			});
			RollRangeTestCases.Emplace(FRollManyRangeTestCase{
				"5d9",
				5,
				45
			});
			RollRangeTestCases.Emplace(FRollManyRangeTestCase{
				"10d10",
				10,
				100
			});
			for (const auto [Input, Min, Max] : RollRangeTestCases)
			{
				const auto [Rolls, Result] = Dice::RollMany(Input);
				TestTrue("Min", Result >= Min);
				TestTrue("Max", Result <= Max);
			}
		});
	});

	Describe("RollMany with an invalid roll input", [this]()
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
					Dice::RollMany(InvalidInput);
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

	Describe("Roll", [this]()
	{
		It("should return correct range", [this]()
		{
			TArray<FRollRangeTestCase> RollRangeTestCases;
			RollRangeTestCases.Emplace(FRollRangeTestCase{
				1,
				1,
				1,
			});
			RollRangeTestCases.Emplace(FRollRangeTestCase{
				10,
				1,
				10,
			});
			RollRangeTestCases.Emplace(FRollRangeTestCase{
				20,
				1,
				20,
			});
			for (auto RollRangeTestCase : RollRangeTestCases)
			{
				Dice d = Dice(RollRangeTestCase.Input);
				int roll = d.Roll();
				TestTrue("Min", roll >= RollRangeTestCase.Min);
				TestTrue("Max", roll <= RollRangeTestCase.Max);
			}
		});
	});
	Describe("RollWithAdvantage", [this]()
	{
		It("rolls twice", [this]()
		{
			Dice d = Dice(20);
			FRollManyOutput r = d.RollWithAdvantage();
			TestTrue("Rolls", r.Rolls.Num() == 2);
		});
		It("picks the higher of two rolls", [this]()
		{
			Dice d = Dice(20);
			FRollManyOutput r = d.RollWithAdvantage();
			for (const auto Roll : r.Rolls)
			{
				TestTrue("Max", r.Result >= Roll);
			}
		});
	});
	Describe("RollWithDisadvantage", [this]()
	{
		It("rolls twice", [this]()
		{
			const Dice d = Dice(20);
			const FRollManyOutput r = d.RollWithDisadvantage();
			TestTrue("Rolls", r.Rolls.Num() == 2);
		});
		It("picks the lower of two rolls", [this]()
		{
			Dice d = Dice(20);
			FRollManyOutput r = d.RollWithDisadvantage();
			for (const auto Roll : r.Rolls)
			{
				TestTrue("Min", r.Result <= Roll);
			}
		});
	});

}
