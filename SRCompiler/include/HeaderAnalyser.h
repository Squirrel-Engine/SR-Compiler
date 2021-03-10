#pragma once
#include <string>
#include <vector>
#include <filesystem>
#include <ostream>
#include <fstream>

#include "KeywordPool.h"
#include "TokenStore.h"
#include "TokenTypes.h"


class HeaderAnalyser
{
	
public:
	HeaderAnalyser(TokenStore* _token_store);
	std::vector<std::string> lexemesList;
	void commandListParser();
	TokenStore* token_store;
	void generateTokens();
	
	HeaderKeywords headerKeywords;

	TO_Actor* generateActorToken(std::string lexemes);
	TO_Component* generateComponentToken(std::string lexemes);
	
};

