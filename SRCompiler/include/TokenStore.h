#pragma once
#include "TokenTypes.h"


class TokenStore
{
public:
	std::vector<TO_Enum> enumTokenList;
	std::vector<TO_Struct> structTokenList;
	std::vector<TO_Actor> actorTokenList;
	std::vector<TO_Component> componentTokenList;


	
	void TokenStore::insertEnumToken(TO_Enum enumToken);
	void TokenStore::insertStructToken(TO_Struct structToken);
	void TokenStore::insertActorToken(TO_Actor actorToken);
	void TokenStore::insertComponentToken(TO_Component componentToken);
};

