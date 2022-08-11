#include "Dice.h"

int Dice::Roll(const FString Input)
{
	RawInput = Input;
	SetRollInput();
	int RollAmount = 0;
	for (int i = 0; i < RollInput.Dice; ++i)
	{
		RollAmount += GetRandomDiceSide();
	}
	return RollAmount;
}

bool Dice::IsInvalidDiceCount() const
{
	return RollInput.Dice <= 0;
}

bool Dice::IsInvalidSideCount() const
{
	return RollInput.Side <= 0;
}

void Dice::HandleInvalidRollInput() const
{
	throw FString("Roll " + RawInput + " is not valid.");
}

int Dice::GetRandomDiceSide() const
{
	srand(time(NULL));
	return rand() % RollInput.Side + 1;
}

void Dice::SetRollInput()
{
	TArray<FString> DiceAndSide;
	RawInput.ParseIntoArray(DiceAndSide, TEXT("d"), true);
	if (DiceAndSide.Num() != 2)
	{
		HandleInvalidRollInput();
	}
	RollInput = FRollInput{
		FCString::Atoi(*DiceAndSide[0]),
		FCString::Atoi(*DiceAndSide[1])
	};
	if (IsInvalidDiceCount() || IsInvalidSideCount())
	{
		HandleInvalidRollInput();
	}
}
