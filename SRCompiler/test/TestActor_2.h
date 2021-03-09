#include "Medicine.h"

SR_ACTOR()
class TestActor_2 : Squirrel::Actor
{
	BODY()

public:
	TestActor();
	//(int var1, int var2, int var3);
	void BeginPlay() override;
	void Update() override;

	SR_VAR_START()
		int var12 = 5;
		int var45 = 10;
		int var32 = 5;
		int var65 = 10;

	SR_VAR_END()


	Medicine medStruct {5, 2};



	SR_COMP_START()
		TestComponent_1* testComponent;
	SR_COMP_END()

private:
	
};
SR_ACTOR()