#include <Onyx/Dice.h>
#include <Onyx/FDice.h>

DEFINE_SPEC(DiceSpec, "Onyx.Dice", EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
void DiceSpec::Define()
{
	Describe("Roll('1d1')", [this] ()
	{
		It("should roll 1", [this]()
		{
		  TestTrue("1", Roll("1d1") == 20);
		});
	});
}
