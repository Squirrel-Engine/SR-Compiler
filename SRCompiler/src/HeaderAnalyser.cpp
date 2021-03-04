#include "HeaderAnalyser.h"

#include <iostream>


HeaderAnalyser::HeaderAnalyser(TokenStore* _token_store)
{
    token_store = _token_store;
    commandListParser();
    generateTokens();
}

void HeaderAnalyser::commandListParser()
{
	std::ifstream outputFile;
    std::string line;
	outputFile.open("Output.txt");

    while (getline(outputFile, line)) {
        lexemesList.push_back(line);
    }
}

void HeaderAnalyser::generateTokens()
{
    for (int i = 0; i < lexemesList.size(); i++) {
        int found = lexemesList.at(i).find("SR_ENUM()");
        if(found != std::string::npos)
	    {
            token_store->insertEnumToken(generateEnumToken(lexemesList.at(i)));
	    }
    	
    }
}
//SR_ENUM()enum class AMMO_TYPE{ HANDGUN,RIFLE};SR_ENUM()
TO_Enum HeaderAnalyser::generateEnumToken(std::string lexemes)
{
    TO_Enum enumToken;

    int classKeywordIndex = lexemes.find("class", 0) + 6;
    int bracesOpenIndex = lexemes.find("{", classKeywordIndex);
    int bracesCloseIndex = lexemes.find("}", classKeywordIndex);

	// Enum Name Parser
    std::string enumName(&lexemes[classKeywordIndex], &lexemes[bracesOpenIndex]);
    enumName.erase(std::remove_if(enumName.begin(), enumName.end(), isspace), enumName.end());
    enumToken.headerName = enumName;

    // Enum Variables Parser
    std::string enumVars(&lexemes[bracesOpenIndex+1], &lexemes[bracesCloseIndex+1]);
    enumVars.erase(std::remove_if(enumVars.begin(), enumVars.end(), isspace), enumVars.end());
    std::cout << enumVars << std::endl;

    int currentIndex = 0;
    while (true)
    {
        int found = enumVars.find(",", currentIndex);
	    if (found != std::string::npos)
	    {
            std::string varBuffer(&enumVars[currentIndex], &enumVars[found]);
            enumToken.values.push_back(varBuffer);
            currentIndex = found + 1;
	    }
        found = enumVars.find("}", currentIndex);
        std::string varBuffer(&enumVars[currentIndex], &enumVars[found]);
        enumToken.values.push_back(varBuffer);
        break;
    }
    std::cout << enumToken.values.at(0)<< std::endl;
    return  enumToken;
}
