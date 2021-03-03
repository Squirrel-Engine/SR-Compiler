#include "PreProcessor.h"

#include <vector>


void eraseFileLine(std::string path, char eraseCharacter) {
    std::string line;
    std::ifstream fin;

    fin.open(path);
    // contents of path must be copied to a temp file then
    // renamed back to the path file
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
    // n is length of the original string
    int n = str.length();

    // i points to next position to be filled in
    // output string/ j points to next character
    // in the original string
    int i = 0, j = -1;

    // flag that sets to true is space is found
    bool spaceFound = false;

    // Handles leading spaces
    while (++j < n && str[j] == ' ');

    // read all characters of original string
    while (j < n)
    {
        // if current characters is non-space
        if (str[j] != ' ')
        {
            // remove preceding spaces before dot,
            // comma & question mark
            if ((str[j] == '.' ||
                str[j] == ',' ||
                str[j] == '?') && i - 1 >= 0 && str[i - 1] == ' ') {
                str[i - 1] = str[j++];
            }
            else {
                // copy current character at index i
                // and increment both i and j
                str[i++] = str[j++];
            }
            // set space flag to false when any
            // non-space character is found
            spaceFound = false;
        }
        // if current character is a space
        else if (str[j++] == ' ')
        {
            // If space is encountered for the first
            // time after a word, put one space in the
            // output and set space flag to true
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

	// Delete includes and compiler directives
    eraseFileLine("Output.txt", '#');
	
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
	

	
	removeSpaces(str);
    std::ofstream out("Output.txt");
    out << str;
    out.close();
	

}

void PreProcessor::typeLiner(std::string typeName, std::string &sourceText)
{
    std::vector<int> indexArray;
	
    size_t found = sourceText.find(typeName.c_str());
	
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
