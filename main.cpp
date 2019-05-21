#include "compiler/compiler.hpp"

#include <iostream>

int main(int argc, char const *argv[])
{
	std::cout << "Welcome to DM SQL Sever" << std::endl;
	std::cout << "***********************" << std::endl;
	Compiler drv;
	if (argc == 2)
		Compiler::file = std::string(argv[1]);
	int res = 0;
	int i = 0;
	do
	{
		res = drv.parse();
		// std::cout << res << std::endl;
	} while (res != -1);

	return 0;
}
