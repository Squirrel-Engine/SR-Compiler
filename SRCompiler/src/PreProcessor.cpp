#include "PreProcessor.h"

#include <vector>

PreProcessor::PreProcessor(std::string _headerFolderPath)
{
    headerFolderPath = _headerFolderPath;
}

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
    std::string en = "SR_ENUM()";
    std::ifstream t("Output.txt");
    std::string str((std::istreambuf_iterator<char>(t)),
        std::istreambuf_iterator<char>());
    str.erase(std::remove(str.begin(), str.end(), '\t'), str.end());
    str.erase(std::remove(str.begin(), str.end(), '\n'), str.end());

	
    // Sinsirella 
	//__________**___________________**__________\\
	//_____________________^^____________________\\
	//___________________------__________________\\
	
    //Enum
    int enumIndexBuffer = 0;
    int n = 0;
    std::vector<int> indexArray;
    size_t found = str.find(en);
    if (found != std::pmr::string::npos)
	    std::cout << "First occurrence is " << found << std::endl;
	
    indexArray.push_back(found);
    char arr[] = "SR_ENUM()";
    found = str.find(arr, found + 1);
    if (found != std::pmr::string::npos)
        std::cout << "Next occurrence is " << found << std::endl;

    indexArray.push_back(found);
	
    found = str.find(arr, found + 2);
    if (found != std::pmr::string::npos)
        std::cout << "Next occurrence is " << found << std::endl;

    indexArray.push_back(found);
	
    found = str.find(arr, found + 3);
    if (found != std::pmr::string::npos)
        std::cout << "Next occurrence is " << found << std::endl;

    indexArray.push_back(found);
	
    found = str.find(arr, found + 4);
    if (found != std::pmr::string::npos)
        std::cout << "Next occurrence is " << found << std::endl;
	
    indexArray.push_back(found);

    found = str.find(arr, found + 5);
    if (found != std::pmr::string::npos)
        std::cout << "Next occurrence is " << found << std::endl;

    indexArray.push_back(found);
	
	
    while (true)
    {

        str.insert((str.find(en, indexArray.at(0)) + 0), "\n");
        str.insert((str.find(en, indexArray.at(1)) + 9), "\n");
        str.insert((str.find(en, indexArray.at(2)) + 0), "\n");
        str.insert((str.find(en, indexArray.at(3)) + 9), "\n");
        str.insert((str.find(en, indexArray.at(4)) + 0), "\n");
        str.insert((str.find(en, indexArray.at(5)) + 9), "\n");
        break;

    }




    std::cout << str << std::endl;

}
