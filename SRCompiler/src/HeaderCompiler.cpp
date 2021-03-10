#include "HeaderCompiler.h"

#include <iostream>

HeaderCompiler::HeaderCompiler(HEADER_COMPILER_DESC* headerCompilerDesc)
{
	headerPreprocesor = new HeaderPreprocessor(headerCompilerDesc->path);
}


void HeaderCompiler::compile()
{
	//Preprocessing
	headerPreprocesor->defragmentHeaderFiles();
	headerPreprocesor->splitHeaderFile();
	
	//Token Store
	tokenStore = new TokenStore();
	
	//Analysis
	headerAnalyser = new HeaderAnalyser(tokenStore);
	headerAnalyser->generateTokens();

	//Synthesis
	headerSynthesizer = new HeaderSynthesizer(tokenStore);
	headerSynthesizer->synthResource();
	std::cout << tokenStore->componentTokenList.at(1)->componentName;
}
