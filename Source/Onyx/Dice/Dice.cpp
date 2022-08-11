#include "Dice.h"

Dice::Dice(int i)
{
	Sides = i;
}

int Dice::Roll()
{
	return Sides;
}

FRollManyOutput Dice::RollMany(const FString Input)
{
	Dice d = Dice(0);
	d.RawInput = Input;
	d.SetRollInput();
	int RollSum = 0;
	TArray<int> Rolls;
	for (int i = 0; i < d.RollInput.DiceQty; ++i)
	{
		int Roll = d.GetRandomDiceSide();
		Rolls.Emplace(Roll);
		RollSum += Roll;
	}
	return FRollManyOutput{
		Rolls,
		RollSum
	};
}

bool Dice::IsInvalidDiceCount() const
{
	return RollInput.DiceQty <= 0;
}

bool Dice::IsInvalidSideCount() const
{
	return RollInput.SideQty <= 0;
}

void Dice::HandleInvalidRollInput() const
{
	throw FString("Roll " + RawInput + " is not valid.");
}

int Dice::GetRandomDiceSide() const
{
	srand(time(NULL));
	return rand() % RollInput.SideQty + 1;
}

void Dice::SetRollInput()
{
	TArray<FString> DiceAndSide;
	RawInput.ParseIntoArray(DiceAndSide, TEXT("d"), true);
	if (DiceAndSide.Num() != 2)
	{
		HandleInvalidRollInput();
	}
	RollInput = FRollManyInput{
		FCString::Atoi(*DiceAndSide[0]),
		FCString::Atoi(*DiceAndSide[1])
	};
	if (IsInvalidDiceCount() || IsInvalidSideCount())
	{
		HandleInvalidRollInput();
	}
}
