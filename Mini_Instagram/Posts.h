#pragma once
#include"string"
class Post {
public:
	std::string postDetail;
	Post* next;
	Post(std::string);
};

class PostStack {
	Post* Top;
public:
	PostStack();
	void push(std::string);
	std::string top();
	void pop();
	bool empty();
};
