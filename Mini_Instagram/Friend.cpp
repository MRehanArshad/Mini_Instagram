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
	system("cls");
	Friend_Node* temp = matrix;
	std::cout << "\n\n\t\t\t\t     Friends ";
	std::cout << "\n\t\t ================================================" << std::endl;
	if (!temp) {
		std::cout << "\n\t\t\t" << "There is no Friend" << std::endl;
	}
	while (temp) {
		if (temp->status == "Friend")
			std::cout << "\n\t\t\t" << temp->name << std::endl;
		temp = temp->next;
	}
	std::cout << "\n\n\t\t ================================================" << std::endl;
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

void Friend::requestedFriends() {
	system("cls");
	Friend_Node* temp = matrix;
	std::cout << "\n\n\t\t\t\t     Requests ";
	std::cout << "\n\t\t ================================================" << std::endl;
	if (!temp) {
		std::cout << "\n\t\t\t" << "There is no Request" << std::endl;
	}
	while (temp) {
		if (temp->status == "Requested")
			std::cout << "\n\t\t\t" << temp->name << std::endl;
		temp = temp->next;
	}
	std::cout << "\n\n\t\t ================================================" << std::endl;
}

void Friend::AcceptAllRequest() {
	Friend_Node* temp = matrix;
	while (temp) {
		if (temp->status == "Requested")
			temp->status = "Friend";
		temp = temp->next;
	}
}

void Friend::AcceptRequest(std::string username) {
	Friend_Node* temp = matrix;
	while (temp) {
		if (temp->name == username && temp->status == "Requested")
			temp->status = "Friend";
		temp = temp->next;
	}
}

void Friend::displayBlockFriends() {
	system("cls");
	Friend_Node* temp = matrix;
	std::cout << "\n\n\t\t\t\t     Blocked ";
	std::cout << "\n\t\t ================================================" << std::endl;
	if (!temp) {
		std::cout << "\n\t\t\t" << "There is no Blocked Friend" << std::endl;
	}
	while (temp) {
		if (temp->status == "Blocked")
			std::cout << "\n\t\t\t" << temp->name << std::endl;
		temp = temp->next;
	}
	std::cout << "\n\n\t\t ================================================" << std::endl;
}

bool Friend::isEmpty()
{
	return this->matrix;
}

Friend_Node* Friend::getList()
{
	return matrix;
}