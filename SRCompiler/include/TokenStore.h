#pragma once
#include "TokenTypes.h"


class TokenStore
{
public:
	std::vector<TO_Actor*> actorTokenList;
	std::vector<TO_Component*> componentTokenList;


	

	void TokenStore::insertActorToken(TO_Actor* actorToken);
	void TokenStore::insertComponentToken(TO_Component* componentToken);
};

