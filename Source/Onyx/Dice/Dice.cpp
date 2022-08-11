#include "Dice.h"

Dice::Dice(const int SideQty)
{
	Sides = SideQty;
}

int Dice::Roll() const
{
	srand(time(nullptr));
	return rand() % Sides + 1;
}

FRollManyOutput Dice::RollMany(const FString RawInput)
{
	const auto [DiceQty, SideQty] = GetRollInput(RawInput);
	int RollSum = 0;
	TArray<int> Rolls;
	for (int i = 0; i < DiceQty; ++i)
	{
	    Dice d = Dice(SideQty);
		int Roll = d.Roll();
		Rolls.Emplace(Roll);
		RollSum += Roll;
	}
	return FRollManyOutput{
		Rolls,
		RollSum
	};
}

bool Dice::IsInvalidRollInput(FRollManyInput RollInput)
{
	return RollInput.DiceQty <= 0 || RollInput.SideQty <= 0;
}

void Dice::HandleInvalidRollInput(FString RawInput)
{
	throw FString("Roll " + RawInput + " is not valid.");
}

FRollManyInput Dice::GetRollInput(FString RawInput)
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
