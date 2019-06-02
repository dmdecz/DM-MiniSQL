//
// Created by Zhuo Chen on 2019-06-01.
//

#ifndef DM_INDEX_MANAGER_HPP
#define DM_INDEX_MANAGER_HPP

#include "../common/common.hpp"
#include "../catalog_manager/catalog_manager.hpp"
#include "../buffer_manager/buffer_manager.hpp"

typedef enum {ROOT, NONLEAF, LEAF, ROOTLEAF} NodeType;

class Node
{
private:
	static int NODE_HEAD_SIZE;

//	int block_number;

	NodeType type;
	std::vector<DMType> key;
	std::vector<int> pointer;
	friend class BPlusTree;
public:
	Node(NodeType type);
	Node(Block * block, AttrType key_type);
	void load(Block * block, AttrType key_type);
	bool is_valid(int degree);
	bool is_full(int degree);
	bool is_half(int degree);
	void write_back_to_block(Block * block, AttrType key_type);
//	int insert_key(DMType key, int position_or_pointer_1, int position_or_pointer_2);
	int insert_key(DMType key, int position);
	int delete_key(DMType key);
	int search_key(DMType key);
};

class BPlusTree
{
private:
	Buffer_Manager * m_buffer;
	const std::string & table_name;
	int entry;

	AttrType key_type;
	int degree;

	int allocate_block();
	Block * get_block(int block_number);
	int insert_key(Node * node, DMType key, int position);
	int search_key(Node * node, DMType key);
	int delete_key(Node * node, DMType key);
public:
	BPlusTree(Buffer_Manager * buffer_manager, const std::string & table_name, int entry, AttrType key_type);

	int insert_key(DMType key, int position);
	int search_key(DMType key);
	int delete_key(DMType key);
	bool is_empty();
};

class Index_Manager
{
private:
	const std::string & database_name;
	Catalog_Manager * m_catalog;
	Buffer_Manager * m_buffer;
public:
	Index_Manager(const std::string & database_name, Catalog_Manager * catalog_manager, Buffer_Manager * buffer_manager);
	~Index_Manager();

	void create_index(const std::string & table_name, const std::string & key_name);
};

#endif //DM_INDEX_MANAGER_HPP
