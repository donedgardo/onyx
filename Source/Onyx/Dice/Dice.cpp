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

FRollManyOutput Dice::RollMany(const FString RawInput)
{
	const FRollManyInput RollManyInput = GetRollManyInput(RawInput);
	return GetRollManyOutput(RollManyInput);
}

bool Dice::IsInvalidRollInput(FRollManyInput RollInput)
{
	return RollInput.DiceQty <= 0 || RollInput.SideQty <= 0;
}

void Dice::HandleInvalidRollInput(FString RawInput)
{
	throw FString("Roll " + RawInput + " is not valid.");
}

FRollManyOutput Dice::GetRollManyOutput(const FRollManyInput RollManyInput)
{
	int RollSum = 0;
	TArray<int> Rolls;
	for (int i = 0; i < RollManyInput.DiceQty; ++i)
	{
		Dice d = Dice(RollManyInput.SideQty);
		int Roll = d.Roll();
		Rolls.Emplace(Roll);
		RollSum += Roll;
	}
	return FRollManyOutput{
		Rolls,
		RollSum
	};
}

FRollManyInput Dice::GetRollManyInput(const FString RawInput)
{
	TArray<FString> DiceAndSide;
	RawInput.ParseIntoArray(DiceAndSide, TEXT("d"), true);
	if (DiceAndSide.Num() != 2)
	{
		HandleInvalidRollInput(RawInput);
	}
	const FRollManyInput RollInput = FRollManyInput{
		FCString::Atoi(*DiceAndSide[0]),
		FCString::Atoi(*DiceAndSide[1])
	};
	if (IsInvalidRollInput(RollInput))
	{
		HandleInvalidRollInput(RawInput);
	}
	return RollInput;
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
