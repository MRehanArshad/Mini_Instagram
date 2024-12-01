#pragma once
#include<string>

class Friend_Node
{
public:
	std::string name;
	std::string status;
	Friend_Node* next;
	Friend_Node(std::string n, std::string s);
};

class Friend
{
private:
	Friend_Node* matrix;

public:
	Friend();

	bool addFriend(std::string name, std::string status);

	bool deleteFriend(std::string n);

	void displayFriends();

	bool searchFriend(std::string name);

	bool updateFriend(std::string, std::string, std::string);

	void requestedFriends();

	void AcceptAllRequest();

	void AcceptRequest(std::string);

	void displayBlockFriends();

	bool isEmpty();

	Friend_Node* getList();
};