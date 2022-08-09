#include "Dice.h"

bool IsValidDiceCount(const int dice_count)
{
	return dice_count <= 0 || dice_count >= 10;
}

void HandleInvalidDiceCount()
{
	throw FString("Roll cd1 is not valid.");
}

int Roll(FString n)
{
	const int DiceCount = n[0] - '0';
	if (IsValidDiceCount(DiceCount))
	{
		HandleInvalidDiceCount();
	}
	return DiceCount;
}
