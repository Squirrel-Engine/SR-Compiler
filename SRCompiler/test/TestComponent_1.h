#pragma once
SR_COMPONENT()
class TestComponent_1 : Squirrel::ActorComponent
{
public:
	TestComponent_1();
	void BeginPlay() override;
	void Update() override;
	
	SR_VAR_START()
		int health;
		int isAlive;
		Ammo ammoBox = {10,10,10,100};
	SR_VAR_END()
};
SR_COMPONENT()