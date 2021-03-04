#pragma once
#include <filesystem>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

typedef std::vector<std::string> stringvec;
class HeaderPreprocessor
{
public:
	HeaderPreprocessor(std::string headerFolderPath);

	void defragmentHeaderFiles();
	void splitHeaderFile();
private:
	void typeLiner(std::string macroKeyword, std::string& sourceText);
	std::string headerFolderPath;
};

