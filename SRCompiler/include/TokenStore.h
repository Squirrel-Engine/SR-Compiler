#pragma once
#include "TokenTypes.h"


class TokenStore
{
public:
	std::vector<TO_Enum> enumTokenList;

	void TokenStore::insertEnumToken(TO_Enum enumToken);
};

