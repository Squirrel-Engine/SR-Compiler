SR_ENUM()
enum class MEDICINE_TYPE{
    PAINKILLER
};
SR_ENUM()

SR_STRUCT()
struct Medicine{
    int med1=0;
    int med2=0;
};
SR_STRUCT()


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

		Medicine medStruct {5, 2};
	SR_VAR_END()

	SR_COMP_START()
		TestComponent_1* testComponent;
	SR_COMP_END()

private:
	
};
SR_ACTOR()