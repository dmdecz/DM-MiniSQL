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
	if (this->parent) {
		if (this->leaf) {
			return this->key.size() < (degree - 1) / 2 + (degree - 1) % 2;
		} else {
			return this->pointer.size() < degree / 2 + degree % 2;
		}
	} else {
		return this->key.empty();
	}
}

bool Node::is_enough(int degree)
{
	if (this->leaf) {
		return this->key.size() > (degree - 1) / 2 + (degree - 1) % 2;
	} else {
		return this->pointer.size() > degree / 2 + degree % 2;
	}
}

void Node::drop()
{
	this->valid = false;
	this->key.clear();
	this->pointer.clear();
}

void Node::write_back_to_block(Block * block, AttrType key_type)
{
	int key_length = attrTypeLength(key_type);
	int p = 0;
	block->datacpy(p, &this->valid, sizeof(bool));
	p += sizeof(bool);
	if (this->valid) {
		block->datacpy(p, &this->leaf, sizeof(bool));
		p += sizeof(bool);
		int number = this->key.size();
		block->datacpy(p, &number, sizeof(int));
		p += sizeof(int);
		for (auto &it : this->key) {
			//		std::cout << "write " << it << std::endl;
			block->datacpy(p, DMType_to_void_pointer(it), sizeof(char) * key_length);
			p += key_length;
		}
		for (auto &it : this->pointer) {
			block->datacpy(p, &it, sizeof(int));
			p += sizeof(int);
		}
	}
	block->zero(p);
}


BPlusTree::BPlusTree(Catalog_Manager * catalog_manager, Buffer_Manager * buffer_manager, const std::string & _table_name, AttrType _key_type)
		: m_catalog(catalog_manager), m_buffer(buffer_manager), table_name(_table_name), key_type(_key_type)
{
	int key_length = attrTypeLength(this->key_type);
	this->degree = (Block::BLOCK_SIZE - Node::NODE_HEAD_SIZE + key_length) / (key_length + sizeof(int));
//	std::cout << "degree " << this->degree << std::endl;
	this->entry = this->allocate_block();
//	std::cout << "new entry " << this->entry << std::endl;
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
//	std::cout << index_fragment << std::endl;
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
	int ret = 0;
	int old_entry = this->entry;
	Block * root_block = this->get_block(this->entry);
	Node * root = new Node(root_block, this->key_type);
	ret = this->insert_key(root, key, position);
	root->write_back_to_block(this->get_block(old_entry), this->key_type);
	delete root;
	return ret;
}

int BPlusTree::insert_key(Node * node, DMType & key, int position)
{
	int ret = 0;
//	std::cout << "insert_record " << key << std::endl;
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
		ret = this->insert_key(child, key, position);
		child->write_back_to_block(this->get_block(child_block_number), this->key_type);
		delete child;
	}
	if (node->is_full(this->degree)) {
//		std::cout << "split" << std::endl;
		this->fix_insert(node);
	}
	return ret;
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
		Node *new_root = new Node(false);
		new_root->pointer.insert(new_root->pointer.begin(), old_entry);
		node->parent = new_root;
		node->index = 0;
		change_root = true;
	}

	int new_block_number = this->allocate_block();
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
//		std::cout << "root" << std::endl;
//		for (auto & it : node->parent->key) {
//			std::cout << "\t" << it;
//		}
//		std::cout << std::endl;
//		std::cout << "left" << std::endl;
//		for (auto & it : node->key) {
//			std::cout << "\t" << it;
//		}
//		std::cout << std::endl;
//		std::cout << "right" << std::endl;
//		for (auto & it : new_node->key) {
//			std::cout << "\t" << it;
//		}
//		std::cout << std::endl;
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

	new_node->write_back_to_block(this->get_block(new_block_number), this->key_type);
	delete new_node;

	if (change_root) {
		node->parent->write_back_to_block(this->get_block(this->entry), this->key_type);
		delete node->parent;
	}

}

int BPlusTree::search_key(DMType & key)
{
	int ret = 0;
	Block * root_block = this->get_block(this->entry);
	Node * root = new Node(root_block, this->key_type);
	ret = this->search_key(root, key);
	delete root;
	return ret;
}

int BPlusTree::search_key(Node * node, DMType & key)
{
	int ret = 0;
	int index = 0;
	for (auto & it : node->key) {
		if (key >= it) {
			index ++;
		}
	}

	if (node->leaf) {
		if (index && node->key[index - 1] == key) {
			ret = node->pointer[index - 1];
		}
	} else {
		int child_block_number = node->pointer[index];
		Block * child_block = this->get_block(child_block_number);
		Node * child = new Node(child_block, this->key_type, node, index);
		ret = this->search_key(child, key);
		delete child;
	}
	return ret;
}

int BPlusTree::delete_key(DMType & key)
{
	int ret = 0;
	int old_entry = this->entry;
	Block * root_block = this->get_block(old_entry);
	Node * root = new Node(root_block, this->key_type);
	ret = this->delete_key(root, key);
	if (this->entry != old_entry) {
		this->m_catalog->add_index_fragment(this->table_name, old_entry);
	}
	root->write_back_to_block(this->get_block(old_entry), this->key_type);
	delete root;
	return ret;
}

int BPlusTree::delete_key(Node * node, DMType & key)
{
	int ret = 0;
	int index = 0;
	for (auto & it : node->key) {
		if (key >= it) {
			index ++;
		}
	}

	if (node->leaf) {
		if (node->key.size() && node->key[index-1] == key) {
			ret = node->pointer[index - 1];
			node->key.erase(node->key.begin() + index - 1);
			node->pointer.erase(node->pointer.begin() + index - 1);
		}
		std::cout << node->key.size() << std::endl;
	} else {
		int child_block_number = node->pointer[index];
		Block * child_block = this->get_block(child_block_number);
		Node * child = new Node(child_block, this->key_type, node, index);
		ret = this->delete_key(child, key);
		child->write_back_to_block(this->get_block(child_block_number), this->key_type);
		delete child;
	}
	if (!(!node->parent && node->leaf) && node->is_half(this->degree)) {
//		std::cout << "fix delete" << std::endl;
		this->fix_delete(node);
//		std::cout << "fix delete done" << std::endl;
	}
	return ret;
}

void BPlusTree::fix_delete(Node * node)
{
	if (!node->parent) {
		this->entry = node->pointer[0];
		node->drop();
		return;
	}
//	std::cout << "not root" << std::endl;
	bool right = node->index == 0;
	int sibling_index;
	if (right) {
		sibling_index = node->index + 1;
	} else {
		sibling_index = node->index - 1;
	}
//	std::cout << right << std::endl;

	int sibling_block_number = node->parent->pointer[sibling_index];
	Block * sibling_block = this->get_block(sibling_block_number);
	Node * sibling = new Node(sibling_block, this->key_type, node->parent, sibling_index);
	if (node->leaf) {
		if (sibling->is_enough(this->degree)) {
			if (right) {
				node->key.push_back(sibling->key[0]);
				node->pointer.insert(node->pointer.end() - 1, sibling->pointer[0]);
				node->parent->key[node->index] = sibling->key[1];
				sibling->key.erase(sibling->key.begin());
				sibling->pointer.erase(sibling->pointer.begin());
			} else {
				int end = sibling->key.size();
				node->key.insert(node->key.begin(), sibling->key[end-1]);
				node->pointer.insert(node->pointer.begin(), sibling->pointer[end-1]);
				node->parent->key[node->index - 1] = sibling->key[end-1];
				sibling->key.erase(sibling->key.end() - 1);
				sibling->pointer.erase(sibling->pointer.end() - 2);
			}
		} else {
			if (right){
				node->pointer.erase(node->pointer.end() - 1);
				for (auto & it : sibling->key) {
					node->key.push_back(it);
				}
				for (auto & it : sibling->pointer) {
					node->pointer.push_back(it);
				}
				node->parent->key.erase(node->parent->key.begin() + node->index);
				node->parent->pointer.erase(node->parent->pointer.begin() + node->index + 1);
			} else {
				sibling->pointer.erase(sibling->pointer.end() - 1);
				int i = 0;
				for (auto & it : sibling->key) {
					node->key.insert(node->key.begin() + i, it);
					i ++;
				}
				i = 0;
				for (auto & it : sibling->pointer) {
					node->pointer.insert(node->pointer.begin() + i, it);
					i ++;
				}
				node->parent->key.erase(node->parent->key.begin() + node->index - 1);
				node->parent->pointer.erase(node->parent->pointer.begin() + node->index - 1);
			}
			sibling->drop();
			this->m_catalog->add_index_fragment(this->table_name, sibling_block_number);
		}
	} else {
		if (sibling->is_enough(this->degree)) {
			if (right) {
				node->key.push_back(node->parent->key[node->index]);
				node->pointer.push_back(sibling->pointer[0]);
				node->parent->key[node->index] = sibling->key[0];
				sibling->key.erase(sibling->key.begin());
				sibling->pointer.erase(sibling->pointer.begin());
			} else {
				node->key.insert(node->key.begin(), node->parent->key[node->index - 1]);
				node->pointer.insert(node->pointer.begin(), sibling->pointer[sibling->pointer.size()-1]);
				node->parent->key[node->index - 1] = sibling->key[sibling->key.size()-1];
				sibling->key.erase(sibling->key.end() - 1);
				sibling->pointer.erase(sibling->pointer.end() - 1);
			}
		} else {
			if (right) {
				node->key.push_back(node->parent->key[node->index]);
				for (auto & it : sibling->key) {
					node->key.push_back(it);
				}
				for (auto & it : sibling->pointer) {
					node->pointer.push_back(it);
				}
				node->parent->key.erase(node->parent->key.begin() + node->index);
				node->parent->pointer.erase(node->parent->pointer.begin() + node->index + 1);
			} else {
				sibling->key.push_back(node->parent->key[node->index - 1]);
				int size = sibling->key.size();
				for (int i = 0; i < size; ++i) {
					node->key.insert(node->key.begin() + i, sibling->key[i]);
					node->pointer.insert(node->pointer.begin() + i, sibling->pointer[i]);
				}
				node->parent->key.erase(node->parent->key.begin() + node->index - 1);
				node->parent->pointer.erase(node->parent->pointer.begin() + node->index - 1);
			}
			sibling->drop();
			this->m_catalog->add_index_fragment(this->table_name, sibling_block_number);
		}
	}
	sibling->write_back_to_block(this->get_block(sibling_block_number), this->key_type);
	delete sibling;
}

void BPlusTree::drop()
{
	Block * root_block = this->get_block(this->entry);
	Node * root = new Node(root_block, this->key_type);
	this->drop(root);
	this->m_catalog->add_index_fragment(this->table_name, this->entry);
	root->write_back_to_block(this->get_block(this->entry), this->key_type);
	delete root;
}

void BPlusTree::drop(Node * node)
{
	if (node->leaf) {
		node->drop();
	} else {
		for (auto & it : node->pointer) {
			Block * child_block = this->get_block(it);
			Node * child = new Node(child_block, this->key_type);
			this->drop(child);
			this->m_catalog->add_index_fragment(this->table_name, it);
			child->write_back_to_block(this->get_block(it), this->key_type);
			delete child;
		}
	}
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

	BPlusTree * tree = new BPlusTree(this->m_catalog, this->m_buffer, table_name, key_type);
//	std::cout << "create a tree" << std::endl;
	Record * tuple = new Record(attribute_list);
	for (int i = 1; i <= block_number; ++i) {
		Block * block = this->m_buffer->get_block(table_name, i);
		int begin = Block::BLOCK_HEAD_SIZE;
		int end = *(int*)block->get_data(0);
		int record_number = (end - begin) / record_length;
		for (int j = 0; j < record_number; ++j) {
			tuple->get_value(block->get_data(begin));
			if (tuple->is_valid()) {
				DMType data = (*tuple)[key_name];
//				std::cout << "insert " << data << std::endl;
				tree->insert_key(data, i);
			}
			begin += record_length;
		}
	}
	this->m_catalog->create_index(table_name, key_name, BPLUSTREE, tree->entry);
	delete tree;
}

void Index_Manager::drop_index(const std::string & table_name, const std::string & key_name)
{
	AttrInfo & attribute_list = this->m_catalog->get_attributes(table_name);
	IndexInfo & indices = this->m_catalog->get_index(table_name);
	BPlusTree tree(this->m_catalog, this->m_buffer, table_name, indices[key_name].second, attribute_list[key_name].first);
	tree.drop();
	this->m_catalog->drop_index(table_name, key_name);
}

void Index_Manager::insert_key(const std::string &table_name, std::map<std::string, DMType> &keys, int block_number)
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

int Index_Manager::search_key(const std::string &table_name, const std::string &key_name, DMType & key)
{
	int ret = 0;
	AttrInfo & attribute_list = this->m_catalog->get_attributes(table_name);
	IndexInfo & indices = this->m_catalog->get_index(table_name);
	BPlusTree tree(this->m_catalog, this->m_buffer, table_name, indices[key_name].second, attribute_list[key_name].first);
	ret = tree.search_key(key);
	return ret;
}

int Index_Manager::delete_key(const std::string &table_name, const std::string &key_name, DMType & key)
{
	int ret = 0;
	AttrInfo & attribute_list = this->m_catalog->get_attributes(table_name);
	IndexInfo & indices = this->m_catalog->get_index(table_name);
	BPlusTree tree(this->m_catalog, this->m_buffer, table_name, indices[key_name].second, attribute_list[key_name].first);
	ret = tree.delete_key(key);
	this->m_catalog->update_index_entry(table_name, key_name, tree.entry);
	return ret;
}

void Index_Manager::delete_key(const std::string &table_name, const std::string &key_name, std::vector<DMType> & key)
{
	AttrInfo & attribute_list = this->m_catalog->get_attributes(table_name);
	IndexInfo & indices = this->m_catalog->get_index(table_name);
	BPlusTree tree(this->m_catalog, this->m_buffer, table_name, indices[key_name].second, attribute_list[key_name].first);
	for (auto & it : key) {
//		std::cout << "deleting " << it << std::endl;
		tree.delete_key(it);
//		std::cout << "delete " << it << " done." << std::endl;
	}
	this->m_catalog->update_index_entry(table_name, key_name, tree.entry);
}