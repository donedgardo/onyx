#include "Dice.h"

bool IsInvalidDiceCount(const int DiceCount)
{
	return DiceCount <= 0;
}

bool IsInvalidSideCount(const int SideCount)
{
	return SideCount <= 0;
}

void HandleInvalidRollInput(FString input)
{
	throw FString("Roll " + input + " is not valid.");
}

int RandomNonZeroNumber(const int InclusiveMax)
{
	srand(time(NULL));
	return rand() % InclusiveMax + 1;
}

struct FRollInput
{
	int Dice;
	int Side;
};

FRollInput GetRollInput(FString RollInput)
{
	TArray<FString> DiceAndSide;
	RollInput.ParseIntoArray(DiceAndSide, TEXT("d"), true);
	if (DiceAndSide.Num() != 2)
	{
		HandleInvalidRollInput(RollInput);
	}
	int DiceQty = FCString::Atoi(*DiceAndSide[0]);
	int SideQty = FCString::Atoi(*DiceAndSide[1]);
	if (IsInvalidDiceCount(DiceQty) || IsInvalidSideCount(SideQty))
	{
		HandleInvalidRollInput(RollInput);
	}
	return FRollInput{
		DiceQty,
		SideQty
	};
}

int Roll(const FString Input)
{
	const auto [Dice, Side] = GetRollInput(Input);
	int RollAmount = 0;
	for (int i = 0; i < Dice; ++i)
	{
		RollAmount += RandomNonZeroNumber(Side);
	}
	return RollAmount;
}
