#include "HeaderAnalyser.h"

#include <iostream>


void deleteKeywords(std::string& variable, std::string search)
{
    size_t index = 0;
    while (true) {
        /* Locate the substring to replace. */
        index = variable.find(search, index);
        if (index == std::string::npos) break;

        /* Make the replacement. */
        variable.replace(index, search.length(), "");

        /* Advance index forward so the next iteration doesn't pick it up as well. */
        index += 3;
    }


}



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
        int found = lexemesList.at(i).find("SR_ACTOR()");
        if (found != std::string::npos)
        {
            token_store->insertActorToken(generateActorToken(lexemesList.at(i)));
        }

    }
}
// SR_ACTOR()class TestActor_1 : Squirrel::Actor{BODY()public:TestActor();//(int var1, int var2, int var3);void BeginPlay() override;void Update() override;SR_VAR_START()int var1 = 5;float var2 = 10;int var3 = 15;int var4 = 20;SR_VAR_END()Ammo ammoCrate {5, 2, 7, 100};AMMO_TYPE ammoType = AMMO_TYPE::HANDGUN;SR_COMP_START()Te
TO_Actor* HeaderAnalyser::generateActorToken(std::string lexemes)
{
/*
                   Sinsirella
  __________**___________________**__________
  _____________________^^____________________
  ___________________------__________________
		   I WILL USE FILE OPERATIONS
            YOU CANNOT REFACTOR ME!!
*/




	
    TO_Actor* actorToken = new TO_Actor();
    // Variables
    int srVarStartKeywordIndex = lexemes.find("SR_VAR_START()", 0) + 14;
    int srVarEndKeywordIndex = lexemes.find("SR_VAR_END()", srVarStartKeywordIndex);
    int comaIndex = lexemes.find(";", srVarStartKeywordIndex);

    int currentIndex = srVarStartKeywordIndex;
    std::string variableStr(&lexemes[srVarStartKeywordIndex], &lexemes[srVarEndKeywordIndex]);


    deleteKeywords(variableStr, headerKeywords.intKeyword);
    deleteKeywords(variableStr, headerKeywords.floatKeyword);
    deleteKeywords(variableStr, headerKeywords.charKeyword);
    deleteKeywords(variableStr, headerKeywords.doubleKeyword);
    deleteKeywords(variableStr, headerKeywords.stringKeyword);
    //variableStr.replace(variableStr.find("int"), sizeof("int") - 1, "");
    variableStr.erase(std::remove_if(variableStr.begin(), variableStr.end(), isspace), variableStr.end());

    size_t index = 0;
    while (true) {
        /* Locate the substring to replace. */
        index = variableStr.find(";", index);
        if (index == std::string::npos) break;

        /* Make the replacement. */
        variableStr.replace(index, 1, "\n");

        /* Advance index forward so the next iteration doesn't pick it up as well. */
        index += 3;
    }
    int i = 0;
    int curentIndexx = 0;


    std::ofstream out("text.txt");
    out << variableStr;
    out.close();
    std::ifstream out2("text.txt");
    std::string line;
    while (std::getline(out2, line)) {
        actorToken->variables.push_back(line);
    }

    std::cout << actorToken->variables.at(2) << std::endl;






	
	/*
    while (true)
    {
	    if (curentIndexx > variableStr.length())
	    {
		    break;
	    }
        std::string stringBuffer(&variableStr[curentIndexx], variableStr.find("\n", curentIndexx));
        std::cout << "String Buffer: " << stringBuffer << "---\n";
        actorToken->variables.push_back(stringBuffer);
        curentIndexx = variableStr.find("\n", curentIndexx) + 1;
    	
        stringBuffer = "";
        i++;
    }
    */
    // Components
    return actorToken;
}



