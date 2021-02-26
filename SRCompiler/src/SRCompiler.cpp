// SRCompiler.cpp : Defines the entry point for the application.
//

#include "SRCompiler.h"
#include <iostream> 
#include "ECompilerMode.h"
#include "HeaderCompiler.h"
#include "MapCompiler.h"
using namespace std;

struct MyException : public exception {
    const char* what() const throw () {
        return "Test Exception";
    }
};


int main(int argc, char** argv)
{
    // Argument Pass
    HEADER_COMPILER_DESC hd = {};
    MAP_COMPILER_DESC md = {};
    ECompilerMode eCompilerMode = ECompilerMode::NONE;
    std::string path(argv[1]);

	for (int i = 2; i <= argc-1; i ++)
	{
        if (strcmp(argv[i], "-MC") == 0)
        {
            eCompilerMode = ECompilerMode::MAP_COMPILER;
            std::cout << "MC";
        }
        else if (strcmp(argv[i], "-HC") == 0)
        {
            eCompilerMode = ECompilerMode::HEADER_COMPILER;
            std::cout << "HC";
        }
	}
    std::cout << "Path: " << path;
	
	// Compiler Objects
    HeaderCompiler* headerCompiler = new HeaderCompiler(&hd);
    MapCompiler* mapCompiler = new MapCompiler(&md);

	
	// Switch
    switch (eCompilerMode)
    {
    case ECompilerMode::NONE:
        break;
    case ECompilerMode::HEADER_COMPILER:
	    try{
            throw MyException();
	    }
        catch (MyException& e) {
            std::cout << "MyException caught" << std::endl;
            std::cout << e.what() << std::endl;
        }
        break;
    case ECompilerMode::MAP_COMPILER:
        try {
            // CODE HERE!! 
        }
        catch (const char* msg) {
            cerr << msg << endl;
        }
        break;
         
    }


}