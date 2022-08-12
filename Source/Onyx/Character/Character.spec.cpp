#include <Onyx/Character/Character.h>
DEFINE_SPEC(FCharacterSpec, "Onyx.Character", EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)

void FCharacterSpec::Define()
{
	Describe("Leveling", [this]
	{
		It("Has Level", [this]
		{
			Character c = Character("Human", "Bard");
			TestTrue("1", c.GetLevel() == 1);
		});
	});
}
