#include "common.hpp"

#include <string>

size_t ExpressionList::size(void) const
{
	return this->list.size();
}

void ExpressionList::push_back(Expression * e)
{
	this->list.push_back(e);
}

Expression * ExpressionList::operator[](int index) const
{
	return this->list[index];
}

void ExpressionList::clear(void)
{
	this->list.clear();
}

ExpressionList::~ExpressionList(void)
{
	delete_ptr_in_vector(this->list);
}

std::ostream& operator<<(std::ostream & output, DMType & v)
{
	size_t type = v.index();
	switch (type) {
		case 0:
			output << v.to_int();
			break;
		case 1:
			output << v.to_double();
			break;
		case 2:
			output << v.to_char();
			break;
		case 3:
			output << v.to_string();
			break;
		case 4:
			output << v.to_expression_list();
			break;
	}
	return output;
}

const void * DMType_to_void_pointer(_DMType v)
{
    size_t type = v.index();
    switch (type) {
        case 0:
            return (void*)&(std::get<int>(v));
        case 1:
            return (void*)&(std::get<double>(v));
        case 2:
            return (void*)&(std::get<char>(v));
        case 3:
            return (void*)(std::get<std::string>(v).c_str());
        case 4:
            return nullptr;
    }
	return nullptr;
}

_DMType void_pointer_to_DMType(const void * p, AttrType a)
{
	switch (a) {
		case -1:
			return *(int*)p;
		case -2:
			return *(double*)p;
		default:
			return std::string((char*)p);
	}
}

std::string DMType_to_string(_DMType v)
{
	std::string ret;
	size_t type = v.index();
	switch (type) {
		case 0:
			ret = std::to_string(std::get<int>(v));
			break;
		case 1:
			ret = std::to_string(std::get<double>(v));
			break;
		case 2:
			ret = std::to_string(std::get<char>(v));
			break;
		case 3:
			ret = std::get<std::string>(v);
			break;
		default:
			break;
	}
	return ret;
}

const int attrTypeLength(AttrType a)
{
	switch (a) {
		case -1:
			return 4;
		case -2:
			return 8;
		default:
			return a;
	}
}

const bool type_match(AttrType a, _DMType d)
{
	bool _int = a == -1 && d.index() == 0;
	bool _double = a == -2 && d.index() == 1;
	bool _string = a > 0 && d.index() == 3;
	return _int || _double || _string;
}

const bool type_match(_DMType d, AttrType a)
{
	return type_match(a, d);
}