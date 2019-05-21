#if !defined(COMPILERTOOL_HPP)
#define COMPILERTOOL_HPP

#include <vector>
#include <string>

class Statement;
class Expression;
class ExpressionList;


typedef enum {SELECT_TYPE, CREATE_DB_TYPE} StatementType;

template<class T>
void delete_ptr_in_vector(std::vector<T *> & v)
{
	for (size_t i = 0; i < v.size(); i++)
		if (!v[i]) delete v[i];
}

class Statement
{
public:
	virtual ~Statement(void) {}
	virtual StatementType type(void) const = 0;
	virtual const ExpressionList * args(int) const = 0;
};

class Expression
{
public:
	virtual ~Expression(void) {}
};

class ExpressionList
{
private:
	std::vector<Expression *> list;
public:
	size_t size(void) const;
	void push_back(Expression *);
	Expression * operator[](int index) const;
	void clear(void);
	~ExpressionList(void);
};


#endif // COMPILERTOOL_HPP
