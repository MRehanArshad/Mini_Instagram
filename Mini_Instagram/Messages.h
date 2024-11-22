#pragma once
#include<string>

class message {
public:
	std::string msg;
	message* next;
	message(std::string m) : msg(m), next(NULL) {};
};

class MessageStack {
	message* top;

public:
	MessageStack();
	std::string Top();
	std::string pop();
	void push(std::string str);
	bool isEmpty();

};