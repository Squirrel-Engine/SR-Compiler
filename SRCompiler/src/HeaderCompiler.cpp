#include "HeaderCompiler.h"

#include <iostream>

HeaderCompiler::HeaderCompiler(HEADER_COMPILER_DESC* headerCompilerDesc)
{
	preProcessor = new PreProcessor(headerCompilerDesc->path);
	preProcessor->defragmentHeaderFiles();
	preProcessor->splitHeaderFile();
}
