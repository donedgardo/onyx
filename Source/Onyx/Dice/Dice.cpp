#include "Dice.h"
#include "Math/UnrealMathUtility.h"

Dice::Dice(const int SideQty)
{
	Sides = SideQty;
}

int Dice::Roll() const
{
	return FMath::RandRange(1, Sides);
}

FRollManyOutput Dice::RollWithAdvantage() const
{
	TArray<int> Rolls = RollTwice();
	Rolls.Sort();
	return FRollManyOutput{
		Rolls,
		Rolls.Last()
	};
}

FRollManyOutput Dice::RollWithDisadvantage() const
{
	TArray<int> Rolls = RollTwice();
	Rolls.Sort();
	return FRollManyOutput{
		Rolls,
		Rolls[0]
	};
}

FRollManyOutput Dice::RollMany(const FString RawInput)
{
	const TArray<int> Rolls;
	FRollManyOutput RollManyOutput = FRollManyOutput {
		Rolls,
		0,
	};
	TArray<FString> DiceAndSide;
	RawInput.ParseIntoArray(DiceAndSide, TEXT("d"), true);
	if (DiceAndSide.Num() != 2)
	{
		RollManyOutput.Error = GetErrorMessage(RawInput);
		return RollManyOutput;
	}
	const FRollManyInput RollManyInput = FRollManyInput{
		FCString::Atoi(*DiceAndSide[0]),
		FCString::Atoi(*DiceAndSide[1])
	};
	if (IsInvalidRollInput(RollManyInput))
	{
		RollManyOutput.Error = GetErrorMessage(RawInput);
		return RollManyOutput;
	}
	for (int i = 0; i < RollManyInput.DiceQty; ++i)
	{
		Dice d = Dice(RollManyInput.SideQty);
		int Roll = d.Roll();
		RollManyOutput.Rolls.Emplace(Roll);
		RollManyOutput.Result += Roll;
	}
	return RollManyOutput;
}

TArray<int> Dice::RollTwice() const
{
	TArray<int> Rolls;
	for (int i = 0; i < 2; ++i)
	{
		int Roll = Dice(Sides).Roll();
		Rolls.Emplace(Roll);
	}
	return Rolls;
}

bool Dice::IsInvalidRollInput(FRollManyInput RollInput)
{
	return RollInput.DiceQty <= 0 || RollInput.SideQty <= 0;
}

FString Dice::GetErrorMessage(FString RawInput)
{
	return FString("Roll " + RawInput + " is not valid.");
}
