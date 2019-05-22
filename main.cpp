#include "compiler/compiler.hpp"

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
		res = drv.parse();
	} while (res != -1);

	delete api;
	
	return 0;
}