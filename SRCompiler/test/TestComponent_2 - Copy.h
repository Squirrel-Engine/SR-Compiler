#include "Components";
#inclıde 	"test";


SR_COMPONENT()
class MelisaComponent : Squirrel::Actor
{
public:
	TransformComponents();
	void calculateTest();

	SR_VAR_START()
	float x;
	float y;
	float z;
	SR_VAR_END()
	AmmoBox ammo;
	Medicine we;
};
SR_COMPONENT()
