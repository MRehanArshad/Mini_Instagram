#include"Posts.h"
using namespace std;

Post::Post(string post) {
	this->postDetail = post;
	this->next = nullptr;
}

PostStack::PostStack() {
	Top = nullptr;
}

bool PostStack::empty() {
	return Top == nullptr;
}

void PostStack::push(string post) {
	if (empty()) {
		Top = new Post(post);
		return;
	}
	Post* newNode = new Post(post);
	newNode->next = Top;
	Top = newNode;
}

string PostStack::top() {
	return Top->postDetail;
}
void PostStack::pop() {
	if (empty())
		return;
	Post* newNode = Top;
	Top = Top->next;
	delete newNode;
	newNode = nullptr;
}