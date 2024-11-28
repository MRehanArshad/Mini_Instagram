#include "Friend.h"
#include<iostream>

Friend_Node::Friend_Node(std::string n, std::string s) {
	next = nullptr;
	name = n;
	status = s;
}

Friend::Friend() {
	matrix = NULL;
}

bool Friend::addFriend(std::string name, std::string status) {
	Friend_Node* temp = new Friend_Node(name, status);
	if (matrix != NULL)
		temp->next = matrix;
	matrix = temp;
	return 1;
}

bool Friend::deleteFriend(std::string n) {
	if (!matrix)
		return false;

	Friend_Node* cur = matrix;
	Friend_Node* prev = NULL;

	if (cur->name == n) {
		matrix = cur->next;
		delete cur;
		return true;
	}

	while (cur) {
		if (cur->name == n) {
			prev->next = cur->next;
			delete cur;
			return true;
		}
		prev = cur;
		cur = cur->next;
	}

	return false;
}

void Friend::displayFriends() {
	if (!matrix)
		std::cout << "No Friends!\n";
	else {
		Friend_Node* cur = matrix;
		for (int i = 1; cur; i++) {
			std::cout << i << ". " << cur->name << "\n";
			std::cout << " " << cur->status << "\n";
		}

	}
}

bool Friend::searchFriend(std::string name) {
	if (!matrix)
		return 0;
	Friend_Node* cur = matrix;
	while (cur) {
		if (cur->name == name)
			return 1;
	}
	return 0;
}

bool Friend::updateFriend(std::string key, std::string name, std::string status) {
	if (!matrix || !searchFriend(name))
		return 0;
	Friend_Node* cur = matrix;
	while (cur)
	{
		if (cur->name == key)
		{
			cur->name = name;
			cur->status = status;
			return 1;
		}
	}
}