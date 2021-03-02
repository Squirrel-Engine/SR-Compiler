#pragma once
#include <filesystem>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

typedef std::vector<std::string> stringvec;
class PreProcessor
{
public:
	PreProcessor(std::string headerFolderPath);

	void defragmentHeaderFiles();
	void splitHeaderFile();
private:
	void typeLiner(std::string typeName, std::string& sourceText);
	std::string headerFolderPath;
};

