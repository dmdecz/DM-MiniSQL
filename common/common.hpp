#if !defined(COMMON_HPP)
#define COMMON_HPP

#include <vector>
#include <map>
#include <string>
#include <variant>
#include <iostream>

class Statement;
class Expression;
class ExpressionList;

typedef enum {SELECT_TYPE, CREATE_TABLE_TYPE, DROP_TABLE_TYPE, USE_TYPE, CREATE_DB_TYPE, DROP_DB_TYPE,
			  INSERT_TYPE, QUIT_TYPE, DELETE_TYPE} StatementType;
typedef enum {BPLUSTREE, HASH} IndexType;

typedef std::variant<int, double, char, std::string, ExpressionList *> DMType;
std::ostream& operator<<(std::ostream & output, DMType & v);

typedef int AttrType;
const void * DMType_to_void_pointer(DMType);
DMType void_pointer_to_DMType(void *, AttrType);
const int attrTypeLength(AttrType);
const bool type_match(AttrType, DMType);
const bool type_match(DMType, AttrType);

template<class T>
void delete_ptr_in_vector(std::vector<T *> & v)
{
	for (size_t i = 0; i < v.size(); i++)
		if (v[i]) delete v[i];
	v.clear();
}

template<class A, class B>
using MapIterator = typename std::map<A, B>::iterator;

template<class T, class A>
void delete_ptr_in_map(std::map<A, T *> & m)
{
	for (MapIterator<A, T*> it = m.begin(); it != m.end(); it++)
		delete it->second;
	m.clear();
}

class Statement
{
public:
	virtual ~Statement(void) {}
	virtual StatementType type(void) const = 0;
	virtual DMType args(int op = 0) const = 0;
};

class Expression
{
public:
	virtual ~Expression(void) {}
	virtual DMType values(int op = 0) const = 0;
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


#endif // COMMON_HPP
