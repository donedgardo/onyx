#include "Dice.h"

#include <string>

bool IsInvalidDiceCount(const int DiceCount)
{
	return DiceCount <= 0 || DiceCount >= 10;
}

bool IsInvalidSideCount(const int SideCount)
{
	return SideCount <= 0 || SideCount >= 10;
}

void HandleInvalidDiceCount(FString input)
{
	throw FString("Roll " + input + " is not valid.");
}

int RandomNonZeroNumber(const int InclusiveMax)
{
	srand(time(NULL));
	return rand() % InclusiveMax + 1;
}

int Roll(FString RollInput)
{
	TArray<FString> DiceAndSide;
	RollInput.ParseIntoArray(DiceAndSide, TEXT("d"), true);
	if (DiceAndSide.Num() != 2)
	{
		HandleInvalidDiceCount(RollInput);
	}
	const int DiceCount = FCString::Atoi(*DiceAndSide[0]);
	const int SideCount = FCString::Atoi(*DiceAndSide[1]);
	if (IsInvalidDiceCount(DiceCount) || IsInvalidSideCount(SideCount))
	{
		HandleInvalidDiceCount(RollInput);
	}

	int roll = 0;
	for (int i = 0; i < DiceCount; ++i)
	{
		roll += RandomNonZeroNumber(SideCount);
	}
	return roll;
}
