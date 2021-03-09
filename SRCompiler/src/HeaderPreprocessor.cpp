#include "HeaderPreprocessor.h"

#include <vector>


void eraseCharacterLine(std::string path, char eraseCharacter) {
    std::string line;
    std::ifstream fin;

    fin.open(path);

    std::ofstream temp;
    temp.open("temp.txt");

    while (getline(fin, line)) {
        // write all lines to temp other than the line marked for erasing
    	if(line[0] != eraseCharacter)
    	{
            temp << line << std::endl;
    	}
    	 
    }

    temp.close();
    fin.close();

    // required conversion for remove and rename functions
    const char* p = path.c_str();
    remove(p);
    rename("temp.txt", p);
}

void removeSpaces(std::string& str)
{
    int n = str.length();

    // i points to next position to be filled in output string j points to next character in the original string
    int i = 0;
	int j = -1;

    bool spaceFound = false;

    // Handles leading spaces
    while (++j < n && str[j] == ' ');

    // read all characters of original string
    while (j < n)
    {
        // if current characters is non-space
        if (str[j] != ' ')
        {
            // remove preceding spaces before dot, comma & question mark
            if ((str[j] == '.' ||
                str[j] == ',' ||
                str[j] == '?') && i - 1 >= 0 && str[i - 1] == ' ') {
                str[i - 1] = str[j++];
            }
            else {
                // copy current character at index i and increment both i and j
                str[i++] = str[j++];
            }
            // set space flag to false when any non-space character is found
            spaceFound = false;
        }
        // if current character is a space
        else if (str[j++] == ' ')
        {
            // If space is encountered for the first time after a word, put one space in the output and set space flag to true
            if (!spaceFound)
            {
                str[i++] = ' ';
                spaceFound = true;
            }
        }
    }
	
    // Remove trailing spaces
    if (i <= 1) {
        str.erase(str.begin() + i, str.end());
    }
    else {
        str.erase(str.begin() + i - 1, str.end());
    }
}

HeaderPreprocessor::HeaderPreprocessor(std::string _headerFolderPath)
{
    headerFolderPath = _headerFolderPath;
}


void HeaderPreprocessor::defragmentHeaderFiles()
{

	
    std::ifstream bufferFile;
    std::ofstream outputFile;
	
    std::vector<std::string> headerPathList;
    for (const auto& entry : std::filesystem::directory_iterator(headerFolderPath))
    {
        headerPathList.push_back(std::string{ entry.path().u8string()});
    	
    }

    if (outputFile.good() == true)
    {
        outputFile.open("Output.txt");
    }else
    {
        outputFile.open("Output.txt", std::ios::app);
    }
    outputFile.clear();
	
    for(int i = 0; i < headerPathList.size(); i++)
    {
        std::cout << headerPathList.at(i) << std::endl;
        bufferFile.open(headerPathList.at(i));
        outputFile << bufferFile.rdbuf() << "\n";
        bufferFile.close();
        bufferFile.clear();
    }
    outputFile.close();

	// Delete includes and compiler directives
    eraseCharacterLine("Output.txt", '#');
	
}

void HeaderPreprocessor::splitHeaderFile()
{
    std::ifstream t("Output.txt");
    std::string str((std::istreambuf_iterator<char>(t)),
        std::istreambuf_iterator<char>());

	// Remove Tab 
    str.erase(std::remove(str.begin(), str.end(), '\t'), str.end());

	// Remove New Lines
    str.erase(std::remove(str.begin(), str.end(), '\n'), str.end());


	// Macro Keywords
    std::string actorLabel = "SR_ACTOR()";
    std::string componentLabel = "SR_COMPONENT()";

	// Constructor of the line by line structure
    typeLiner(actorLabel, str);
    typeLiner(componentLabel, str);
	
	// Remove Whitespaces
	removeSpaces(str);

	// Write string into file
    std::ofstream out("Output.txt");
    out << str;
    out.close();

}

void HeaderPreprocessor::typeLiner(std::string macroKeyword, std::string &sourceText)
{
    std::vector<int> indexArray; // All Encountered Indices 
    
    size_t found = sourceText.find(macroKeyword.c_str()); 	// First Encounter with Macro Keyword

    indexArray.push_back(found);
	
    int firstIndex = found;
    int searchIndex = 1;
    while (true)
    {
    	if(found == 0) // If first encounter with keyword is at zero, this scope should run for that special case
    	{
            searchIndex++;
            firstIndex = sourceText.find(macroKeyword, found + searchIndex);
            found = sourceText.find(macroKeyword, found + searchIndex);
            indexArray.push_back(found);
            continue;
    		
    	}
        found = sourceText.find(macroKeyword, found + searchIndex);
        indexArray.push_back(found);
        if (firstIndex == indexArray.at(searchIndex))
        {
            indexArray.pop_back();
            break;
        }
        searchIndex++;
    }

    for (int i = 0; i < indexArray.size(); i++)
    {
    	// Only put newline to odd encounters, otherwise it duplicates new line
    	if (i % 2 == 0)
	    {
	    	continue;
	    }
    	else
	    {
            sourceText.insert((sourceText.find(macroKeyword, indexArray.at(i)) + macroKeyword.length()), "\n");
	    }
    }

}