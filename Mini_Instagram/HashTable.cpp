#include"HashTable.h"
using namespace std;

Node::Node(string username, string password) :username(username), password(password), next(nullptr) {};

LinkList::LinkList() {
	root = end = nullptr;
}

void LinkList::Insert(string username, string password) {
	if (root == nullptr) {
		root = end = new Node(username, password);
		return;
	}
	end->next = new Node(username, password);
	end = end->next;
}

bool LinkList::Search(string username, string& password) {
	if (root == nullptr) return false;
	Node* temp = root;
	while (temp) {
		if (temp->username == username) {
			password = temp->password;
			return true;
		}
		temp = temp->next;
	}
	return false;
}

HashMap::HashMap(int size) {
	hash_array = new LinkList[size];
	this->size = size;
	this->length = 0;
}

int HashMap::hash(string username) {
	int val = 0;
	for (char c : username) {
		val += static_cast<int>(c);
	}
	return (val % size);
}

void HashMap::Insert(string username, string password) {
	int location = hash(username);
	hash_array[location].Insert(username, password);
}

string HashMap::Retrive(string username) {
	string password;
	int location = hash(username);
	if (hash_array[location].Search(username, password)) {
		return password;
	}
	return "";
}