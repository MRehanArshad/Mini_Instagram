#pragma once
#include<string>

class Node {
public:
	std::string username;
	std::string password;
	Node* next;
	Node(std::string username, std::string password);
};

class LinkList {
	Node* root;
	Node* end;
public:
	LinkList();
	void Insert(std::string username, std::string password);
	bool Search(std::string username, std::string& password);
};

class HashMap {
	LinkList* hash_array;
	int size;
	int length;
public:
	HashMap(int size);
	int hash(std::string username);
	void Insert(std::string username, std::string password);
	std::string Retrive(std::string username);
};