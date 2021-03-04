#include "TokenStore.h"

// Insert new Enum Token
void TokenStore::insertEnumToken(TO_Enum enumToken)
{
	enumTokenList.push_back(enumToken);
}

// Insert new Struct Token
void TokenStore::insertStructToken(TO_Struct structToken)
{
	structTokenList.push_back(structToken);
}

// Insert new Actor Token
void TokenStore::insertActorToken(TO_Actor actorToken)
{
	actorTokenList.push_back(actorToken);
}

// Insert new Component Token
void TokenStore::insertComponentToken(TO_Component componentToken)
{
	componentTokenList.push_back(componentToken);
}

