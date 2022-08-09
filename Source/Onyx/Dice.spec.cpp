#include "Misc/AutomationTest.h"
#include <Onyx/Dice.h>

DEFINE_SPEC(DiceSpec, "Onyx.Dice", EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
void DiceSpec::Define()
{
	Describe("A valid roll", [this] ()
	{
		It("should return possible range", [this]()
		{
		  TestTrue("1", Roll("1d1") == 1);
		});
	});
	
	Describe("An invalid roll input", [this] ()
	{
		It("should return exception", [this] ()
		{
			FString invalidInput = "cd1";
			try
			{
			  Roll(invalidInput);
			} catch (FString error)
			{
				FString expectedError = "Roll " + invalidInput + " is not valid."; 
				TestEqual("Expected Error", error, expectedError);
			}
		});
	});
}
