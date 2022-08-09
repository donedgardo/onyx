#include "Dice.h"

int Roll(FString n)
{
	int dice_count = n[0] - '0';
	if(dice_count <= 0 || dice_count >= 10)
	{
		FString errMsg = "Roll cd1 is not valid.";
		throw(errMsg);
	}
	return dice_count;
}
