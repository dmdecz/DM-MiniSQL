#include "compilertools.hpp"

void f()
{
	Drop_Table_Statement * s = new Drop_Table_Statement("fasf");
	delete s;
}