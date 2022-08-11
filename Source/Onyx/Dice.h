#pragma once

struct FRollInput
{
	int Dice;
	int Side;
};

class Dice
{
public:
	int Roll(const FString Input);
private:
	FString RawInput;
	FRollInput RollInput;
	bool IsInvalidDiceCount() const;
	bool IsInvalidSideCount() const;
	void HandleInvalidRollInput() const;
	int GetRandomDiceSide() const;
	void SetRollInput();
};
