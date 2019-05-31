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
			output << std::get<int>(v);
			break;
		case 1:
			output << std::get<double>(v);
			break;
		case 2:
			output << std::get<char>(v);
			break;
		case 3:
			output << std::get<std::string>(v);
			break;
		case 4:
			output << std::get<ExpressionList *>(v);
			break;
	}
	return output;
}

const void * DMType_to_void_pointer(DMType v)
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

DMType void_pointer_to_DMType(void * p, AttrType a)
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

const bool type_match(AttrType a, DMType d)
{
	bool _int = a == -1 && d.index() == 0;
	bool _double = a == -2 && d.index() == 1;
	bool _string = a > 0 && d.index() == 3;
	return _int || _double || _string;
}

const bool type_match(DMType d, AttrType a)
{
	return type_match(a, d);
}