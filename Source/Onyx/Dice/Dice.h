#pragma once

struct FRollManyInput
{
	int DiceQty;
	int SideQty;
};

struct FRollManyOutput
{
	TArray<int> Rolls;
	int Result;
	
};

class Dice
{
public:
	Dice(int SideQty);
	int Roll() const;
	static FRollManyOutput RollMany(const FString RawInput);
private:
	int Sides;
	static bool IsInvalidRollInput(FRollManyInput RollInput);
	static void HandleInvalidRollInput(FString RawInput);
	static FRollManyInput GetRollInput(FString RawInput);
};

