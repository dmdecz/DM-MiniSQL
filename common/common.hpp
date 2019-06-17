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
			  INSERT_TYPE, QUIT_TYPE, DELETE_TYPE, CREATE_INDEX_TYPE, DROP_INDEX_TYPE, SHOW_TYPE,
				SOURCE_TYPE} StatementType;
typedef enum {BPLUSTREE, HASH} IndexType;

typedef std::variant<int, double, char, std::string, ExpressionList *> _DMType;

typedef int AttrType;
const void * DMType_to_void_pointer(_DMType);
_DMType void_pointer_to_DMType(const void *, AttrType);
std::string DMType_to_string(_DMType);
const int attrTypeLength(AttrType);
const bool type_match(AttrType, _DMType);
const bool type_match(_DMType, AttrType);

class DMType {
private:
	_DMType data;
public:
	DMType() {}
	DMType(const void * p, AttrType a) { data = ::void_pointer_to_DMType(p, a); }
	explicit DMType(const _DMType & d): data(d) {}

	explicit DMType(int d): data(d) {}
	explicit DMType(double d): data(d) {}
	explicit DMType(char d): data(d) {}
	explicit DMType(ExpressionList *d): data(d) {}
	explicit DMType(const std::string & d): data(d) {}

	DMType &operator=(int d) { data = d; return *this;}
	DMType &operator=(double d) { data = d; return *this;}
	DMType &operator=(char d) { data = d; return *this;}
	DMType &operator=(ExpressionList *d) { data = d; return *this;}
	DMType &operator=(const std::string & d) { data = d; return *this;}

	int to_int() { return std::get<int>(data); }
	double to_double() { return std::get<double>(data); }
	char to_char() { return std::get<char>(data); }
	std::string to_string() { return ::DMType_to_string(data); }
	ExpressionList * to_expression_list() { return std::get<ExpressionList*>(data); }
	const void * data_address();
	bool type_match(AttrType a) { return ::type_match(a, data); }

	bool operator==(DMType & d) const { return data == d.data; }
	bool operator<(DMType & d) const { return data < d.data; }
	bool operator>(DMType & d) const { return data > d.data; }
	bool operator<=(DMType & d) const { return data <= d.data; }
	bool operator>=(DMType & d) const { return data >= d.data; }
	bool operator!=(DMType & d) const { return data != d.data; }

	int index() { return data.index(); }
};

std::ostream& operator<<(std::ostream & output, DMType & v);

typedef std::map<std::string, std::pair<AttrType, int>> AttrInfo;
typedef enum {EQUAL, LESS, LARGE, NOT} CmpType;
typedef std::map<std::string, std::pair<int, DMType>> CmpInfo;
typedef std::map<std::string, std::pair<IndexType, int>> IndexInfo;

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
