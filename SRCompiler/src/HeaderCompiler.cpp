#include "HeaderCompiler.h"

#include <iostream>

HeaderCompiler::HeaderCompiler(HEADER_COMPILER_DESC* headerCompilerDesc)
{
	//Preprocessing
	preProcessor = new PreProcessor(headerCompilerDesc->path);
	preProcessor->defragmentHeaderFiles();
	preProcessor->splitHeaderFile();

	//
	tokenStore = new TokenStore();
	
	//Analysis
	headerAnalyser = new HeaderAnalyser(tokenStore);

	std::cout << "ENUM TOKEN: " << tokenStore->enumTokenList.at(0).values.at(1);

}
