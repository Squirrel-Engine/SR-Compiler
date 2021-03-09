#include "Ammo.h"
#include "EAmmo_Type.h"

SR_ACTOR()
class TestActor_1 : Squirrel::Actor
{
	BODY()

public:
	TestActor();
	//(int var1, int var2, int var3);
	void BeginPlay() override;
	void Update() override;
	
	SR_VAR_START()
		int var1 = 5;
		float var2 = 10;
		char var3 = 15;
		double var4 = 20;

	SR_VAR_END()

	
	Ammo ammoCrate {5, 2, 7, 100};
	AMMO_TYPE ammoType = AMMO_TYPE::HANDGUN;


	SR_COMP_START()
		TestComponent_1* testComponent;
	SR_COMP_END()

private:
	
};
SR_ACTOR()