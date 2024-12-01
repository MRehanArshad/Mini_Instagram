#include "Messages.h"
#include<iostream>
using namespace std;

MessageStack::MessageStack() {
	top = NULL;
}

string MessageStack::Top(string& sender) {
	sender = top->name;
	return (top)? top->msg: "";
}

string MessageStack::pop(string& sender){
	if (!top)
		return "";
	string msg = top->msg;
	sender = top->name;
	message* temp = top;
	top = top->next;
	delete temp;
	return msg;
}

//First sender then message itself
void MessageStack::push(std::string nam, std::string msg) {
	message* temp = new message(nam, msg);
	temp->next = top;
	top = temp;
}

bool MessageStack::isEmpty() {
	return top == NULL;
}

bool MessageStack::display() {
	MessageStack stck2;
	while (!isEmpty())
	{
		string name = top->name;
		cout << "\n\t\t\tMessage : " << name << "\n";
		cout << "\t\t\tSender : " << Top(name) << "\n";
		stck2.push(name, Top(name));
		pop(name);
	}

	while (!stck2.isEmpty())
	{
		string name;
		stck2.Top(name);
		push(name, stck2.Top(name));
		pop(name);
		stck2.pop(name);
	}
	return true;
}

void MessageStack::copyStack(MessageStack obj) {
	while (!obj.isEmpty()){
		string name;
		obj.Top(name);
		this->push(name, obj.pop(name));
	}
}