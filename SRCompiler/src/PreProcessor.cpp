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
    int n = 1;
    while (true)
    {
        std::cout << "Index Buffer: " << enumIndexBuffer;
        std::cout << "STR Find: " << str.find(en, n);
        std::cout << "N: " << n;
        n = str.find(en, n) + 10;
        if (enumIndexBuffer == str.find(en, n))
        {
            break;
        }
    	

    	
        
        enumIndexBuffer = str.find(en, n);

        str.insert((str.find(en, n) + 9), "\n");

    }




    std::cout << str << std::endl;

}
