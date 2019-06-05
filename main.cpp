#include "compiler/compiler.hpp"
#include "api/api.hpp"

#include <iostream>

int main(int argc, char const *argv[])
{
	std::cout << "Welcome to DM SQL Sever" << std::endl;
	std::cout << "***********************" << std::endl;
	API * api = new API;
	Compiler drv(api);
	do
	{
		drv.parse();
	} while (!drv.quit());

	delete api;
	
	return 0;
}
