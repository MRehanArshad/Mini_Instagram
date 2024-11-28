#pragma once
#include<string>

class message {
public:
	std::string msg;
	std::string name;
	message* next;
	message(std::string m, std::string nam) : name(nam), msg(m), next(NULL) {};
};

class MessageStack {
	message* top;

public:
	MessageStack();
	std::string Top(std::string&);
	std::string pop(std::string&);
	void push(std::string nam, std::string msg);
	bool isEmpty();
	bool display();
};