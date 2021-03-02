#include "PreProcessor.h"

#include <vector>

PreProcessor::PreProcessor(std::string _headerFolderPath)
{
    headerFolderPath = _headerFolderPath;
}

enum class test
{
	SR_ENUM,
	
};
void PreProcessor::defragmentHeaderFiles()
{
    std::vector<std::ifstream> files;
    std::ifstream bufferFile;
    std::ofstream outputFile;
	
    std::vector<std::string> headerNames;
    for (const auto& entry : std::filesystem::directory_iterator(headerFolderPath))
    {
        headerNames.push_back(std::string{ entry.path().u8string()});
    	
    }
    if (outputFile.good() == true)
    {
        outputFile.open("Output.txt");
    }else
    {
        outputFile.open("Output.txt", std::ios::app);
    }

    outputFile.clear();
    for(int i = 0; i < headerNames.size(); i++)
    {
        std::cout << headerNames.at(i) << std::endl;
        bufferFile.open(headerNames.at(i));
        outputFile << bufferFile.rdbuf() << "\n";
        bufferFile.close();
        bufferFile.clear();
    }
    outputFile.close();

	
}

void PreProcessor::splitHeaderFile()
{
    std::ifstream t("Output.txt");
    std::string str((std::istreambuf_iterator<char>(t)),
        std::istreambuf_iterator<char>());
    str.erase(std::remove(str.begin(), str.end(), '\t'), str.end());
    str.erase(std::remove(str.begin(), str.end(), '\n'), str.end());

	
    std::string enumLabel = "SR_ENUM()";
    std::string structLabel = "SR_STRUCT()";
    std::string actorLabel = "SR_ACTOR()";
    std::string componentLabel = "SR_COMPONENT()";

	
    typeLiner(enumLabel, str);
    typeLiner(structLabel, str);
    typeLiner(actorLabel, str);
    typeLiner(componentLabel, str);
    std::cout << str;

}

void PreProcessor::typeLiner(std::string typeName, std::string &sourceText)
{
    std::vector<int> indexArray;
	
    size_t found = sourceText.find(typeName.c_str());
	
    if (found != std::pmr::string::npos)
        std::cout << "First occurrence is " << found << std::endl;

    indexArray.push_back(found);
    int firstIndex = found;

	
    int searchIndex = 1;
    while (true)
    {
    	if(found == 0)
    	{
            searchIndex++;
            firstIndex = sourceText.find(typeName, found + searchIndex);
            found = sourceText.find(typeName, found + searchIndex);
            indexArray.push_back(found);
            continue;
    		
    	}
        found = sourceText.find(typeName, found + searchIndex);
        indexArray.push_back(found);
        if (firstIndex == indexArray.at(searchIndex))
        {
            indexArray.pop_back();
            break;
        }
        if (found != std::pmr::string::npos)
            std::cout << "Next occurrence is " << found << std::endl;
        searchIndex++;
    }

    for (int i = 0; i < indexArray.size(); i++)
    {
	    if (i % 2 == 0)
	    {
	    }else
	    {
            sourceText.insert((sourceText.find(typeName, indexArray.at(i)) + typeName.length()), "\n");
	    }
    }

	



}
