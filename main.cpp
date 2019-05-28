#include "compiler/compiler.hpp"
#include "api/api.hpp"

#include <iostream>

int main(int argc, char const *argv[])
{
	std::cout << "Welcome to DM SQL Sever" << std::endl;
	std::cout << "***********************" << std::endl;
	API * api = new API;
	Compiler drv(api);
	if (argc == 2)
		Compiler::file = std::string(argv[1]);
	int res = 0;
	int i = 0;
	do
	{
		drv.parse();
		// std::cout << drv.result << std::endl;
	} while (drv.result != -1);

	delete api;
	
	return 0;
}
