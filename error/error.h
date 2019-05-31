//
// Created by Zhuo Chen on 2019-05-29.
//

#ifndef DM_ERROR_H
#define DM_ERROR_H

#include <string>

class Error: public std::exception
{
private:
	int code;
	std::string message;
public:
	Error(int, const std::string &);
	~Error();

	void diagnose();
};

#endif //DM_ERROR_H
