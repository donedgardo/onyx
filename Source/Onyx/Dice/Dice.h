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
	Dice(int i);
	static FRollManyOutput RollMany(const FString Input);
	int Roll();
private:
	FString RawInput;
	FRollManyInput RollInput;
	int Sides;
	bool IsInvalidDiceCount() const;
	bool IsInvalidSideCount() const;
	void HandleInvalidRollInput() const;
	int GetRandomDiceSide() const;
	void SetRollInput();
};

