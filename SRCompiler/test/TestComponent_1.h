#include "Components";
#inclıde 	"test";


SR_COMPONENT()
class 	RenderComponent :   Squirrel::Actor
{
public:
	RenderComponent();
	void getMesh();

	SR_VAR_START()
			int meshID;
			char meshChar
			double dob
	SR_VAR_END()
	Mesh ammo;
	Texture we;
};
SR_COMPONENT()