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
	FRollManyOutput RollWithAdvantage() const;
	FRollManyOutput RollWithDisadvantage() const;
	static FRollManyOutput RollMany(const FString RawInput);
private:
	int Sides;
	static FRollManyOutput GetRollManyOutput(FRollManyInput RollManyInput);
	static FRollManyInput GetRollManyInput(FString RawInput);
	static bool IsInvalidRollInput(FRollManyInput RollInput);
	static void HandleInvalidRollInput(FString RawInput);
	TArray<int> RollTwice() const;
};

