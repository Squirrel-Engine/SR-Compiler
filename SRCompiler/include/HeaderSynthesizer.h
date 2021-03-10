#pragma once

#include <fstream>
#include <string>

#include "TokenStore.h"

class HeaderSynthesizer
{
public:
	HeaderSynthesizer(TokenStore* _token_store);


	TokenStore* tokenStore;
	void synthResource();
};

