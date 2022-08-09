#include "Dice.h"

bool IsValidDiceCount(int dice_count)
{
	return dice_count <= 0 || dice_count >= 10;
}

void HandleInvalidDiceCount(int dice_count)
{
	if(IsValidDiceCount(dice_count))
	{
		throw(FString("Roll cd1 is not valid."));
	}
}

int Roll(FString n)
{
	const int Dice_Count = n[0] - '0';
	HandleInvalidDiceCount(Dice_Count);
	return Dice_Count;
}
