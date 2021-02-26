#pragma once
#include <string>

typedef struct HEADER_COMPILER_DESC
{
	std::string test;
}HEADER_COMPILER_DESC;


class HeaderCompiler
{
public:
	int x = 0;
	HeaderCompiler(HEADER_COMPILER_DESC* headerCompilerDesc);

};

