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

	bool valid;
	bool leaf;
	Node * parent;
	int index;
	std::vector<DMType> key;
	std::vector<int> pointer;
	friend class BPlusTree;
public:
	Node(bool leaf, Node * parent = nullptr, int index = 0);
	Node(Block * block, AttrType key_type, Node * parent = nullptr, int index = 0);
	void load(Block * block, AttrType key_type);
	void write_back_to_block(Block * block, AttrType key_type);

	bool is_full(int degree);
	bool is_half(int degree);
	bool is_enough(int degree);

	void drop();
//	int insert_key(DMType key, int position_or_pointer_1, int position_or_pointer_2);
//	int insert_key(DMType key, int position);
//	int delete_key(DMType key);
//	int search_key(DMType key);
};

class BPlusTree
{
private:
	Catalog_Manager * m_catalog;
	Buffer_Manager * m_buffer;
	const std::string & table_name;
	int entry;

	AttrType key_type;
	int degree;

	int allocate_block();
	Block * get_block(int block_number);

	void fix_insert(Node * node);
	void fix_delete(Node * node);
	int insert_key(Node * node, DMType & key, int position);
	int search_key(Node * node, DMType & key);
	int delete_key(Node * node, DMType & key);

	void drop(Node * node);

	friend class Index_Manager;
public:
	BPlusTree(Catalog_Manager * catalog_manager, Buffer_Manager * buffer_manager, const std::string & table_name, AttrType key_type);
	BPlusTree(Catalog_Manager * catalog_manager, Buffer_Manager * buffer_manager, const std::string & table_name, int entry, AttrType key_type);

	int insert_key(DMType & key, int position);
	int search_key(DMType & key);
	int delete_key(DMType & key);

	void drop();
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
	void drop_index(const std::string & table_name, const std::string & key_name);

	void insert_key(const std::string &table_name, std::map<std::string, DMType> &keys, int block_number);
	int search_key(const std::string &table_name, const std::string &key_name, DMType & key);
	int delete_key(const std::string &table_name, const std::string &key_name, DMType & key);
	void delete_key(const std::string &table_name, const std::string &key_name, std::vector<DMType> & key);
};

#endif //DM_INDEX_MANAGER_HPP
