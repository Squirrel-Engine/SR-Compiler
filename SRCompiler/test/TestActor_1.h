#include "Ammo.h"
#include "EAmmo_Type.h"

SR_ACTOR()
class Skeleton : Squirrel::Actor
{
	BODY()
public:
	TestActor();
	//(int var1, int var2, int var3);
	void BeginPlay() override;
	void Update() override;
	
	SR_VAR_START()
	int weapon = 5;
	float health = 10;
	char attack = 15;
	double power = 20;
	SR_VAR_END()

	
	Ammo ammoCrate {5, 2, 7, 100};
	AMMO_TYPE ammoType = AMMO_TYPE::HANDGUN;


	SR_COMP_START()
			TransformComponent* transformComponent;
		RenderComponent* renderComponent;
	SR_COMP_END()


};
SR_ACTOR()