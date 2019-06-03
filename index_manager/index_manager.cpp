//
// Created by Zhuo Chen on 2019-06-01.
//

#include "index_manager.hpp"
#include "../record_manager/record_manager.hpp"
#include "../error/error.h"

#include <cstring>

int Node::NODE_HEAD_SIZE = sizeof(bool) * 2 + sizeof(int);

Node::Node(bool _leaf, Node * _parent, int _index)
	: valid(true), leaf(_leaf), parent(_parent), index(_index) {}

Node::Node(Block * block, AttrType key_type, Node * _parent, int _index)
	: parent(_parent), index(_index)
{
	this->load(block, key_type);
}


void Node::load(Block * block, AttrType key_type)
{
	int key_length = attrTypeLength(key_type);
	int p = 0;
	this->valid = *(bool*)block->get_data(p);
	p += sizeof(bool);

	if (this->valid) {
		this->leaf = *(bool*)block->get_data(p);
		p += sizeof(bool);
		int number = *(int*)block->get_data(p);
		p += sizeof(int);
		for (int i = 0; i < number; ++i) {
			DMType data = void_pointer_to_DMType(block->get_data(p), key_type);
//			std::cout << "load " << data << std::endl;
			this->key.push_back(data);
			p += key_length;
		}
		for (int i = 0; i < number + 1; ++i) {
			this->pointer.push_back(*(int*)block->get_data(p));
			p += 4;
		}
	}
}

bool Node::is_full(int degree)
{
	return this->key.size() > (degree - 1);
}

bool Node::is_half(int degree)
{
	return this->key.size() >= (degree - 1)/2;
}

void Node::write_back_to_block(Block * block, AttrType key_type)
{
	int key_length = attrTypeLength(key_type);
	int p = 0;
	block->datacpy(p, &this->valid, sizeof(bool));
	p += sizeof(bool);
	block->datacpy(p, &this->leaf, sizeof(bool));
	p += sizeof(bool);
	int number = this->key.size();
	block->datacpy(p, &number, sizeof(int));
	p += sizeof(int);
	for (auto & it : this->key) {
//		std::cout << "write " << it << std::endl;
		block->datacpy(p, DMType_to_void_pointer(it), sizeof(char) * key_length);
		p += key_length;
	}
	for (auto & it : this->pointer) {
		block->datacpy(p, &it, sizeof(int));
		p += sizeof(int);
	}
	block->zero(p);
}


BPlusTree::BPlusTree(Catalog_Manager * catalog_manager, Buffer_Manager * buffer_manager, const std::string & _table_name, AttrType _key_type)
		: m_catalog(catalog_manager), m_buffer(buffer_manager), table_name(_table_name), key_type(_key_type)
{
	int key_length = attrTypeLength(this->key_type);
	this->degree = (Block::BLOCK_SIZE - Node::NODE_HEAD_SIZE + key_length) / (key_length + sizeof(int));
//	std::cout << "key_length " << key_length << std::endl;
//	std::cout << "degree " << this->degree << std::endl;
	this->entry = this->allocate_block();
	Node root(true, nullptr, 0);
	root.write_back_to_block(this->get_block(this->entry), this->key_type);
}

BPlusTree::BPlusTree(Catalog_Manager * catalog_manager, Buffer_Manager * buffer_manager, const std::string & _table_name, int _entry, AttrType _key_type)
	: m_catalog(catalog_manager), m_buffer(buffer_manager), table_name(_table_name), entry(_entry), key_type(_key_type)
{
	int key_length = attrTypeLength(this->key_type);
	this->degree = (Block::BLOCK_SIZE - Node::NODE_HEAD_SIZE + key_length) / (key_length + sizeof(int));
}

Block * BPlusTree::get_block(int block_number)
{
	return this->m_buffer->get_block(this->table_name, block_number);
}

int BPlusTree::allocate_block()
{
	int ret = 0;
	int index_fragment = this->m_catalog->get_index_fragment(this->table_name);
	if (index_fragment < 0) {
		ret = index_fragment;
	} else {
		ret = -(this->m_catalog->index_block_number(this->table_name) + 1);
		this->m_buffer->create_block(this->table_name, ret);
		this->m_catalog->add_index_block(this->table_name);
	}
	return ret;
}

int BPlusTree::insert_key(DMType & key, int position)
{
	Block * root_block = this->get_block(this->entry);
	Node * root = new Node(root_block, this->key_type);
	this->insert_key(root, key, position);
	root->write_back_to_block(root_block, this->key_type);
	delete root;
}

int BPlusTree::insert_key(Node * node, DMType & key, int position)
{
//	std::cout << "insert " << key << std::endl;
	int index = 0;
	for (auto & it : node->key) {
//		std::cout << "key[" << index << "] = " << it << std::endl;
		if (key > it) {
			index ++;
		}
	}
//	std::cout << node->key.size() << std::endl;
//	std::cout << index << std::endl;
	if (node->leaf) {
		node->key.insert(node->key.begin() + index, key);
//		std::cout << "inserted " << node->key[index] << std::endl;
		node->pointer.insert(node->pointer.begin() + index, position);
	} else {
		int child_block_number = node->pointer[index];
//		std::cout << child_block_number << std::endl;
		Block * child_block = this->get_block(child_block_number);
		Node * child = new Node(child_block, this->key_type, node, index);
		this->insert_key(child, key, position);
		child->write_back_to_block(child_block, this->key_type);
		delete child;
	}
	if (node->is_full(this->degree)) {
//		std::cout << "split" << std::endl;
		this->fix_insert(node);
	}
}

void BPlusTree::fix_insert(Node * node)
{
	int right = this->degree / 2;
	int left = this->degree - right;
	bool change_root = false;

	if (!node->parent) {
//		std::cout << "split root" << std::endl;
		int old_entry = this->entry;
		this->entry = this->allocate_block();
		Block *new_root_block = this->get_block(this->entry);
		Node *new_root = new Node(false);
		new_root->pointer.insert(new_root->pointer.begin(), old_entry);
		node->parent = new_root;
		node->index = 0;
		change_root = true;
	}

	int new_block_number = this->allocate_block();
	Block *new_block = this->get_block(new_block_number);
	Node *new_node = new Node(node->leaf, node->parent, node->index + 1);

	if (node->leaf) {
		for (int i = 0; i < right; ++i) {
			new_node->key.push_back(node->key[i + left]);
			new_node->pointer.push_back(node->pointer[i + left]);
		}
		node->key.erase(node->key.begin() + left, node->key.end());
		node->pointer.erase(node->pointer.begin() + left, node->pointer.end());
		node->pointer.push_back(new_block_number);
		node->parent->key.insert(node->parent->key.begin() + node->index, new_node->key[0]);
		node->parent->pointer.insert(node->parent->pointer.begin() + new_node->index, new_block_number);
//		std::cout << "new root" << std::endl;
//		for (auto & it : node->parent->key) {
//			std::cout << it << '\t';
//		}
//		std::cout << std::endl;
//		std::cout << "left" << std::endl;
//		for (auto & it : node->key) {
//			std::cout << it << '\t';
//		}
//		std::cout << std::endl;
//		std::cout << "right" << std::endl;
//		for (auto & it : new_node->key) {
//			std::cout << it << '\t';
//		}
	} else {
		int pivot = right;
//		std::cout << "pivot " << pivot << std::endl;
		for (int i = pivot + 1; i < this->degree; ++i) {
//			std::cout << "move " << node->key[i] << std::endl;
			new_node->key.push_back(node->key[i]);
			new_node->pointer.push_back(node->pointer[i]);
		}
		new_node->pointer.push_back(node->pointer[this->degree]);

		node->parent->key.insert(node->parent->key.begin() + node->index, node->key[pivot]);
		node->parent->pointer.insert(node->parent->pointer.begin() + new_node->index, new_block_number);

		node->key.erase(node->key.begin() + pivot, node->key.end());
		node->pointer.erase(node->pointer.begin() + pivot + 1, node->pointer.end());
	}

	new_node->write_back_to_block(new_block, this->key_type);
	delete new_node;

	if (change_root) {
		node->parent->write_back_to_block(this->get_block(this->entry), this->key_type);
		delete node->parent;
	}

}


Index_Manager::Index_Manager(const std::string &_database_name, Catalog_Manager *catalog_manager, Buffer_Manager *buffer_manager)
	: database_name(_database_name), m_catalog(catalog_manager), m_buffer(buffer_manager) {}

Index_Manager::~Index_Manager() = default;

void Index_Manager::create_index(const std::string & table_name, const std::string & key_name)
{
//	int block_number = this->m_catalog->data_block_number(table_name);
//	int record_length = this->m_catalog->get_record_length(table_name);
	AttrInfo & attribute_list = this->m_catalog->get_attributes(table_name);
	AttrType key_type = attribute_list[key_name].first;

	BPlusTree * tree = new BPlusTree(this->m_catalog, this->m_buffer, table_name, key_type);

//	Record * tuple = new Record(attribute_list);
//	for (int i = 0; i < block_number; ++i) {
//		Block * block = this->m_buffer->get_block(table_name, i);
//		int begin = Block::BLOCK_HEAD_SIZE;
//		int end = *(int*)block->get_data(0);
//		int record_number = (end - begin) / record_length;
//		for (int j = 0; j < record_number; ++j) {
//			tuple->get_value(block->get_data(begin));
//			if (tuple->is_valid()) {
//				tree->insert_key((*tuple)[key_name], i);
//			}
//		}
//	}
	this->m_catalog->create_index(table_name, key_name, BPLUSTREE, tree->entry);
	delete tree;

}

void Index_Manager::insert_record(const std::string & table_name, std::map<std::string, DMType> & keys, int block_number)
{
	AttrInfo & attribute_list = this->m_catalog->get_attributes(table_name);
	IndexInfo & indices = this->m_catalog->get_index(table_name);
	for (auto & it : indices) {
		if (it.second.first == BPLUSTREE) {
			BPlusTree tree(this->m_catalog, this->m_buffer, table_name, it.second.second, attribute_list[it.first].first);
			tree.insert_key(keys[it.first], block_number);
			this->m_catalog->update_index_entry(table_name, it.first, tree.entry);
		}
	}
}