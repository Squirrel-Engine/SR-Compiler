#pragma once
#include <string>

typedef struct MAP_COMPILER_DESC
{
	std::string test;
}MAP_COMPILER_DESC;


class MapCompiler
{
public:
	MapCompiler(MAP_COMPILER_DESC* mapCompilerDesc);
};


