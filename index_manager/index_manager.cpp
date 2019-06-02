//
// Created by Zhuo Chen on 2019-06-01.
//

#include "index_manager.hpp"
#include "../record_manager/record_manager.hpp"
#include "../error/error.h"

int Node::NODE_HEAD_SIZE = sizeof(bool) + sizeof(int);

Node::Node(NodeType _type)
	: type(_type) {}

Node::Node(Block * block, AttrType key_type)
{
	this->load(block, key_type);
}


void Node::load(Block * block, AttrType key_type)
{
	int key_length = attrTypeLength(key_type);
	int p = 0;
	bool valid = *(bool*)block->get_data(p);
	p += sizeof(bool);

	if (valid) {
		int number = *(int*)block->get_data(p);
		for (int i = 0; i < number; ++i) {
			this->key.push_back(void_pointer_to_DMType(block->get_data(p), key_type));
			p += key_length;
		}
		for (int i = 0; i < number + 1; ++i) {
			this->pointer.push_back(*(int*)block->get_data(p));
			p += 4;
		}
	}
}

bool Node::is_valid(int degree)
{
	bool ret = this->is_half(degree) && this->is_full(degree);
	if (this->type == ROOT && this->key.size() == 0) {
		ret = false;
	} else if (this->type == ROOTLEAF) {
		ret = this->key.size() <= (degree - 1);
	}
	return ret;
}

bool Node::is_full(int degree)
{
	return this->key.size() <= (degree - 1);
}

bool Node::is_half(int degree)
{
	return this->key.size() >= (degree - 1)/2;
}

void Node::write_back_to_block(Block * block, AttrType key_type)
{
	int key_length = attrTypeLength(key_type);
	int number = this->key.size();
	block->datacpy(sizeof(bool), &number, sizeof(int));
	int p = sizeof(int);
	for (auto & it : this->key) {
		block->datacpy(p, DMType_to_void_pointer(it), sizeof(char) * key_length);
		p += key_length;
	}
	for (auto & it : this->pointer) {
		block->datacpy(p, &it, sizeof(int));
		p += sizeof(int);
	}
}

//int Node::insert_key(DMType key, int position_or_pointer_1, int position_or_pointer_2)
//{
//	int ret = 0;
//	if (!this->key.size()) {
//		this->key.push_back(key);
//		this->pointer.push_back(position_or_pointer_1);
//		this->pointer.push_back(position_or_pointer_2);
//	}
//	return ret;
//}

int Node::insert_key(DMType key, int position_or_pointer)
{
	int ret = 0;
	if (this->key.size()) {
		for (auto &it : this->key) {
			if (key < it) {
				ret++;
			} else if (key == it) {
				ret = 0;
				break;
//				throw Error(100, "Duplicated key value.");
			} else {
				this->key.insert(this->key.begin() + ret - 1, key);
				this->pointer.insert(this->pointer.begin() + ret, position_or_pointer);
				break;
			}
		}
	} else {
		ret = this->insert_key(key, position_or_pointer, 0);
	}
	return ret;
}

int Node::delete_key(DMType key)
{

}

int Node::search_key(DMType key)
{

}

BPlusTree::BPlusTree(Buffer_Manager * buffer_manager, const std::string & _table_name, int _entry, AttrType _key_type)
	: m_buffer(buffer_manager), table_name(_table_name), entry(_entry), key_type(_key_type)
{
	int key_length = attrTypeLength(this->key_type);
	this->degree = (Block::BLOCK_SIZE - Node::NODE_HEAD_SIZE + key_length) / (key_length + sizeof(int));
}

Block * BPlusTree::get_block(int block_number)
{
	return this->m_buffer->get_block(this->table_name, block_number);
}

int BPlusTree::insert_key(DMType key, int position)
{
	Node * root = nullptr;
	if (this->is_empty()) {
		entry = this->allocate_block();
		root = new Node(ROOTLEAF);
		insert_key(root, key, position);
	} else {
		Block * block = this->get_block(entry);
		root = new Node(block, this->key_type);
		insert_key(root, key, position);
		root->write_back_to_block(this->get_block(entry), this->key_type);
	}
}

int BPlusTree::search_key(DMType key)
{

}

int BPlusTree::delete_key(DMType key)
{

}

bool BPlusTree::is_empty()
{
	return this->entry == 0;
}

int BPlusTree::insert_key(Node * node, DMType key, int position)
{
	if (node->type == LEAF || node->type == ROOTLEAF) {
		node->insert_key(key, position);
	} else {
		int index = 0;
		for (auto & it : node->key) {
			if (key < it) {
				index ++;
			} else {
				break;
			}
		}
		Block * block = this->get_block(node->pointer[index]);
		Node * child = new Node(block, this->key_type);
		this->insert_key(child, key, position);
		child->write_back_to_block(this->get_block(node->pointer[index]), this->key_type);
	}
	if (node->)
}

int BPlusTree::search_key(Node * node, DMType key)
{

}

int BPlusTree::delete_key(Node * node, DMType key)
{

}

Index_Manager::Index_Manager(const std::string &_database_name, Catalog_Manager *catalog_manager, Buffer_Manager *buffer_manager)
	: database_name(_database_name), m_catalog(catalog_manager), m_buffer(buffer_manager) {}

Index_Manager::~Index_Manager() = default;

void Index_Manager::create_index(const std::string & table_name, const std::string & key_name)
{
	int block_number = this->m_catalog->data_block_number(table_name);
	int record_length = this->m_catalog->get_record_length(table_name);
	AttrInfo & attribute_list = this->m_catalog->get_attributes(table_name);
	AttrType key_type = attribute_list[key_name].first;

	BPlusTree * tree = new BPlusTree(this->m_buffer, table_name, 0, key_type);

	Record * tuple = new Record(attribute_list);
	for (int i = 0; i < block_number; ++i) {
		Block * block = this->m_buffer->get_block(table_name, i);
		int begin = Block::BLOCK_HEAD_SIZE;
		int end = *(int*)block->get_data(0);
		int record_number = (end - begin) / record_length;
		for (int j = 0; j < record_number; ++j) {
			tuple->get_value(block->get_data(begin));
			if (tuple->is_valid()) {
				tree->insert_key((*tuple)[key_name], i);
			}
		}
	}
	this->m_catalog->add_index(table_name, key_name, BPLUSTREE);
}