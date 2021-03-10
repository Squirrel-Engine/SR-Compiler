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
        found = lexemesList.at(i).find("SR_COMPONENT()");
        if (found != std::string::npos)
        {
            token_store->insertComponentToken(generateComponentToken(lexemesList.at(i)));
        }

    }
}
// SR_ACTOR()class TestActor_1 : Squirrel::Actor{BODY()public:TestActor();//(int var1, int var2, int var3);void BeginPlay() override;void Update() override;SR_VAR_START()int var1 = 5;float var2 = 10;int var3 = 15;int var4 = 20;SR_VAR_END()Ammo ammoCrate {5, 2, 7, 100};AMMO_TYPE ammoType = AMMO_TYPE::HANDGUN;SR_COMP_START()Te
TO_Actor* HeaderAnalyser::generateActorToken(std::string lexemes)
{	
    TO_Actor* actorToken = new TO_Actor();

    // ========     //
	// Actor Name   //
	// ========     //
    int classKeyword = lexemes.find("class", 0) + 6;
    int colonKeyword = lexemes.find(":", 0);
    std::string actorName(&lexemes[classKeyword], &lexemes[colonKeyword]);
    actorToken->actorName = actorName;
	
    // ======== //
    // Variable 
    // ======== //
    int srVarStartKeywordIndex = lexemes.find("SR_VAR_START()", 0) + 14;
    int srVarEndKeywordIndex = lexemes.find("SR_VAR_END()", srVarStartKeywordIndex);
    int comaIndex = lexemes.find(";", srVarStartKeywordIndex);

    int currentIndex = srVarStartKeywordIndex;
    std::string variableStr(&lexemes[srVarStartKeywordIndex], &lexemes[srVarEndKeywordIndex]);


	/*
    deleteKeywords(variableStr, headerKeywords.intKeyword);
    deleteKeywords(variableStr, headerKeywords.floatKeyword);
    deleteKeywords(variableStr, headerKeywords.charKeyword);
    deleteKeywords(variableStr, headerKeywords.doubleKeyword);
    deleteKeywords(variableStr, headerKeywords.stringKeyword);
    //variableStr.replace(variableStr.find("int"), sizeof("int") - 1, "");
    variableStr.erase(std::remove_if(variableStr.begin(), variableStr.end(), isspace), variableStr.end());
    */
    size_t index = 0;
    while (true) {
        /* Locate the substring to replace. */
        index = variableStr.find(";", index);
        if (index == std::string::npos) break;

        /* Make the replacement. */
        variableStr.replace(index, 1, "\n");
        variableStr.insert(index + 1, "\t\t");
        /* Advance index forward so the next iteration doesn't pick it up as well. */
        index += 3;
    }
    int i = 0;
    int curentIndexx = 0;


	
    actorToken->variables = variableStr;


	
    // ======== //
    // Component
    // ======== //
    int srComponentStartKeywordIndex = lexemes.find("SR_COMP_START()", 0) + 15;
    int srComponentEndKeywordIndex = lexemes.find("SR_COMP_END()", srComponentStartKeywordIndex);
    comaIndex = lexemes.find(";", srComponentStartKeywordIndex);

    currentIndex = srComponentStartKeywordIndex;
    std::string componentString(&lexemes[srComponentStartKeywordIndex], &lexemes[srComponentEndKeywordIndex]);


    index = 0;
    while (true) {
        /* Locate the substring to replace. */
        index = componentString.find(";", index);
        if (index == std::string::npos) break;

        /* Make the replacement. */
        componentString.replace(index, 1, "\n");
        componentString.insert(index + 1, "\t\t");
        /* Advance index forward so the next iteration doesn't pick it up as well. */
        index += 3;
    }

    actorToken->components = componentString;
    return actorToken;
}

TO_Component* HeaderAnalyser::generateComponentToken(std::string lexemes)
{
    TO_Component* componentToken = new TO_Component();

    // ========         //
	// Component Name   //
	// ========         //
    int classKeyword = lexemes.find("class", 0) + 6;
    int colonKeyword = lexemes.find(":", 0);
    std::string componentName(&lexemes[classKeyword], &lexemes[colonKeyword]);
    componentToken->componentName = componentName;

    // ======== //
    // Variable 
    // ======== //
    int srVarStartKeywordIndex = lexemes.find("SR_VAR_START()", 0) + 14;
    int srVarEndKeywordIndex = lexemes.find("SR_VAR_END()", srVarStartKeywordIndex);
    int comaIndex = lexemes.find(";", srVarStartKeywordIndex);

    int currentIndex = srVarStartKeywordIndex;
    std::string variableStr(&lexemes[srVarStartKeywordIndex], &lexemes[srVarEndKeywordIndex]);


    /*
    deleteKeywords(variableStr, headerKeywords.intKeyword);
    deleteKeywords(variableStr, headerKeywords.floatKeyword);
    deleteKeywords(variableStr, headerKeywords.charKeyword);
    deleteKeywords(variableStr, headerKeywords.doubleKeyword);
    deleteKeywords(variableStr, headerKeywords.stringKeyword);
    //variableStr.replace(variableStr.find("int"), sizeof("int") - 1, "");
    variableStr.erase(std::remove_if(variableStr.begin(), variableStr.end(), isspace), variableStr.end());
    */
    size_t index = 0;
    while (true) {
        /* Locate the substring to replace. */
        index = variableStr.find(";", index);
        if (index == std::string::npos) break;

        /* Make the replacement. */
        variableStr.replace(index, 1, "\n");
        variableStr.insert(index + 1, "\t\t");
        /* Advance index forward so the next iteration doesn't pick it up as well. */
        index += 3;
    }
    int i = 0;
    int curentIndexx = 0;

    componentToken->variables = variableStr;


	
    return componentToken;
}



