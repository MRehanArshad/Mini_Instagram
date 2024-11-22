#include "Messages.h"
using namespace std;

MessageStack::MessageStack() {
	top = NULL;
}

string MessageStack::Top() {
		return (top)? top->msg: "";
}

string MessageStack::pop(){
	if (!top)
		return "";
	string msg = top->msg;
	message* temp = top;
	top = top->next;
	delete temp;
	return msg;
}

void MessageStack::push(std::string str)
{
	message* temp = new message(str);
	temp->next = top;
	top = temp;
}

bool MessageStack::isEmpty() {
	return top == NULL;
}