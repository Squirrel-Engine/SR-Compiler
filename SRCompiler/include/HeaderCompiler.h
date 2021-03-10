#pragma once
#include <string>


#include "HeaderAnalyser.h"
#include "HeaderPreprocessor.h"
#include "HeaderSynthesizer.h"
#include "TokenStore.h"

typedef struct HEADER_COMPILER_DESC
{
	std::string path;
}HEADER_COMPILER_DESC;


class HeaderCompiler
{
public:
	int x = 0;
	HeaderCompiler(HEADER_COMPILER_DESC* headerCompilerDesc);
	void compile();
private:
	
	TokenStore* tokenStore;
	HeaderPreprocessor* headerPreprocesor;
	HeaderAnalyser* headerAnalyser;
	HeaderSynthesizer* headerSynthesizer;
};

