//
// Created by Zhuo Chen on 2019-05-29.
//

#include "error.h"

#include <iostream>

Error::Error(int c, const std::string & m)
	: code(c), message(m) {}

Error::~Error() {}

void Error::diagnose()
{
	std::cerr << "Error " << code << ":" << std::endl;
	std::cerr << message << std::endl << std::endl;
}