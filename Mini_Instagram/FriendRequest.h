#pragma once
#include<string>

class Request {
public:
	Request* next;
	std::string name;
	Request(std::string name) {
		this->name = name;
		next = NULL;
	}
};

class FriendRequest {
private:
	Request* front, * rear;
public:
	FriendRequest();
	void enQueue(std::string name);
	std::string deQueue();
	bool isEmpty();
	std::string Front();
	std::string Rear();
};