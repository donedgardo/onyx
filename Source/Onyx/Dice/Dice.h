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
	FString Error;
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
	static bool IsInvalidRollInput(FRollManyInput RollInput);
	static FString GetErrorMessage(FString RawInput);
	TArray<int> RollTwice() const;
};

