#include "Dice.h"

bool IsInvalidDiceCount(const int DiceCount)
{
	return DiceCount <= 0 || DiceCount >= 10;
}

bool IsInvalidSideCount(const int SideCount)
{
	return SideCount <= 0 || SideCount >= 10;
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

struct FRoll
{
	int Dice;
	int Side;
};

FRoll GetDiceAndSideCount(FString RollInput)
{
	TArray<FString> DiceAndSide;
	RollInput.ParseIntoArray(DiceAndSide, TEXT("d"), true);
	if (DiceAndSide.Num() != 2)
	{
		HandleInvalidRollInput(RollInput);
	}
	return FRoll{
		FCString::Atoi(*DiceAndSide[0]),
		FCString::Atoi(*DiceAndSide[1])
	};
}

int Roll(FString RollInput)
{
	FRoll rollInput = GetDiceAndSideCount(RollInput);
	if (IsInvalidDiceCount(rollInput.Dice) || IsInvalidSideCount(rollInput.Side))
	{
		HandleInvalidRollInput(RollInput);
	}

	int roll = 0;
	for (int i = 0; i < rollInput.Dice; ++i)
	{
		roll += RandomNonZeroNumber(rollInput.Side);
	}
	return roll;
}
