SR_ENUM()
enum class AMMO_TYPE{
    HANDGUN,RIFLE
};
SR_ENUM()

SR_ENUM()
enum class AMMO_TYPE2{
    HANDGUN2,RIFLE2
};
SR_ENUM()


SR_STRUCT()
struct Ammo{
    int handgunAmmo=0;
    AMMO_TYPE rifleAmmo=AMMO_TYPE::HANDGUN;
    float sniperAmmo=2;
    int machinegunAmmo=sniperAmmo*2;
};
SR_STRUCT()


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
		int var2 = 10;
		int var3 = 15;
		int var4 = 20;
		Ammo ammoCrate {5, 2, 7, 100};
		AMMO_TYPE ammoType = AMMO_TYPE::HANDGUN;
	SR_VAR_END()

	SR_COMP_START()
		TestComponent_1* testComponent;
	SR_COMP_END()

private:
	
};
SR_ACTOR()