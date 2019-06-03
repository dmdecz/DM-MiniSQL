#include "compiler/compiler.hpp"
#include "api/api.hpp"

#include <iostream>

int main(int argc, char const *argv[])
{
	std::cout << "Welcome to DM SQL Sever" << std::endl;
	std::cout << "***********************" << std::endl;
	API * api = new API;
	Compiler drv(api);
	int res = 0;
//	int i = 0;
	do
	{
		res = drv.parse();
//		std::cout << drv.result << std::endl;
	} while (res != -1);

	delete api;
	
	return 0;
}
