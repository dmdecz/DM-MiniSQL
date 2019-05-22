#if !defined(API_HPP)
#define API_HPP

#include "../compiler/compilertools/compilertool.hpp"

#include <vector>


class API
{
private:
	// static std::vector<>

public:
	API(void);
	void excute(Statement *);
	void excute_select(Statement *);
	void excute_table(Statement *);
	~API(void);
};


#endif // API_HPP
