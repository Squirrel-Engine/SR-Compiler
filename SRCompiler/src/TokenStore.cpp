#include "TokenStore.h"



// Insert new Actor Token
void TokenStore::insertActorToken(TO_Actor* actorToken)
{
	actorTokenList.push_back(actorToken);
}

// Insert new Component Token
void TokenStore::insertComponentToken(TO_Component* componentToken)
{
	componentTokenList.push_back(componentToken);
}

